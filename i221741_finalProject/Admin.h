#pragma once
#include<iostream>
#include<string>
#include"User.h"
#include"DoctorPatient.h"

using namespace std;

class Admin: public User
{
	Doctor doctorsList[100];
	Patient patientsList[100];
public:
	Admin();
	void setDoctorsList(Doctor* doctor);
	void setPatientsList(Patient* patients);
};
