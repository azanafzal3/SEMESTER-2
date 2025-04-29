#pragma once
#include<iostream>
#include<string>

using namespace std;

class User
{
protected:
	char username[20], password[20], email[20];
	char CNIC[20];
	int ID;
	bool isLoggedIn;
	bool isAdmin;
public:
	User(const char* = "", const char* = "", const char* = "", int = -1, bool = 0, bool = 0);

	// getters
	char* getUserName();
	char* getCNIC();
	char* getPassword();
	char* getEmail();
	int getID();
	bool getIsLoggedIn();
	bool getIsAdmin();

	// setters
	void setUserName(const char* val);
	void setCNIC(const char* val);
	void setPassword(const char* val);
	void setEmail(const char* val);
	void setID(int val);
	void setIsLoggedIn(bool val);
	void setIsAdmin(bool val);
};
