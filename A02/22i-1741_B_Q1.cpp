#include <iostream>
#include <cstring> 
using namespace std;
class Employee {
private:
    char *name;
    double salary;
public:
    Employee(char *name, double salary)      // Default constructor
	{
        this->name = new char[strlen(name) + 1];    //Will allocate  memory and copy it
        strcpy(this->name, name);
        this->salary = salary;         //setting of salary
    }
    ~Employee()   // Destructor 
	{
        delete [] name;
    }
    char* getName()
	{
        return name;
    }
    double getSalary()
	{
        return salary;
    }
};

int main()
{
    char name[] ="Larry Bird";
    double salary = 200000;
    Employee employee(name, salary);
    cout << "New employee has been created." << endl;
    cout << "Name of employee: " << employee.getName() << endl;
    cout << "Salary: " << employee.getSalary() << endl;
    return 0;
}
