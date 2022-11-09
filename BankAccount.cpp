//DISPLAY 10.6 Class with Constructors 
//Program to demonstrate the class BankAccount.
#include <iostream>
#include "BankAccount.h"
using namespace std;


/* 
Constructor for BankAccount takes dollars and cents 
Initializes the account balance to $dollars.cents
*/
BankAccount::BankAccount(int dollars, int cents)
{
    if ((dollars < 0) || (cents < 0))
    {
        cout << "Illegal values for money.\n";
        exit(1); // throw exception;
    }
    balance = dollars + 0.01*cents;
}

/*
Constructor for BankAccount takes dollars
Initializes the account balance to $dollars.00 
*/
BankAccount::BankAccount(int dollars)
{
    if (dollars < 0) 
    {
        cout << "Illegal values for money.\n";
        exit(1);
    }
    balance = dollars;
}

/*
Default Constructor for BankAccount takes no parameters
Initializes the account balance to $0.00 
*/
BankAccount::BankAccount( ) : balance(0)
{
   //Body intentionally empty
}

/*
Public member function: deposit
Precondition: dollars and cents must be greater or equal to 0.
Postcondition: increase the balance by the dollars and cents
*/
void BankAccount::deposit(int dollars, int cents)
{
    if (dollars >= 0 && cents >= 0)
    {
        balance += dollars + 0.01*cents;
    }
    else {
        cout << "Illegal values for money must be greater than or equal 0\n";
    }
}

/*
Public member function: withdraw
Precondition: dollars and cents must be greater or equal to 0. Dollars and cents be less than or equal to balance.
Postcondition: increase the balance by the dollars and cents
*/
void BankAccount::withdraw(int dollars, int cents)
{
    double amount = dollars + .01*cents;
    if (dollars >= 0 && cents >= 0 && amount <= get_balance())
    {
        balance -= amount;
    }
    else {
        cout << "Illegal values for money must be greater than or equal 0 ";
        cout << "and less than or equal to the balance.\n";
    }
}

/*
Public member function: output
Precondition: If outs is a file output stream, then outs has already been connected to a file.
Postcondition: Account balance has been written to the stream outs.
*/
void BankAccount::output(ostream& outs) const
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account Balance: $" << get_balance() << endl;
}

/*
Public member function: input
Input the balance for the BankAccount
*/
void BankAccount::input(istream& ins)
{
	ins >> balance;
}

/*
Public member function: get_balance (accessor)
Returns the current account balance.
*/
double BankAccount::get_balance() const
{
    return balance;
}

/*
Public member function: set_balance (mutator)
Sets the current account balance to parameter amount
*/
void BankAccount::set_balance(double amount)
{
    balance = amount;
}

