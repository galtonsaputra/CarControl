#include "car_control_connection.h"
#include "car_control_L298.h"

const char *addrAssigned;
uint8_t convertedIPtoTemporary;

extern asn_TYPE_descriptor_t asn_DEF_OCTET_STRING;
extern Speed s;

CarSpeedConversion verifyCarSpeed;

int CarConnection::ClientConnect(const char *serverIp)
{
	struct sockaddr_in serv_addr;
	const char *ipAddress = serverIp;
		
	int sId = socket(AF_INET, SOCK_STREAM, 0);
	if (sId == -1) return -1;

	activeSocket = sId;

	memset(&serv_addr, '0', sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if (inet_pton(AF_INET, ipAddress, &serv_addr.sin_addr) <= 0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	status = connect(sId, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	struct ifaddrs *ifap, *ifa;
	struct sockaddr_in *sa;

	//Grabs IP assigned from server 
	getifaddrs(&ifap);
	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
		if (ifa->ifa_addr->sa_family == AF_INET) {
			sa = (struct sockaddr_in *) ifa->ifa_addr;
			addrAssigned = inet_ntoa(sa->sin_addr);
			printf("Interface: %s\n Address: %s\n", ifa->ifa_name, addrAssigned);
		}
	}
	
	if (status == 0) { return 0; }
	else { return -1; }
}

void CarConnection::ClientCloseConnection()
{
	close(activeSocket);
}

bool CarSpeedConversion::inRange(unsigned low, unsigned high, unsigned x)
{
	return  ((x - low) <= (high - low));
}

BasicSafetyMessage_t* CarConnection::PopulateBSM(int messageType)
{
	//Creates a new Octet String to parse IP.4 as TempID
	OCTET_STRING_t* t = OCTET_STRING_new_fromBuf(&asn_DEF_OCTET_STRING, 
						addrAssigned, strlen(addrAssigned));

	TemporaryID_t* tempId = t;
	
	BasicSafetyMessage_t* bsm;
	bsm = (BasicSafetyMessage_t*)calloc(1, sizeof(BasicSafetyMessage_t));
	bsm->coreData.id = *tempId;
	bsm->coreData.msgCnt = 1;
	
	//Actor profile switch: T:Bad or F:Good
	bool badActor = true;
	int speedTranslationToCM = 0;

	//Below represnts the table to map PWM speed to tested linear distance in cm/seconds.
	switch(messageType)
	{
		case 0:
			//GEAR 1
			if (verifyCarSpeed.inRange(300, 399, s.car_speed_reading))
			{
				speedTranslationToCM = 14;
			}
			//GEAR 2
			else if (verifyCarSpeed.inRange(400, 499, s.car_speed_reading))
			{
				speedTranslationToCM = 25;
			}
			//GEAR 3
			else if (verifyCarSpeed.inRange(500, 599, s.car_speed_reading))
			{
				if (badActor) 
				{
					speedTranslationToCM = 30;
				}
				else 
				{
					//speedTranslationToCM = 62.04;//A
					speedTranslationToCM = 53;//B
				}
			}
			//GEAR 4
			else if (verifyCarSpeed.inRange(600, 699, s.car_speed_reading))
			{
				if(badActor)
				{
					speedTranslationToCM = 40;
				}
				else 
				{
					speedTranslationToCM = 55;
				}
			}

			bsm->coreData.speed = speedTranslationToCM;
			break;
		case 1:
			bsm->coreData.heading = 100;
			break;
		case 2: //GPS Coordinates of UQ
			bsm->coreData.lat = 27.4975; 
		case 3:
			bsm->coreData.Long = 153.0137;
	}

	return bsm;
}

//ClientSending and generating BSM message
void CarConnection::SendMessage(BasicSafetyMessage_t *bsm)
{
	char x[1024];
	size_t errLen = sizeof(x);

	printf("DEBUG:: TOBE broadcasted converted speed %ld cm/s \n", bsm->coreData.speed);

	// Construct the actual BasicSafetyMessage message frame.
	MessageFrame_t msgFrame;
	msgFrame.messageId = 20;
	msgFrame.value.present = MessageFrame__value_PR::MessageFrame__value_PR_BasicSafetyMessage;
	msgFrame.value.choice.BasicSafetyMessage = *bsm;

	int ret = asn_check_constraints(&asn_DEF_MessageFrame, &msgFrame, x, &errLen);
	if (ret) { fprintf(stderr, "Constraint failed %s\n", x); }

	// Encode the message for transmission
	asn_encode_to_new_buffer_result_t rsltMsg = asn_encode_to_new_buffer(0, ATS_DER, &asn_DEF_MessageFrame, &msgFrame);

	if (rsltMsg.buffer) 
	{
		//write broken pipe handler
		if (write(activeSocket, rsltMsg.buffer, rsltMsg.result.encoded) == -1)
		{
			exit(1);
			perror("PipeWriteToServer:");
		}
	}

	// Free the BSM memory once we've sent the message 
	ASN_STRUCT_FREE(asn_DEF_BasicSafetyMessage, bsm);
	free(rsltMsg.buffer);
}