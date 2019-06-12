#ifdef UTILITIES_H
#define UTILITIES_H
#endif

#include <sstream>
#include <wiringPi.h>


namespace hall_sensor
{
	static bool HSActive;
	void HallSensorStartRead();
	void HallSensorInitPins();
	void LedBlink(char* ledstate);
};

