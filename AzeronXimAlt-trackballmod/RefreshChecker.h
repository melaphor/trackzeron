// RefreshChecker.h

#ifndef _REFRESHCHECKER_h
#define _REFRESHCHECKER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class RefreshChecker
{
public:
	RefreshChecker(int size);
	int PassNew(int id, int value);
	bool HasNewData();

private:
	int* previousValues;
	bool _hasNewData = false;
};

#endif
