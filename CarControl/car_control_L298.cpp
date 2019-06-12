#include "car_control_L298.h"

//PIN Configuration
//Input 1 - 4
static int rightBackwardPin = 24;
static int rightForwardPin = 25;
static int leftBackwardPin = 23;
static int leftForwardPin = 22;

//PWM BCM12
static int pmwPin = 26;

//Initial vehicle config
static int speed = 500;
static bool forwardDirection = true;

//Class to populate BSM message
Speed s;

//Set all pins to LOW 
void car_control_L298::setAllPinsLow()
{
	digitalWrite(rightForwardPin, LOW);
	digitalWrite(rightBackwardPin, LOW);
	digitalWrite(leftForwardPin, LOW);
	digitalWrite(leftBackwardPin, LOW);	
}

//Set Pins to OUTPUT and EXPORT BCM13 -> PWM0
void car_control_L298::initPins()
{
	pinMode(leftForwardPin, OUTPUT);
	pinMode(leftBackwardPin, OUTPUT);
	pinMode(rightForwardPin, OUTPUT);
	pinMode(rightBackwardPin, OUTPUT);
	pinMode(pmwPin, PWM_OUTPUT);
	
	perror("Set pinMode status: ");
	setAllPinsLow();
}

//MAIN CAR CONTROL//
void car_control_L298::forwardCar()
{
	forwardDirection = true;

	//Generates a steady square wave of the specified
	//duty cycle. pwmWrite (ALT0) ranges from [0-1024]
	pwmWrite(pmwPin, speed);
	perror("PWM write status: ");
	std::cout << "SPEED: " << speed << "\n";

	//H-bridge current flow control
	//Right motor control
	digitalWrite(rightBackwardPin, HIGH);
	digitalWrite(rightForwardPin, LOW);
	//Left motor control
	digitalWrite(leftBackwardPin, HIGH);
	digitalWrite(leftForwardPin, LOW);
	
	//Populate ASN.Struct.BSM field speed for message transmission
	s.car_speed_reading = speed;
}

void car_control_L298::reverseCar()
{
	setAllPinsLow();
	forwardDirection = false;

	digitalWrite(leftBackwardPin, LOW);
	digitalWrite(leftForwardPin, HIGH);
	digitalWrite(rightBackwardPin, LOW);
	digitalWrite(rightForwardPin, HIGH);
}

void car_control_L298::stopCar()
{
	setAllPinsLow();
	car_control_L298::carActive = false;
}

//MANOEUVRE CONTROLS//
//Acc & Dec increments by +-50.
void car_control_L298::accelerate()
{
	if (speed >= 800)
	{
		speed = 800;
		printf("MAX speed reached of %d \n", speed);
	}

	else
	{
		speed += 100;
		pwmWrite(pmwPin, speed);
		printf("Increasing speed to %d \n", speed);
	}
	
	s.car_speed_reading = speed;
}

void car_control_L298::decelerate() 
{
	if (speed <= 300)
	{
		speed = 300;
		printf("MIN speed reached of %d \n", speed);
	}
	else 
	{
		speed -= 100;
		pwmWrite(pmwPin, speed);
		printf("Recuding speed to %d \n", speed);
	}
	s.car_speed_reading = speed;
}

void car_control_L298::turn_left()
{
	if (forwardDirection)
	{
		_CarManoeuvre::halt_left();
	}

	else
	{
		_CarManoeuvre::halt_right();
	}
}

void car_control_L298::turn_right()
{
	if (forwardDirection)
	{
		_CarManoeuvre::halt_right();
	}

	else
	{
		_CarManoeuvre::halt_left();
	}
}

//In order to manoeuvre, one side of the motor is
//stoped to allow the car to turn. Delay of 1 second
//is needed and minimum to turn.
void _CarManoeuvre::halt_left()
{
	digitalWrite(leftBackwardPin, LOW);
	digitalWrite(leftForwardPin, LOW);
	delayMicroseconds(1000000);

	//Resumes current direction by setting pin back to HIGH
	if (!forwardDirection)
	{
		digitalWrite(leftForwardPin, HIGH);
	}

	else
	{
		digitalWrite(leftBackwardPin, HIGH);
	}
}

void _CarManoeuvre::halt_right()
{
	digitalWrite(rightBackwardPin, LOW);
	digitalWrite(rightForwardPin, LOW);
	delayMicroseconds(1000000);

	//Resumes current direction by setting pin back to HIGH
	if (!forwardDirection)
	{
		digitalWrite(rightForwardPin, HIGH);
	}

	else
	{
		digitalWrite(rightBackwardPin, HIGH);
	}
}
