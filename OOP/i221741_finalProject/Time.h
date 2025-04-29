#pragma once
using namespace std;

class Time
{
	int hour, minute, second;
public:
	Time();

	// getters
	int getHour();
	int getMinute();
	int getSecond();

	//setters
	void setHour(int val);
	void setMinute(int val);
	void setSecond(int val);
};
