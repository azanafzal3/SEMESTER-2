#include"Date.h"

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

void Date::setDay(int dayVal)
{
    day = dayVal;
}

void Date::setMonth(int monthVal)
{
    month = monthVal;
}

void Date::setYear(int yearVal)
{
    year = yearVal;
}
