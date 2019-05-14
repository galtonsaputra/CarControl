#include "car_control_connection.h"

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
	if (status == 0) { return 0; }
	else { return -1; }
}

void CarConnection::ClientCloseConnection()
{
	close(activeSocket);
}

BasicSafetyMessage_t* CarConnection::PopulateBSM(int messageType)
{
	TemporaryID_t* tempId = (TemporaryID_t*)calloc(1, sizeof(TemporaryID_t));
	tempId->size = 4;
	tempId->buf = (uint8_t*)calloc(1, 4);

	BasicSafetyMessage_t* bsm;
	bsm = (BasicSafetyMessage_t*)calloc(1, sizeof(BasicSafetyMessage_t));
	bsm->coreData.id = *tempId;
	bsm->coreData.msgCnt = 1;

	switch(messageType)
	{
		case 0:
			//int x = carSpeedReading;
			bsm->coreData.speed = CarConnection::carSpeedReading;
			break;
		case 1:
			bsm->coreData.heading = 100;
			break;
		case 2:
			bsm->coreData.lat = 0;
		case 3:
			bsm->coreData.Long = 0;
	}

	return bsm;
}

//ClientSending and generating BSM message
void CarConnection::SendMessage(BasicSafetyMessage_t *bsm)
{
	char x[1024];
	size_t errLen = sizeof(x);

	if (bsm->coreData.speed == 0) { exit(-1); }
	printf("Current car speed %ld\n", bsm->coreData.speed);

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
		write(activeSocket, rsltMsg.buffer, rsltMsg.result.encoded);
		cout << "BSM Message sent";
	}

	// Free the BSM memory once we've sent the message 
	ASN_STRUCT_FREE(asn_DEF_BasicSafetyMessage, bsm);
	free(rsltMsg.buffer);

}