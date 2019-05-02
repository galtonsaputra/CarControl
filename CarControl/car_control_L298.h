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
	//Motor control
	void forwardCar();
	void stopCar();
	void accelerate();
	void decelerate();
	void reverseCar();
	void reverseTesty();
	//Manouvre
	void turnLeft();
	void turnRight();
	//void stop_start_left();
	//void stop_start_right();
};

class Speed {
	public:
		Speed() = default; //recheck understanding.
		int car_speed_reading;

		//Recheck speed sending intervals.
		//Hall sensor application.
};

