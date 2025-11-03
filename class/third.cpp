#include <iostream>
using namespace std;

class BankAccount
{
public:
    double balance = 0.0;

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "Your balance is too low to withdraw" << endl;
        }
    }
};

int main()
{

    BankAccount JadinAcc;

    JadinAcc.deposit(5.15);

    cout << "Your account balance is: " << JadinAcc.balance << endl;

    JadinAcc.withdraw(4.10);

    cout << "Your *new* account balance is: " << JadinAcc.balance << endl;

    return 0;
}