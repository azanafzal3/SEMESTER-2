#pragma once
#include<string>
#include"Date.h"
#include"Time.h"
using namespace std;

class Appointment
{
	Date bookDate;
	Date cancelDate;
	Time time;
	char doctorName[20];
	char appointmentMode[30];
	char status[20];
public:
	Appointment(const char* = "", const char*  = "", const char* = "pending");

	// setters 
	void setBookDate(Date& date);
	void setCancelDate(Date& date);
	void setTime(Time& time);
	void setDoctorName(char* doctorname);
	void setAppointmentMode(char* val);

	// getters
	Date& getBookDate();
	Date& getCancelDate();
	Time& getTime();
	char* getDoctorName();
	char* getAppointmentMode();
	char* getStatus();
};