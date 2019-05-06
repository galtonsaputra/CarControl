#ifndef	car_control_L298_H
#define	car_control_L298_H
#endif

#include<stdio.h>
#include <stdbool.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <bits/stdc++.h> 

using namespace std;

namespace car_control_L298 
{
	//Initialization
	void initPins();
	void setAllPinsLow();
	static bool carActive;

	//Motor control
	void forwardCar();
	void stopCar();
	void accelerate();
	void decelerate();
	void reverseCar();

	//Manoeuvre
	void turn_left();
	void turn_right();
};

namespace _CarManoeuvre
{
	void halt_left();
	void halt_right();
}

class Speed {
	public:
		Speed() = default; //recheck understanding.
		int car_speed_reading;

};

