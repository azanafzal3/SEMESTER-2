#include"OlaDoc.h"
#include<iostream>
#include<string>
#include<fstream>
#include"DoctorPatient.h"
#include"Schedule.h"

using namespace std;

OlaDoc::OlaDoc(string nameVal, string cityVal)
{
	name = nameVal;
	city = cityVal;

	user = new User[100];
	doctor = new Doctor[100];
	patient = new Patient[100];

	/*for (int i = 0; i < 100; i++)
	{
		doctor[i].getInstances();
		patient[i].getInstances();
	}*/

	for (int i = 0; i < 100; i++)
	{
		doctor[i].setPatientsList(patient, i);
		patient[i].setDoctorsList(doctor, i);
	}

	admin = new Admin[5];

	for (int i = 0; i < 5; i++)
	{
		admin[i].setDoctorsList(doctor);
		admin[i].setPatientsList(patient);
	}
	
	admin[0].setUserName("admin1");
	admin[0].setPassword("admin1");

	admin[1].setUserName("admin2");
	admin[1].setPassword("admin2");

	admin[2].setUserName("admin3");
	admin[2].setPassword("admin3");

	admin[3].setUserName("admin4");
	admin[3].setPassword("admin4");

	admin[4].setUserName("admin5");
	admin[4].setPassword("admin5");
	// storing in file
	ofstream fout;
	fout.open("admin.dat", ios::app | ios::binary);
	fout.write((char*)(&admin[0]), sizeof(admin[0]));
	fout.close();

	fout.open("admin.dat", ios::app | ios::binary);
	fout.write((char*)(&admin[1]), sizeof(admin[1]));
	fout.close();

	fout.open("admin.dat", ios::app | ios::binary);
	fout.write((char*)(&admin[2]), sizeof(admin[2]));
	fout.close();

	fout.open("admin.dat", ios::app | ios::binary);
	fout.write((char*)(&admin[3]), sizeof(admin[3]));
	fout.close();

	fout.open("admin.dat", ios::app | ios::binary);
	fout.write((char*)(&admin[4]), sizeof(admin[4]));
	fout.close();
}

string OlaDoc::getName()
{
	return name;
}

string OlaDoc::getCity()
{
	return city;
}

void OlaDoc::setName(string val)
{
	name = val;
}

void OlaDoc::setCity(string val)
{
	city = val;
}

bool OlaDoc::Register(int usertype, int ID, const char* username, const char* password, const char* cnic, const char* email,
	const char* specialityVal, int chargesVal, const char* locationVal, bool emailchoice)
{
	bool email_CNICflag = 0;
	if (usertype == 1) // doctor
	{
		if (emailchoice == 1) // user asked registration through CNIC
		{
			// if cnic is already in the database
			ifstream fin;
			fin.open("doctor.dat", ios::in | ios::binary);
			if (!fin)
			{
				
			}
			else
			{
				fin.read((char*)(&doctor[ID]), sizeof(doctor[ID]));

				while (!fin.eof())
				{
					if (strcmp(doctor[ID].getCNIC(), cnic) == 0)
					{
						cout << "The cnic you entered already exists in the database. Enter your original cnic." << endl;
						fin.close();
						email_CNICflag = 1;
						break;
					}
					fin.read((char*)(&doctor[ID]), sizeof(doctor[ID]));
				}
				fin.close();
				if (email_CNICflag == 0)
				{
					doctor[ID].setCNIC(cnic);
				}
			}
		}
		
		else
		{
			// checking if email already exists in the database
			ifstream fin;
			fin.open("doctor.dat", ios::in | ios::binary);

			if (!fin)
			{

			}
			else
			{
				fin.read((char*)(&doctor[ID]), sizeof(doctor[ID]));

				while (!fin.eof())
				{
					if (strcmp(doctor[ID].getEmail(), email) == 0)
					{
						cout << "The email you entered already exists in the database. Enter your original email." << endl;
						fin.close();
						email_CNICflag = 1;
						break;
					}
					fin.read((char*)(&doctor[ID]), sizeof(doctor[ID]));
				}
				fin.close();
				if (email_CNICflag == 0)
				{
					doctor[ID].setEmail(email);
				}
			}
			
		}
		
		if (email_CNICflag == 0)
		{
			doctor[ID].setSpeciality(specialityVal);
			doctor[ID].setCharges(chargesVal);
			doctor[ID].setLocation(locationVal);
			doctor[ID].setUserName(username);
			doctor[ID].setPassword(password);

			// storing in file
			ofstream fout;
			fout.open("doctor.dat", ios::app | ios::binary);
			fout.write((char*)(&doctor[ID]), sizeof(doctor[ID]));
			fout.close();

			return 1;
		}
		else
		{
			return 0;
		}
		
	}

	else if (usertype == 2) // patient
	{
		email_CNICflag = 0;
		ifstream fin;
		fin.open("patient.dat", ios::in | ios::binary);
		if (!fin)
		{

		}
		else
		{
			fin.read((char*)(&patient[ID]), sizeof(patient[ID]));
			
			while (!fin.eof())
			{
				if (strcmp(patient[ID].getCNIC(), cnic) == 0)
				{
					cout << "The cnic you entered already exists in the database. Enter your original cnic." << endl;
					fin.close();
					email_CNICflag = 1;
					break;
				}
				fin.read((char*)(&patient[ID]), sizeof(patient[ID]));
			}
				fin.close();
				if (email_CNICflag == 0)
				{
					patient[ID].setCNIC(cnic);
				}
			}
		}

	if (email_CNICflag == 0)
	{
		patient[ID].setUserName(username);
		patient[ID].setPassword(password);
		patient[ID].setBalance(3500);

		// storing in file
		ofstream fout;
		fout.open("patient.dat", ios::app | ios::binary);
		fout.write((char*)(&patient[ID]), sizeof(patient[ID]));
		fout.close();

		return 1;
	}
	else
	{
		return 0;
	}
}

bool OlaDoc::Login(int usertype, int ID, const char* userName, const char* password)
{
	fstream fin;
	if (usertype == 1) // Admin
	{
		fin.open("admin.dat", ios::binary | ios::in);

		fin.read((char*)&admin[ID], sizeof(admin[ID]));

		if ((strcmp(admin[ID].getUserName(), userName) == 0) && (strcmp(admin[ID].getPassword(), password) == 0))
		{
			admin[ID].setIsLoggedIn(1);
			fin.close();
			return 1;
		}
		return 0;
	}

	else if (usertype == 2) // doctor
	{
		fin.open("doctor.dat", ios::binary | ios::in);

		fin.read((char*)&doctor[ID], sizeof(doctor[ID]));

		if ((strcmp(doctor[ID].getUserName(), userName) == 0) && (strcmp(doctor[ID].getPassword(), password) == 0))
		{
			doctor[ID].setIsLoggedIn(1);
			fin.close();
			return 1;
		}
		return 0;
	}

	else if (usertype == 3) // patient
	{
		fin.open("patient.dat", ios::binary | ios::in);

		fin.read((char*)&patient[ID], sizeof(patient[ID]));

		if ((strcmp(patient[ID].getUserName(), userName) == 0) && (strcmp(patient[ID].getPassword(), password) == 0))
		{
			patient[ID].setIsLoggedIn(1);
			fin.close();
			return 1;
		}
		return 0;
	}
}

void OlaDoc::setSchedule(char* username, int ID)
{
	// input the schedule
	int choice, hour, minute;
	Schedule schedule;
	Time time;

	fstream fin;
	fin.open("doctor.dat", ios::binary | ios::in);
	
	fin.read((char*)&doctor[ID], sizeof(doctor[ID]));

	if (strcmp(username, doctor[ID].getUserName()) == 0)
	{
		// asking about day of the schedule
		cout << "Which day do you want to set the schedule of?" << endl << "1. Monday" << endl << "2. Tuesday" << endl;
		cout << "3. Wednesday" << endl << "4. Thursday" << endl << "5. Friday" << endl << "6. Saturday" << endl << "7. Sunday";
		cout << endl << "Enter your choice: ";

		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		schedule.setDaysAvailable(choice - 1);

		// asking about starting time of the shift on that particular day
		cout << "Enter the starting time of the shift: " << endl << "Hour: ";
		cin >> hour;
		cout << "Minute: ";
		cin >> minute;

		time.setHour(hour);
		time.setMinute(minute);

		schedule.setTimeStart(choice - 1, time);

		// asking about ending time of the shift on that particular day
		cout << "Enter the ending time of the shift: " << endl << "Hour: ";
		cin >> hour;
		cout << "Minute: ";
		cin >> minute;

		time.setHour(hour);
		time.setMinute(minute);

		schedule.setTimeEnd(choice - 1, time);

		cout << endl << "Schedule is set successfully" << endl;
	}
	else
	{
		cout << "Wrong credentials" << endl;
	}
}

void OlaDoc::bookAppointment(int val, int ID)
{
	patient[ID].bookAppointment(val, ID);
}
