#include <iostream>
using namespace std;
class Address {
private:
    int HouseNumber;
    int Street;
    int ApartmentNumber;
    char* City;
    char* State;
    int PostalCode;

public:
    Address(int houseNum, int street, char* city, char* state, int postalCode)   // Constructor without apartment number
	{
        HouseNumber = houseNum;
        Street = street;
        City = city;
        State = state;
        PostalCode = postalCode;
        ApartmentNumber = -1;     // will set default value 
    }
    Address(int houseNum, int street, int aptNum, char* city, char* state, int postalCode)    // Constructor with apartment number
	{
        HouseNumber = houseNum;
        Street = street;
        ApartmentNumber = aptNum;
        City = city;
        State = state;
        PostalCode = postalCode;
    }
void print() 
{
    cout<<HouseNumber<< " " <<Street<<endl;
    cout<<City<< ", "<<State <<" "<<PostalCode<<endl;
        if (ApartmentNumber != -1) 
		{ 
		    cout<<"Apt"<<ApartmentNumber<<endl;
        }
}

bool compareTo(Address a) 
{
        if (PostalCode < a.PostalCode) {
            return true;
        }
        return false;
}
};

int main() {
    Address address1(123, 1, "New York", "NY", 10001);
    Address address2(456, 2, 101, "Los Angeles", "CA", 90001);

    cout<<"Address 1:"<<endl;
    address1.print();
    cout<<endl;
    cout<<"Address 2:"<<endl;
    address2.print();
    cout<<endl;
    if (address1.compareTo(address2)) 
	{
        cout<<"Address 1 comes before Address 2."<<endl;
    } else 
	{
        cout<<"Address 2 comes before Address 1."<<endl;
    }
    return 0;
}
