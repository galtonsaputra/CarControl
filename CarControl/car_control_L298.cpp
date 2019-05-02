#include "car_control_L298.h"

//PIN Configuration
static int rightForwardPin = 25;
static int rightBackwardPin = 24;
static int leftForwardPin = 29;
static int leftBackwardPin = 28;

//PWM BCM12 - remember to set out (uncomment system())
static int pmwPin = 1;

//Motor rotation speed
static int speed = 400;
static bool forwardDirection = true;

void car_control_L298::setAllPinsLow()
{
	digitalWrite(rightForwardPin, LOW);
	digitalWrite(rightBackwardPin, LOW);
	digitalWrite(leftForwardPin, LOW);
	digitalWrite(leftBackwardPin, LOW);	
}

//Sets Pins to OUTPUT and EXPORT PIN1 -> PWM
void car_control_L298::initPins()
{
	pinMode(leftForwardPin, OUTPUT);
	pinMode(leftBackwardPin, OUTPUT);
	pinMode(rightForwardPin, OUTPUT);
	pinMode(rightBackwardPin, OUTPUT);
	pinMode(pmwPin, PWM_OUTPUT);

	//string setPWMCommand = "gpio mode 1 pwm";
	//const char *pwmCommand = str5.c_str();
	//std::system(pwmCommand);
	
	perror("Set pinMode status: ");
	pwmWrite(pmwPin, speed);
	setAllPinsLow();
}

Speed s;
void car_control_L298::forwardCar()
{
	pwmWrite(pmwPin, speed);
	perror("PWM write status: ");
	std::cout << "SPEED: " << speed << "\n";

	digitalWrite(rightBackwardPin, HIGH);
	digitalWrite(rightForwardPin, LOW);
	digitalWrite(leftBackwardPin, HIGH);
	digitalWrite(leftForwardPin, LOW);
	
	s.car_speed_reading = speed;
}

void car_control_L298::stopCar()
{
	setAllPinsLow();
}

//Acc & Dec increments by +-50
void car_control_L298::accelerate()
{
	if (speed >= 950)
	{
		speed = 950;
		printf("MAX speed reached of %d \n", speed);
	}

	else
	{
		speed += 50;
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
		printf("MIN speed reached of %d", speed);
	}
	else 
	{
		speed -= 50;
		pwmWrite(pmwPin, speed);
		printf("Recuding speed to %d \n", speed);
	}
	s.car_speed_reading = speed;
}

//Car Reverse - behaving good, maybe cause no pwm?
void car_control_L298::reverseCar()
{
	setAllPinsLow();
	forwardDirection = false;
	digitalWrite(leftBackwardPin, LOW);
	digitalWrite(leftForwardPin, HIGH);
	digitalWrite(rightBackwardPin, LOW);
	digitalWrite(rightForwardPin, HIGH);
}

void car_control_L298::reverseTesty()
{
	setAllPinsLow();
	forwardDirection = true;
	pwmWrite(pmwPin, 500);
	perror("PWM write status: ");
	std::cout << "SPEED: " << speed << "\n";

	digitalWrite(leftBackwardPin, HIGH);
	digitalWrite(leftForwardPin, LOW);
	digitalWrite(rightBackwardPin, HIGH);
	digitalWrite(rightForwardPin, LOW);
}

//Car manouvre: LEFT & RIGHT BUGGY
//After turning left, it stops. Reverse is smoother.
void car_control_L298::turnLeft()
{
	cout << "Turning RIGHT \n";

	digitalWrite(leftBackwardPin, LOW);
	digitalWrite(leftForwardPin, LOW);
	delayMicroseconds(1000000);

	if (!forwardDirection)
	{
		digitalWrite(leftForwardPin, HIGH);
	}

	else
	{
		digitalWrite(leftBackwardPin, HIGH);

	}
}

void car_control_L298::turnRight()
{
	cout << "Turning LEFT \n";
	digitalWrite(rightBackwardPin, LOW);
	digitalWrite(rightForwardPin, LOW);
	delayMicroseconds(1000000);

	if (!forwardDirection)
	{
		digitalWrite(rightForwardPin, HIGH);
	}

	else
	{
		digitalWrite(rightBackwardPin, HIGH);

	}
}
