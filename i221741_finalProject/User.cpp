#include "User.h"

User::User(const char* cnic, const char* userName, const char* Password, int id, bool loggedin, bool isadmin)
{
	strcpy_s(CNIC, 20, cnic);
	strcpy_s(username, 20, userName);
	strcpy_s(password, 20, Password);
	ID = id;
	isLoggedIn = loggedin;
	isAdmin = isadmin;
}

char* User::getUserName()
{
	return username;
}

char* User::getCNIC()
{
	return CNIC;
}

char* User::getPassword()
{
	return password;
}

char* User::getEmail()
{
	return email;
}

int User::getID()
{
	return ID;
}

bool User::getIsLoggedIn()
{
	return isLoggedIn;
}

bool User::getIsAdmin()
{
	return isAdmin;
}

void User::setUserName(const char* val)
{
	strcpy_s(username, 20, val);
}

void User::setCNIC(const char* val)
{
	strcpy_s(CNIC, 20, val);
	int i;
	/*for (i = 0; i < strlen(val); i++)
	{
		CNIC[i] = val[i];
	}
	CNIC[i] = '\0';*/
	//strcpy(CNIC, val);
}

void User::setPassword(const char* val)
{
	strcpy_s(password, 20, val);
}

void User::setEmail(const char* val)
{
	strcpy_s(email, 20, val);
}

void User::setID(int val)
{
	ID = val;
}

void User::setIsLoggedIn(bool val)
{
	isLoggedIn = val;
}

void User::setIsAdmin(bool val)
{
	isAdmin = val;
}
