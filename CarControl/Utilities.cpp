#include "Utilities.h"

//Hall Sensor Initialization
static int SensorPin = 21;
static int LedOutput = 27;

//LED blink to count for 1 rotation
void hall_sensor::LedBlink(char* ledstate)
{
	pinMode(LedOutput, OUTPUT);

	if (ledstate == "OUTPUT")
	{
		digitalWrite(LedOutput, HIGH);
	}
	else if (ledstate == "INPUT")
	{
		digitalWrite(LedOutput, LOW);
	}
	else
	{
		printf("Error Led Output");
	}
}

void hall_sensor::HallSensorInitPins()
{
	pinMode(SensorPin, INPUT);
	LedBlink("INPUT");
}

void hall_sensor::HallSensorStartRead()
{
	HSActive = true;
	static int x = 0;
	while (HSActive)
	{
		if (0 == digitalRead(SensorPin))
		{
			if (0 == digitalRead(SensorPin)) {
				LedBlink("OUTPUT");
				delay(180);
				printf("Counter: %d \n", x);
			}

		}
		else if (1 == digitalRead(SensorPin))
		{
			delay(10);
			if (1 == digitalRead(SensorPin)) {
				while (!digitalRead(SensorPin));
				LedBlink("INPUT");
			}
		}
	}
}