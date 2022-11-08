//DISPLAY 10.6 Class with Constructors 
//Program to demonstrate the class BankAccount.
#include <iostream>
using namespace std;

#pragma once

//Class for a bank account:
class BankAccount
{
public:
    BankAccount(int dollars, int cents);
    //Initializes the account balance to $dollars.cents.

    BankAccount(int dollars);
    //Initializes the account balance to $dollars.00.

    BankAccount( );
    //Initializes the account balance to $0.00.

    double get_balance( ) const;
    //Returns the current account balance.

    void set_balance(double balance);
    //Sets the current account balance to parameter amount

    void output(ostream& outs) const;
    //Precondition: If outs is a file output stream, then
    //outs has already been connected to a file.
    //Postcondition: Account balance has been written to the stream outs.

	void input(istream& ins);
	// Input the balance for the BankAccount

    void deposit(int dollars, int cents);
    // Precondition: dollars and cents must be greater or equal to 0.
    // Postcondition: increase the balance by the dollars and cents
    
    void withdraw(int dollars, int cents);
    // Precondition: dollars and cents must be greater or equal to 0.
    // Dollars and cents be less than or equal to balance.
    // Postcondition: increase the balance by the dollars and cents
private:
	double balance;

};

