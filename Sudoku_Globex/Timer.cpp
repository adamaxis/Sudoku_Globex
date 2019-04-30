#include <iostream>
#include "Timer.h"


void Timer::printTime( ) {
	if(running) {
		endTime = clock( );
		cout << ((endTime - startTime) / (double) CLOCKS_PER_SEC);
	} else cout << ((startTime - endTime) / (double) CLOCKS_PER_SEC);
}

void Timer::start( ) {
	running = true;
	startTime = clock( );
}

void Timer::stop( ) {
	running = false;
}