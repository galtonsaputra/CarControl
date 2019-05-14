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
	const char *ipAddress = "192.168.43.100";
	int status = connection.ClientConnect(ipAddress);
	if (status == -1) 
	{
		perror("Error:");
		exit(1); 
	}

	std::cout << "Server connected... \n";

	//Car WiringSetup and Control
	if (wiringPiSetup() == -1) { exit(1); }
	else 
	{ 
		car_control_L298::initPins();
	}
	
	while (runningStatus)
	{
		int command;

		std::cout << "Enter command: \n";
		std::cin >> command;

		switch (command)
		{
			case 0: //Stop, Break and exit(0)
				car_control_L298::stopCar();
				connection.ClientCloseConnection();
				runningStatus = false;
				break;
			case 8: //Forward
				car_control_L298::forwardCar();
				car_control_L298::carActive = true;
				SendBSMSpeedMessage();
				break;
			case 5: //Stop
				car_control_L298::stopCar();
				car_control_L298::carActive = false;
				break;
			case 7: //Accelerate
				car_control_L298::accelerate();
				SendBSMSpeedMessage();
				break;
			case 9: //Deccelerate
				car_control_L298::decelerate();
				SendBSMSpeedMessage();
				break;
			case 4: //Left
				if (car_control_L298::carActive == true) 
				{
					car_control_L298::turn_left();
				}
				break;
			case 6: //Right
				if (car_control_L298::carActive == true) 
				{
					car_control_L298::turn_right();
				}
				break;
			case 2: //Reverse
				car_control_L298::carActive = true;
				car_control_L298::reverseCar();
				break;
		}
	}

    return 0;
}

