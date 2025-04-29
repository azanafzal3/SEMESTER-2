#include "Admin.h"

Admin::Admin()
{

}

void Admin::setDoctorsList(Doctor* doctor)
{
	for (int i = 0; i < 100; i++)
	{
		doctorsList[i] = doctor[i];
	}
}

void Admin::setPatientsList(Patient* patients)
{
	for (int i = 0; i < 100; i++)
	{
		patientsList[i] = patients[i];
	}
}
