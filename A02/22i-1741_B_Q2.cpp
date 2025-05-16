#include <iostream>
using namespace std;
class Car 
{
private:
    float fuelEfficiency;  
    float fuelLevel; 

public:
    Car(float fuelEfficiency)   // Constructor
	{
        this->fuelEfficiency = fuelEfficiency;
        this->fuelLevel = 0;
    }
    void drive(float distance) 
	{
        float fuelUsed = distance / fuelEfficiency;
        fuelLevel -= fuelUsed;    //will reduce fuel level
    }
    float getFuelLevel() 
	{
        return fuelLevel;
    }
    void tank(float fuel)    
	{
        fuelLevel += fuel;
    }
};

int main() {
    //create a car object 
    Car myBeemer(29);
    cout << myBeemer.getFuelLevel() << endl;         //will display initial value which is 0
    myBeemer.tank(20);    //fill 20 
    cout << myBeemer.getFuelLevel() << endl;
    myBeemer.drive(100);
    cout << myBeemer.getFuelLevel() << endl;   //will display the current fuel level
    return 0;
}
