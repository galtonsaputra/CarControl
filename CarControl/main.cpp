#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <wiringPi.h>

#include "car_control_L298.h"
#include "car_control_connection.h"
#include "Utilities.h"

using namespace std;

//TODO: interval of message to send
CarConnection connection;

//Find placement to where this has to go for interval broadcasting.
void SendBSMSpeedMessage()
{
	Speed s;
	connection.carSpeedReading = s.car_speed_reading;
	connection.SendMessage(connection.PopulateBSM(0));
}

int main()
{
    printf("CarController \n");
	bool runningStatus = true;

	//ClientConnect to RSU Server
	//const char *ipAddress = "192.168.1.106";
	//int status = connection.ClientConnect(ipAddress);
	//if (status == -1) { exit(1); }
	//std::cout << "Server connected... \n";

	//Car WiringSetup and Control
	//if (wiringPiSetupSys() == -1) { exit(1); }
	if (wiringPiSetup() == -1) { exit(1); }
	else { car_control_L298::initPins(); }

	TimerOnline TimerOnline;
	MathFunction MathFunction;

	while (runningStatus)
	{
		int command;

		std::cout << "Enter command: \n";
		std::cin >> command;
		//command = 1;
		switch (command)
		{
			case 0: //Stop, Break and exit(0)
				car_control_L298::stopCar();
				runningStatus = false;
				break;
			case 8: //Forward
				car_control_L298::forwardCar();
				break;
			case 5: //Stop
				car_control_L298::stopCar();
				break;
			case 7: //Accelerate
				car_control_L298::accelerate();
				//SendBSMSpeedMessage();
				break;
			case 9: //Deccelerate
				car_control_L298::decelerate();
				//SendBSMSpeedMessage();
				break;
			case 4: //Left
				car_control_L298::turnLeft();
				break;
			case 6: //Right
				car_control_L298::turnRight();
				break;
			case 2: //Reverse
				car_control_L298::reverseCar();
				break;
		}
	}

    return 0;
}

