#pragma once
#pragma once
#include<iostream>
#include<string>
#include"User.h"
#include"Schedule.h"
#include"Appointment.h"
class Patient;

using namespace std;

class Doctor : public User
{
protected:
	char speciality[20];
	int rating;
	double balance;
	bool availability;
	int charges;
	char location[20];
	char** workingHospital;
	Schedule schedule;
	Patient* patientsList;
public:
	Doctor(const char* = "", int = -1, double = -1, bool = 1, int = 0, const char* = "");

	// getters
	char* getSpeciality();
	int getRating();
	double getBalance();
	bool getAvailability();
	int getCharges();
	char* getLocation();
	char** getWorkingHospital();
	Time& getTimeStart(int dayVal);
	Time& getTimeEnd(int dayVal);
	bool* getDaysAvailable();

	// setters
	void setSpeciality(const char* val);
	void setRating(int val);
	void setBalance(double);
	void setAvailability(bool val);
	void setCharges(int val);
	void setLocation(const char* val);
	void setWorkingHospital(char** val);
	void setSchedule(Schedule& val);
	void setPatientsList(Patient* patients, int);

	void getInstances();
};

class Patient : public User
{
	double balance;
	bool hasAppointment;
	int appointmentNo;
	Date showUpDate;
	Doctor* doctorsList;
	Appointment* appointment;

public:
	Patient(double = -1, bool = 0);

	// getters
	double getBalance();
	bool getHasAppointment();
	Date& getShowUpDate();

	// setters
	void setBalance(double val);
	void setHasAppointment(bool val);
	void setShowUpDate(Date& dateVal);
	void setDoctorsList(Doctor* doctors, int);

	bool searchDoctorSp(char* specializationVal, int*, char*, int);
	bool searchDoctorArea(char* areaVal, int*, char*);
	bool bookAppointment(int searchMode, int ID);

	void getInstances();
};
