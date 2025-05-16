#include <iostream>
using namespace std;
class Employee2 {
private:
    char* name;
    float hourlyWage;
    float workedHours;
    float extraHours;
public:
    Employee2()     // Constructor
	{
        name = new char[50];
        hourlyWage = 0.0;
        workedHours = 0.0;
        extraHours = 0.0;
    }
float wageCalculator()  //Function to calculate wage
{
        cout << "Please enter employee's name: ";
        cin >> name;
        cout << "Please enter hourly wage : ";
        cin >> hourlyWage;
        cout << "Please enter hours worked : ";
        cin >> workedHours;
        
        //will calculate wage
        float overtimeHours = 0.0;
        if (workedHours > 40.0) 
		{
            overtimeHours = workedHours - 40.0;
            workedHours = 40.0;
        }
        extraHours = overtimeHours;
        float regularPay = workedHours * hourlyWage;
        float overtimePay = overtimeHours * (hourlyWage * 1.5);
        float totalPay = regularPay + overtimePay;

        cout<<"Paycheck for employee "<<name<<endl;
        cout<<"Hours worked: "<<workedHours + overtimeHours<<endl;
        cout<<"Hourly wage: "<<hourlyWage<<endl;
        if (overtimeHours > 0.0) 
		{
            cout<< "Overtime hours: " <<overtimeHours<<endl;
            cout<< "Overtime hourly wage: "<<hourlyWage * 1.5<<endl;
        }
        cout<< "Total payment: "<<totalPay<<endl;
        return totalPay;
}
};

int main() {
    Employee2 emp1;
    emp1.wageCalculator();
    return 0;
}
