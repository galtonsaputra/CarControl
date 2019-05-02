#ifdef UTILITIES_H
#define UTILITIES_H
#endif

#include <math.h>
#include <iomanip> 
#include <iostream> 
#include <stdlib.h> 
#include <unistd.h> 
using namespace std;

class MathFunction
{
	public:
		int seconds = 0;
		int minutes = 0;
		int hours = 0;

		void CountOneMinute()
		{
			while (true)
			{
				delay(5);
				sleep(1);
				seconds++;
				if (seconds == 5)
				{
					break;
				}
			}
		}

		void CalculateRPM()
		{
			static int _counter = 0;

		}
};

class TimerOnline
{
	void displayClock()
	{
		// system call to clear the screen 
		system("clear");

		cout << setfill(' ') << setw(55) << "		 TIMER		 \n";
		cout << setfill(' ') << setw(55) << " --------------------------\n";
		cout << setfill(' ') << setw(29);
		cout << "| " << setfill('0') << setw(2) << hours << " hrs | ";
		cout << setfill('0') << setw(2) << minutes << " min | ";
		cout << setfill('0') << setw(2) << seconds << " sec |" << endl;
		cout << setfill(' ') << setw(55) << " --------------------------\n";
	}

public:
	int seconds = 0;
	int hours = 0;
	int minutes = 0;

	void timer()
	{
		while (true)
		{
			// display the timer 
			//displayClock();

			sleep(1);

			seconds++;

			if (seconds == 60)
			{
				minutes++;

				if (minutes == 60) {

					// increment hours 
					hours++;
					minutes = 0;
				}

				seconds = 0;
			}
		}
	}
};
