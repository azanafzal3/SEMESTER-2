#include <iostream>
#include <string>
using namespace std;
class Student {
    private:
        char* rollNumber;
        char* name;
        int batch;
        int coursesCode[5];
        char* coursesName[5];
        char coursesGrades[5];
        float cgpa;
        char* degree;
        char* dob;
        
    public:
        // Default Constructor
        Student() {
            rollNumber = new char[10];
            name = new char[50];
            degree = new char[50];
            dob = new char[20];
            batch = 0;
            cgpa = 0.0;
            for(int i=0; i<5; i++) 
			{
                coursesCode[i] = 0;
                coursesName[i] = new char[50];
                coursesGrades[i] = ' ';
            }
        }
        
        // Overloaded Constructor
Student(char* rollNumber, char* name, int batch, int coursesCode[], char* coursesName[],
            char coursesGrades[], float cgpa, char* degree, char* dob) {
            this->rollNumber = rollNumber;
            this->name = name;
            this->batch = batch;
            this->cgpa = cgpa;
            this->degree = degree;
            this->dob = dob;
            for(int i=0; i<5; i++) {
                this->coursesCode[i] = coursesCode[i];
                this->coursesName[i] = coursesName[i];
                this->coursesGrades[i] = coursesGrades[i];
            }
        }
        
        // Setter functions for each data member
        void setRollNumber(char* rollNumber) 
		{
            this->rollNumber = rollNumber;
        }
        
        void setName(char* name) 
		{
            this->name = name;
        }
        
        void setBatch(int batch) 
		{
            this->batch = batch;
        }
        
        void setCourseCode(int index, int code)
		{
            coursesCode[index] = code;
        }
        
        void setCourseName(int index, char* name) 
		{
            coursesName[index] = name;
        }
        
        void setCourseGrade(int index, char grade) 
		{
            coursesGrades[index] = grade;
        }
        
        void setCGPA(float cgpa) 
		{
            this->cgpa = cgpa;
        }
        
        void setDegree(char* degree) 
		{
            this->degree = degree;
        }
        
        void setDOB(char* dob) 
		{
            this->dob = dob;
        }
        
        // Display function to show transcript of the student
void display() 
{
    cout << "+----------------------------------+" << endl;
    cout << "|            TRANSCRIPT            |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "| Roll Number:         " << rollNumber << "       |" << endl;
    cout << "| Name:                " << name << "    |" << endl;
    cout << "| Degree:              " << degree << "        |" << endl;
    cout << "| Batch:               " << batch << "               |" << endl;
    cout << "| CGPA:                " << cgpa << "                |" << endl;
    cout << "| Date of Birth:       " << dob << "           |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "|  Course Code | Course Name      | Grade |" << endl;
    cout << "+----------------------------------+" << endl;
    for(int i=0; i<5; i++) 
	{
        cout << "| " << coursesCode[i] << " | " << coursesName[i] << " | " << coursesGrades[i] << " |" << endl;
    }
    cout << "+----------------------------------+" << endl;
}


void studentDemo() {
    Student s1;
    s1.setValues();

    // display initial transcript
    s1.display();

    // update student data
    s1.setName("John Smith");
    s1.setBatch(2023);
    s1.setCGPA(3.8);
    s1.setDegree("Bachelor of Science");
    s1.setDOB("01/01/2005");
    s1.setCourseCode(0, 1001);
    s1.setCourseCode(1, 1002);
    s1.setCourseCode(2, 1003);
    s1.setCourseCode(3, 1004);
    s1.setCourseCode(4, 1005);
    s1.setCourseName(0, "Mathematics");
    s1.setCourseName(1, "Physics");
    s1.setCourseName(2, "Chemistry");
    s1.setCourseName(3, "Computer Science");
    s1.setCourseName(4, "English");
    s1.setCourseGrade(0, 'A');
    s1.setCourseGrade(1, 'B');
    s1.setCourseGrade(2, 'A');
    s1.setCourseGrade(3, 'A');
    s1.setCourseGrade(4, 'B');

    // display updated transcript
    s1.display();
}};

int main() {
    studentDemo();
    return 0;
}

