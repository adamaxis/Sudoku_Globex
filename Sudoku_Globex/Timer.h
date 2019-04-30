#ifndef _TIMER_H
#define _TIMER_H
#include <time.h>
#include <string>
using namespace std;

class Timer {
	clock_t startTime,  endTime;
	public:
	bool running;
	Timer( ) {
		startTime = endTime = 0;
		running = false;
	}

	void start( );
	void stop( );
	void printTime( );
};

#endif