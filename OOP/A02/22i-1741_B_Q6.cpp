#include <iostream>
using namespace std;
class Account {
private:
    float balance;
public:
    Account(float initialBalance = 0.0)  // Constructor
	{
        balance = initialBalance;
    }
void deposit(float amount) //for adding money
	{
        balance += amount;
    }
    
bool withdraw(float amount) 
{
        if (balance < amount) 
		{
           cout<<"Insufficient balance. A penalty of $5 has been charged."<<endl;
           balance -= 5.0;
           return false;
        }
        balance -= amount;
        return true;
    }
    float inquire() 
	{
        return balance;
    }
};

int main() 
{
    Account myAccount(100.0);
    cout<<"Initial balance: $"<<myAccount.inquire()<<endl;
    
    myAccount.deposit(50.0);
    cout<<"Balance after deposit: $"<<myAccount.inquire()<<endl;
    
    myAccount.withdraw(75.0);
    cout<<"Balance after withdrawal: $"<<myAccount.inquire()<<endl;
    
    myAccount.withdraw(200.0);
    cout<<"Balance after second withdrawal: $"<<myAccount.inquire()<<endl;
    return 0;
}
