#include "Time.h"

Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}

int Time::getHour()
{
	return hour;
}

int Time::getMinute()
{
	return minute;
}

int Time::getSecond()
{
	return second;
}

void Time::setHour(int val)
{
	hour = val;
}

void Time::setMinute(int val)
{
	minute = val;
}

void Time::setSecond(int val)
{
	second = val;
}
