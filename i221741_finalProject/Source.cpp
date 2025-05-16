#include<iostream>
#include<fstream>
#include<string>
#include"OlaDoc.h"
#include"Feedback.h"

using namespace std;
bool passwordIsValid(char* password)
{
	bool specialChar = 1, uppercase = 1, lowercase = 1, digit = 1, isValid;
	if (strlen(password) >= 8)
	{
		// check special char
		for (int i = 0; i < strlen(password); i++)
		{
			if (!(((password[i] >= 48 && password[i] <= 57) || (password[i] >= 65 && password[i] <= 90) || (password[i] >= 97 && password[i] <= 122))))
			{
				specialChar = 0;
			}
			else
			{
				specialChar = 1;
				break;
			}
		}

		// check upper case 
		for (int i = 0; i < strlen(password); i++)
		{
			if (!((password[i] >= 65) && (password[i] <= 90)))
			{
				uppercase = 0;
			}
			else
			{
				uppercase = 1;
				break;
			}
		}

		// check lower case 
		for (int i = 0; i < strlen(password); i++)
		{
			if (!((password[i] >= 97) && (password[i] <= 122)))
			{
				lowercase = 0;
			}
			else
			{
				lowercase = 1;
				break;
			}
		}

		// check digit
		for (int i = 0; i < strlen(password); i++)
		{
			if (!((password[i] - '0' >= 0) && (password[i] - '0' <= 9)))
			{
				digit = 0;
			}
			else
			{
				digit = 1;
				break;
			}
		}

		// isValid or not
		if ((lowercase == 1) && (uppercase == 1) && (digit == 1) && (specialChar == 1))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		cout << "length not correct" << endl;
		return 0;
	}
}
bool checkCNIC(char* cnic)
{
	// checking first 5 digits
	for (int i = 0; i < 4; i++)
	{
		if (!((cnic[i] - '0' >= 0) && (cnic[i] - '0' <= 9)))
		{
			return 0;
		}
	}

	if (cnic[5] != '-')
		return 0;

	// checking next 7 digits
	for (int i = 6; i < 12; i++)
	{
		if (!((cnic[i] - '0' >= 0) && (cnic[i] - '0' <= 9)))
		{
			return 0;
		}
	}

	if (cnic[13] != '-')
		return 0;

	if (!(cnic[14] - '0' >= 0) && (cnic[14] - '0' <= 9))
		return 0;
}
int main()
{
	OlaDoc obj;
	char username[20], password[20], password1[20], email[20], speciality[20], location[20], hospitalchoice[20];
	char cnic[20];
	bool email_choice, Action_choice;

	cout << "----- Welcome to the home screen! -----" << endl;
	int choice = 1, usertype, user_choice, login_choice, charges, operation_choice, ID, action, numeric_limits;

	while (choice != 0)
	{
		cout << endl << "What would you like to do?" << endl << endl;
		cout << "1. Register" << endl << "2. Login" << endl << "3. Logout" << endl << "0. Exit" << endl << "Choice: ";
		cin >> choice;

		// Register
		if (choice == 1)
		{
			cout << "Press 1 for Doctor and 2 for Patient" << endl << "Choice: ";
			cin >> usertype;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (usertype == 1) // doctor
			{
				cout << "Enter 1 for registration through CNIC and 0 for registration through email:";
				cin >> email_choice;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (email_choice == 1)
				{
					cout << "Enter your CNIC: ";
					cin.getline(cnic, 20);
					if(!checkCNIC(cnic)) // if cnic is not valid
					{
						cout << "Invalid cnic" << endl;
						continue;
					}
				}
				else if(email_choice == 0)
				{
					cout << "Enter email: ";
					cin.getline(email, 20);
				}
				else
				{
					cout << "Invalid" << endl;
					continue;
				}
				cout << "Enter the data: " << endl;
				cout << "Username: ";
				cin.getline(username, 20);
				cout << "Password length must be greater or equal to 8 characters. Password must contain one upper case" << endl << ", lower case, special characterand a digit." << endl << "Password: ";
				cin.getline(password, 20);
				cout << "ID: ";
				cin >> ID;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Speciality: ";
				cin.getline(speciality, 20);
				cout << "Hourly charges:";
				cin >> charges;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Which location do you work in: ";
				cin.getline(location, 20);
				if (obj.Register(1, ID, username, password, cnic, email, speciality, charges, location, email_choice))
				{
					cout << "Doctor registered successfully!" << endl;
				}
				else
				{
					cout << "Doctor not registered" << endl;
				}
			}

			else if (usertype == 2)
			{
				cout << "Enter your CNIC: ";
				cin.getline(cnic, 20);
				if (!checkCNIC(cnic)) // if cnic is not valid
				{
					cout << "Invalid cnic" << endl;
					continue;
				}
				cout << "Enter the data: " << endl;
				cout << "Username: ";
				cin.getline(username, 20);
				cout << "Password length must be greater or equal to 8 characters. Password must contain one upper case, lower case, special character and a digit." << endl << "Password: ";
				cin.getline(password, 20);

				cout << "Re-enter your password: ";
				cin.getline(password1, 20);

				// check password
				if (strcmp(password, password1) == 0)
				{
					if (!(passwordIsValid(password)))
					{
						cout << "Invalid password" << endl;
						continue;
					}
				}
				else
				{
					cout << "The passwords don't match." << endl;
					continue;
				}
				cout << "ID: ";
				cin >> ID;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (obj.Register(2, ID, username, password, cnic, email, "", 0, "", 0))
				{
					cout << "Patient registered successfully!" << endl;
				}
				else
				{
					cout << "Patient not registered" << endl;
				}
			}
		}

		else if (choice == 2)// login
		{
			cout << endl << "Admin(Press 1), Doctor(Press 2) or Patient(Press 3)?" << endl << "Choice: ";
			cin >> login_choice;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (login_choice == 1)
			{
				cout << "Enter the details: " << endl << "Username: ";
				cin.getline(username, 20);

				cout << "Password: ";
				cin.getline(password, 20);

				cout << "ID: ";
				cin >> ID;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				if (obj.Login(1, ID, username, password))
				{
					char username_doctor[20];

					cout << endl << "Login successful" << endl;

					// Different choices for the admin
					cout << "What would you like to do? " << endl;
					cout << "1. Set a schedule for any doctor";

					cout << endl << "Choice: ";
					cin >> Action_choice;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (Action_choice == 1)
					{
						cout << "Enter the username of the doctor: ";
						cin.getline(username_doctor, 20);
						cout << "ID: ";
						cin >> ID;
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						obj.setSchedule(username_doctor, ID);
					}

				}
				else
				{
					cout << "Wrong credendtials" << endl;
				}
			}

			else if (login_choice == 2) // doctor
			{
				cout << "Enter the details: " << endl << "Username: ";
				cin.getline(username, 20);

				cout << "Password: ";
				cin.getline(password, 20);

				cout << "ID: ";
				cin >> ID;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				if (obj.Login(2, ID, username, password))
				{
					cout << endl << "Login successful" << endl;
				}
				else
				{
					cout << "Wrong credendtials" << endl;
				}
			}

			else if (login_choice == 3) // patient
			{
				char review[300];

				cout << "Enter the details: " << endl << "Username: ";
				cin.getline(username, 20);

				cout << "Password: ";
				cin.getline(password, 20);

				cout << "ID: ";
				cin >> ID;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				if (obj.Login(3, ID, username, password))
				{
					cout << endl << "Login successful" << endl;

					// Different choices for the user
					cout << "What would you like to do? " << endl;
					cout << "1. Book an appointment" << endl << "2. Give feedback" << endl;

					cout << endl << "Choice: ";
					cin >> choice;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (choice == 1)
					{
						cout << "Search by: " << endl << "1. Speacialization" << endl << "2. Area" << endl << "Choice: ";
						cin >> action;
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						obj.bookAppointment(action, ID);
					}
					else if (choice == 2)
					{
						Feedback feed;
						cout << endl << "Review: ";
						cin.getline(review, 300);
						feed.setReview(review);

						cout << "Your review is recorded" << endl;
					}
					
				}
				else
				{
					cout << "Wrong credendtials" << endl;
				}
			}


		}
	}
}
