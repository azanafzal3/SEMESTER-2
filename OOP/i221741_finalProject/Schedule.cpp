#include"Schedule.h"

Schedule::Schedule()
{
	for (int i = 0; i < 7; i++)
	{
		daysAvailable[i] = 1;
	}
}

bool* Schedule::getDaysAvailable()
{
	return daysAvailable;
}

Time& Schedule::getTimeStart(int dayVal)
{
	return timeStart[dayVal];
}

Time& Schedule::getTimeEnd(int dayVal)
{
	return timeEnd[dayVal];
}

void Schedule::setDaysAvailable(int dayVal)
{
	daysAvailable[dayVal] = 1;
}

void Schedule::setTimeStart(int dayVal, Time& time)
{
	timeStart[dayVal] = time;
}

void Schedule::setTimeEnd(int dayVal, Time& time)
{
	timeEnd[dayVal] = time;
}
