#pragma once
#include<iostream>
#include<string>
#include"User.h"
#include"DoctorPatient.h"
#include"Admin.h"

using namespace std;

class OlaDoc
{
	int userType;
	string name, city;
	User* user;
	Admin* admin;
	Patient* patient;
	Doctor* doctor;

public:

	OlaDoc(string = "", string = "");

	// getters
	string getName();
	string getCity();

	//setter
	void setName(string val);
	void setCity(string val);

	bool Register(int usertype, int ID, const char* username, const char* password, const char* cnic, const char* email, const char* specialityVal, int chargesVal, const char* locationVal, bool emailchoice);
	bool Login(int usertype, int ID, const char* userName, const char* password);
	void setSchedule(char* username, int ID);
	void bookAppointment(int val, int);
};
