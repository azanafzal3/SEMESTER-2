#include <iostream>
#include <cstring>
using namespace std;
class FlightInfo {             //create a class of flight info
private:
    int flightNumber;
    char* destination;
    float distance;
    float fuel;

public:
    FlightInfo()     // Constructor
	{
        destination = nullptr;
    }
    ~FlightInfo()    // Destructor to deallocate the memory
	{
        delete[] destination;
    }
    void calFuel() {
        if (distance <= 1000)     //will compare the value of distance
		{
            fuel = 500;
        }
        else if (distance <= 2000) 
		{
            fuel = 1100;
        }
        else 
		{
            fuel = 2200;
        }
    }
void feedInfo() 
{
    cout << "Enter flight number: ";
    cin >> flightNumber;
    cout << "Enter destination: ";
    char dest[100];
    cin.ignore(); // ignore newline character from previous input
    cin.getline(dest, 100);
    destination = new char[strlen(dest) + 1];        // will allocate memory for destination and copy input into it
    strcpy(destination, dest);
    cout << "Enter distance: ";
    cin >> distance;
    calFuel();
    }
void showInfo() 
    {
    cout<< "Flight Number: "<<flightNumber<<endl;
    cout<< "Destination: "<<destination<<endl;
    cout<< "Distance: "<<distance<<endl;
    cout<< "Fuel: " <<fuel<<endl;
    }
    float getFuel() 
	{
        return fuel;
    }
};

int main() {
    FlightInfo myFlight;   //new object of myFlight
    myFlight.feedInfo();
    myFlight.showInfo();      //will display all flight info
    float currentFuel = myFlight.getFuel();    //will get value of current fuel
    cout << "Current fuel: " << currentFuel << endl;
    return 0;
}

