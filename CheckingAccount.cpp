//Implementation of the class CheckingAccount.
#include <iostream>
#include <cmath>
// To Do: include necessary header files
#include "CheckingAccount.h"
using namespace std;





// To Do: Please write comments and code to implement CheckingAccount here

/* 
Constructor for CheckingAccount takes dollars, cents and fee
*/
CheckingAccount::CheckingAccount(int dollars, int cents, double fee) : BankAccount(dollars, cents), check_fee(fee)
{
    if (fee < 0)
    {
        cout << "Illegal value for check fee.\n";
        exit(1);
    }
    
}

/*
Constructor for CheckingAccount takes dollars and fee
*/
CheckingAccount::CheckingAccount(int dollars, double fee) : BankAccount(dollars), check_fee(fee)
{
    if (fee < 0)
    {
        cout << "Illegal value for check fee.\n";
        exit(1);
    }
}

/*
Default contructor for CheckingAccount takes no parameters

*/
CheckingAccount::CheckingAccount() : BankAccount(), check_fee(0.0)
{
    //Body intentionally empty
}

/*
Public member function: get_fee (accessor)
Returns the check fee.
*/
double CheckingAccount::get_fee () const
{
    return check_fee;
}

/*
Public member function: output
Precondition: If outs is a file output stream, then outs has already been connected to a file.
Postcondition: balance and check fee have been written to the stream outs.
*/
void CheckingAccount::output(ostream& outs) const
{
    BankAccount::output(outs);
    outs << "Check fee: $" << get_fee() << endl;
}

/*
Public member function: input
Precondition: If ins is a file input stream, then ins has already been connected to a file.
Postcondition: balance and check fee have been read from the stream ins
*/
void CheckingAccount::input(istream& ins)
{
    BankAccount::input(ins);
    ins >> check_fee;
}

/*
Pubic member function: check
Behaves like withdraw but charges the check fee too.
Precondition: dollars and cents must be greater or equal to 0. Dollars and cents be less than or equal to balance.
Postcondition: increase the balance by the dollars and cents plus the fee. 
*/
void CheckingAccount::check(int dollars, int cents)
{
    double amount = dollars + .01*cents;
    double b = get_balance();
    if (dollars >= 0 && cents >= 0 && amount <= get_balance())
    {
        b -= amount;
        b -= check_fee;
        set_balance(b);
    }
    else {
        cout << "Illegal values for money must be greater than or equal 0 ";
        cout << "and less than or equal to the balance.\n";
    }
}
