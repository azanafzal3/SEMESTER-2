#include"DoctorPatient.h"
#include<string>
#include<iostream>

using namespace std;

Doctor::Doctor(const char* specialityVal, int ratingVal, double Balance, bool available, int charge, const char* Location)
{
	strcpy_s(speciality, 20, specialityVal);
	rating = ratingVal;
	balance = Balance;
	availability = available;
	charges = charge;
	strcpy_s(location, 20, Location);
}

char* Doctor::getSpeciality()
{
	return speciality;
}

int Doctor::getRating()
{
	return rating;
}

double Doctor::getBalance()
{
	return balance;
}

bool Doctor::getAvailability()
{
	return availability;
}

int Doctor::getCharges()
{
	return charges;
}

char* Doctor::getLocation()
{
	return location;
}

char** Doctor::getWorkingHospital()
{
	return workingHospital;
}

Time& Doctor::getTimeStart(int dayVal)
{
	return schedule.getTimeStart(dayVal);
}

Time& Doctor::getTimeEnd(int dayVal)
{
	return schedule.getTimeEnd(dayVal);
}

bool* Doctor::getDaysAvailable()
{
	return schedule.getDaysAvailable();
}

void Doctor::setSpeciality(const char* val)
{
	strcpy_s(speciality, 20, val);
}

void Doctor::setRating(int val)
{
	rating = val;
}

void Doctor::setBalance(double val)
{
	balance = val;
}

void Doctor::setAvailability(bool val)
{
	availability = val;
}

void Doctor::setCharges(int val)
{
	charges = val;
}

void Doctor::setLocation(const char* val)
{
	strcpy_s(location, 20, val);
}

void Doctor::setWorkingHospital(char** val)
{
	/*for (int i = 0; i <= BUFSIZ; i++)
	{
		strcpy(workingHospital[i], val[i]);
	}*/
}

void Doctor::setSchedule(Schedule& val)
{
	schedule = val;
}

void Doctor::setPatientsList(Patient* patient, int id)
{
	this[id].patientsList = new Patient[100];

	for (int i = 0; i < 100; i++)
	{
		this[id].patientsList[i] = patient[i];
	}
}

void Doctor::getInstances()
{
	patientsList = new Patient[100];
}
