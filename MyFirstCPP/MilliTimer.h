#pragma once

#include <chrono>

using namespace std::chrono;

class MilliTimer
{
private:
	long epoch;

	long getEpoch();
public:
	MilliTimer();

	bool hasTimeElapsed(long offset);
	void resetTimer();
	long getTimeElapsed();
};

