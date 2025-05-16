#include"DoctorPatient.h"
#include<fstream>
#include"Appointment.h"
#include"Time.h"

using namespace std;

Patient::Patient(double balanceval, bool HasAppointment)
{
	balance = balanceval;
	hasAppointment = HasAppointment;

	showUpDate.setDay(0);
	showUpDate.setMonth(0);
	showUpDate.setYear(0);
	appointmentNo = 0;

	appointment = new Appointment[5];
}

double Patient::getBalance()
{
	return balance;
}

bool Patient::getHasAppointment()
{
	return hasAppointment;
}

Date& Patient::getShowUpDate()
{
	return showUpDate;
}

void Patient::setBalance(double val)
{
	balance = val;
}

void Patient::setHasAppointment(bool val)
{
	hasAppointment = val;
}

void Patient::setShowUpDate(Date& dateVal)
{
	showUpDate = dateVal;
}

void Patient::setDoctorsList(Doctor* doctors, int ID)
{
	this[ID].doctorsList = new Doctor[100];

	for (int i = 0; i < 100; i++)
	{
		this[ID].doctorsList[i] = doctors[i];
	}
}

bool Patient::searchDoctorSp(char* specializationVal, int* doctorIDptr, char* doctorname, int ID)
{
	ifstream fin;
	int i = 0;

	fin.open("C:\\Users\Haris'\source\repos\Project\Project\doctor.dat", ios::binary | ios::in);

	if (!fin)
	{
		/*fin.read((char*)(&this[ID].doctorsList[i]), sizeof(this[ID].doctorsList[i]));
		while (!fin.eof())
		{
			if ((strcmp(specializationVal, this[ID].doctorsList[i].getSpeciality()) == 0) && (this[ID].doctorsList[i++].getAvailability() != 0))
			{
				fin.close();
				*doctorIDptr = i - 1;
				strcpy_s(doctorname, 20, this[ID].doctorsList[i - 1].getUserName());
				return 1;
			}
		}*/
		return 0; // not found
	}
	else
	{
		cout << "File not found" << endl;
	}
}

bool Patient::searchDoctorArea(char* areaVal, int* doctorIDptr, char* doctorname)
{
	ifstream fin;
	int i = 0;
	fin.open("doctor.dat", ios::binary | ios::in);
	if (!fin)
	{
		fin.read((char*)(&doctorsList[0]), sizeof(doctorsList[0]));

		while (!fin.eof())
		{
			if ((strcmp(areaVal, doctorsList[i].getLocation()) == 0) && (doctorsList[i++].getAvailability() != 0))
			{
				fin.close();
				*doctorIDptr = i - 1;
				strcpy_s(doctorname, 20, doctorsList[i - 1].getUserName());
				return 1;
			}
		}
		return 0; // not found
	}
	else
	{
		cout << "File not found" << endl;
	}
	
}

bool Patient::bookAppointment(int searchMode, int ID)
{
	char specialization[20];
	int* doctorID_ptr = 0;

	char doctorName[20], appointmentMode[30];
	int day;
	int hour, minute, month, year;
	Time time;
	Date date;

	if (searchMode == 1) // search by specialization
	{
		cout << "Which specialist do you want? \nEnter their specialization: ";
		cin.getline(specialization, 20);

		if (searchDoctorSp(specialization, doctorID_ptr, doctorName, ID))
		{
			doctorsList[*doctorID_ptr].setAvailability(0); // doctor is busy now
			this->hasAppointment = 1;

			cout << "1. Monday \n 2. Tuesday \n 3. Wednesday \n 4.Thursday \n 5. Friday";
			cout << endl << "Enter the day of the appointment: ";
			cin >> day;

			time = doctorsList[*doctorID_ptr].getTimeStart(day);

			// displaying the doctor schedule
			cout << "Starting time of shift: " << time.getHour() << ":" << time.getMinute() << endl;

			time = doctorsList[*doctorID_ptr].getTimeEnd(day);

			cout << "Ending time of shift: " << time.getHour() << ":" << time.getMinute() << endl;

			// Asking about date of the appointment
			cout << "Enter the date of the appointment: ";
			cout << "Day: ";
			cin >> day;
			cout << "Month: ";
			cin >> month;
			cout << "Year: ";
			cin >> year;

			date.setDay(day);
			date.setMonth(month);
			date.setYear(year);

			this->appointment[appointmentNo].setBookDate(date);

			// Asking about time slot
			cout << "Enter the time you want to visit: \n Hour: ";
			cin >> hour;
			cout << "Minute: ";
			cin >> minute;
			time.setHour(hour);
			time.setMinute(minute);

			this->appointment[appointmentNo].setTime(time);

			// Asking about the appointment mode
			cout << "Appointment mode: ";
			cin.getline(appointmentMode, 30);
			this->appointment[appointmentNo].setAppointmentMode(appointmentMode);
			
			this->appointment[appointmentNo].setDoctorName(doctorName);

			// storing in file
			ofstream fout;
			fout.open("appointment.dat", ios::binary | ios::app);
			fout.write((char*)&appointment[appointmentNo], sizeof(appointment[appointmentNo++]));
			fout.close();

			return 1;
		}
	}
}

void Patient::getInstances()
{
	doctorsList = new Doctor[100];
}


