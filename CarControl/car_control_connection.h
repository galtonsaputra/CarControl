#ifdef car_control_connection_H
#define car_control_connection_H
#endif

#include <cstdio>
#include <thread>
//Wireless
#include <string.h> 
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8888

//J2735
#include "MessageFrame.h"
#include "BasicSafetyMessage.h"
#include "ConcurrentQueue.h"
#include "TemporaryID.h"
#include "constraints.h"



class CarConnection
{
	public:
		//Client Connection
		int status = 0;
		int activeSocket;
		//WiFi operations
		int ClientConnect(const char *serverIp);
		void ClientCloseConnection();


		//J2735 Broadcast
		int carSpeedReading;
		void SendMessage(BasicSafetyMessage_t *bsm);
		BasicSafetyMessage_t* PopulateBSM(int messageType);

		static BasicSafetyMessage_t populatedBSM_Message;
};