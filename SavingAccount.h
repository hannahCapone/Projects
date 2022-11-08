//DISPLAY 10.6 Class with Constructors 
//Program to demonstrate the class SavingAccount.
#include <iostream>
#include "BankAccount.h"
using namespace std;

#pragma once

//Class for a Saving account:
class SavingAccount : public BankAccount
{
public:
    SavingAccount(int dollars, int cents, double rate);
    //Initializes the account balance to $dollars.cents and
    //initializes the interest rate to rate percent.

    SavingAccount(int dollars, double rate);
    //Initializes the account balance to $dollars.00 and
    //initializes the interest rate to rate percent.

    SavingAccount( );
    //Initializes the account balance to $0.00 and the interest rate to 0.0%.

    void update( );
    //Postcondition: One year of simple interest has been added to the account
    //balance.

    double get_rate( ) const;
    //Returns the current account interest rate as a percentage.

    void output(ostream& outs) const;
    //Precondition: If outs is a file output stream, then
    //outs has already been connected to a file.
    //Postcondition: Account balance and interest rate
    //have been written to the stream outs.

    void input(istream& ins);
    //Precondition: If ins is a file input stream, then
    //ins has already been connected to a file.
    //Postcondition: Account balance and interest rate
    //have been read from the stream ins.

private:
    double interest_rate;//expressed as a percent,

protected:
    double fraction(double percent);
    //Converts a percentage to a fraction. For example, fraction(50.3)
    //returns 0.503.

};


