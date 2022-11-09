// Declaration of the class CheckingAccount.

#include <iostream>
#include "BankAccount.h"
using namespace std;

#pragma once

//Class for a CheckingAccount which is derived from BankAccount.
class CheckingAccount : public BankAccount
{
public:
    //Initializes the account balance to $dollars.cents and the check fee to fee.
    CheckingAccount(int dollars, int cents, double fee);
    
    //Initializes the account balance to $dollars.00 and check fee to the fee
    CheckingAccount( int dollars, double fee);

    //Initializes the account balance to $0.00 and the check fee to $0.00.
    CheckingAccount( );
    
    //Returns the check fee.
    double get_fee( ) const;

    void output(ostream& outs) const;

    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.
    //Postcondition: balance and check fee have been written to the stream outs.
    
    void input(istream& ins);

    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.
    //Postcondition: balance and check fee have been read from the stream ins.

    void check(int dollars, int cents);

    // Precondition: dollars and cents must be greater or equal to 0.
    // Dollars and cents be less than or equal to balance.
    // Postcondition: increase the balance by the dollars and cents
    // plus the fee. 

private:
    double check_fee;

};

