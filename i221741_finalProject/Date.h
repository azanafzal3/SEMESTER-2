#pragma once
using namespace std;

class Date
{
	int day, month, year;
public:
	Date();

	int getDay();
	int getMonth();
	int getYear();

	void setDay(int dayVal);
	void setMonth(int monthVal);
	void setYear(int yearVal);
};
