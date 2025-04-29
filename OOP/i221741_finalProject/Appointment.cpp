#include"Appointment.h"

Appointment::Appointment(const char* doctorname, const char* appointmentmode, const char* Status)
{
	strcpy_s(doctorName, 20, doctorname);
	strcpy_s(appointmentMode, 20, appointmentmode);
	strcpy_s(status, 20, Status);
}

void Appointment::setBookDate(Date& date)
{
	bookDate = date;
}

void Appointment::setCancelDate(Date& date)
{
	cancelDate = date;
}

void Appointment::setTime(Time& time)
{
	this->time = time;
}

void Appointment::setDoctorName(char* doctorname)
{
	strcpy_s(doctorName, 20, doctorname);
}

void Appointment::setAppointmentMode(char* val)
{
	strcpy_s(appointmentMode, 20, val);
}

Date& Appointment::getBookDate()
{
	return bookDate;
}

Date& Appointment::getCancelDate()
{
	return cancelDate;
}

Time& Appointment::getTime()
{
	return time;
}

char* Appointment::getDoctorName()
{
	return doctorName;
}

char* Appointment::getAppointmentMode()
{
	return appointmentMode;
}

char* Appointment::getStatus()
{
	return status;
}
