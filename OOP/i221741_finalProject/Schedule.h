#pragma once
#include<string>
#include"Time.h"

using namespace std;

class Schedule
{
	bool daysAvailable[7];
	Time timeStart[7];
	Time timeEnd[7];
public:
	Schedule();
	// getters
	bool* getDaysAvailable();
	Time& getTimeStart(int dayVal); // here dayVal is the day on which you want to get the time 
	Time& getTimeEnd(int dayVal); // here dayVal is the day on which you want to get the time

	// setters
	void setDaysAvailable(int dayVal); // here dayVal is the day on which you want the availablity to be set
	void setTimeStart(int dayVal, Time& time); // here dayVal is the day on which you want the time to be set
	void setTimeEnd(int dayVal, Time& time); // here dayVal is the day on which you want the time to be set
};

