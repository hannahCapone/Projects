//DISPLAY 10.6 Class with Constructors 
//Program to demonstrate the class SavingAccount.
#include <iostream>
#include "SavingAccount.h"
using namespace std;

// Please write comments here

/* 
Constructor for SavingAccount takes dollars, cents and rate
Initializes the account balance to $dollars.cents and
initializes the interest rate to rate percent.
*/
SavingAccount::SavingAccount(int dollars, int cents, double rate) : BankAccount(dollars, cents), interest_rate(rate)
{
    if (rate < 0)
    {
        cout << "Illegal values for interest rate.\n";
        exit(1); // throw exception;
    }
}

/* 
Constructor for SavingAccount takes dollars and rate 
Initializes the account balance to $dollars.00 and
initializes the interest rate to rate percent.
*/
SavingAccount::SavingAccount(int dollars, double rate) : BankAccount(dollars), interest_rate(rate)
{
    if (rate < 0)
    {
        cout << "Illegal value for interest rate.\n";
        exit(1);
    }
}

/* 
Default Constructor for SavingAccount takes no parameters  
Initializes the account balance to $0.00 and the interest rate to 0.0%.
*/
SavingAccount::SavingAccount( ) : BankAccount(), interest_rate(0.0)
{
   //Body intentionally empty
}

/*
Public member function: update
Updates the balance with the interest_rate.
Postcondition: One year of simple interest has been added to the account
balance.
*/
void SavingAccount::update() 
{
    double amount = get_balance();
	amount = amount + fraction(interest_rate)*amount;
	set_balance(amount);
}

/* 
Public member function: output
Precondition: If outs is a file output stream, then outs has already been connected to a file.
Postcondition: Account balance and interest rate have been written to the stream outs.
*/
void SavingAccount::output(ostream& outs) const
{
	BankAccount::output(outs);
    outs << "Interest rate: " << get_rate() << "%" << endl;
}

/* 
Public member function: input
Precondition: If ins is a file input stream, then ins has already been connected to a file.
Postcondition: Account balance and interest rate have been read from the stream ins.
*/
void SavingAccount::input(istream& ins)
{
	BankAccount::input(ins);
    ins >> interest_rate;
}

/*
Public member function: get_rate (accessor)
Returns the current account interest rate as a percentage.
*/
double SavingAccount::get_rate() const
{
    return interest_rate;
}

/* 
Protected member function: fraction
Converts a percentage to a fraction. For example, fraction(50.3) returns 0.503.
*/
double SavingAccount::fraction(double percent)
{
    return percent/100.0;
}

