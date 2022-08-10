#include "MilliTimer.h"

long MilliTimer::getEpoch()
{
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

MilliTimer::MilliTimer()
{
	this->resetTimer();
}

bool MilliTimer::hasTimeElapsed(long offset)
{
	return this->getTimeElapsed() > offset;
}

void MilliTimer::resetTimer()
{
	epoch = this->getEpoch();
}

long MilliTimer::getTimeElapsed()
{
	return this->getEpoch() - this->epoch;
}