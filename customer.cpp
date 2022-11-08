#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Customer {
 
 public:
      // Constructor
      Customer () : cust_name(""), cust_address(""), acct_number(0)
      {
          
      }
      
      Customer(string name, string address, int number) : cust_name(name), cust_address(address), acct_number(number)
      {
      }

      // Accessor to get the account number
      int getAcctNumber() const { return acct_number; }

      // Accessor to get the customer name
      string getCustName() const { return cust_name; }

      // Accessor to get the customer  address
      string getCustAddress() const { return cust_address; }

      // Set a customer name and address
      void set(string name, string address);

      // Set a customer address
      void setAddress(string address) {  cust_address = address; }
      
      // Set a customer acct number
      void setAcct_number(int number) { acct_number = number; }

      // Get the next account number for the next customer.
      const unsigned long getNextAcctNumber() { return acct_number++; }

      // input operator
      friend Customer operator>> (istream& ins, Customer &cust);

      // output operator
      friend void operator<< (ostream& outs, const Customer &cust);

  private:
      string cust_name;                           // customer name

      unsigned long acct_number;                  // account number

      string cust_address;                        // customer address

};

const int MAX_CUSTOMERS = 20; // Change this to a smaller number to test.

// Declare the class variable nextAcctNum
//unsigned long Customer::nextAcctNum=10000;

// set the customer name and address
// @param name: the customer name
// @param address: the account address
void Customer::set(string name, string address)
{
    this->cust_name = name;
    this->cust_address = address;
}

// input operator reads customer as a name and address on two separate lines.
// name
// address1
Customer operator >>(istream& ins, Customer& cust)
{
     getline(ins, cust.cust_name);
     getline(ins, cust.cust_address);
     return cust;
}

// output operator
void operator <<( ostream& out, const Customer& cust)
{
     out << cust.acct_number << ": " << cust.cust_name << "\n" << cust.cust_address << endl;
}

int main()
{
    Customer custList[MAX_CUSTOMERS];
    ifstream infile;
    string filename;

    cout << "Enter the name of the file for input: ";
    cin >> filename;

    infile.open(filename);
    if (infile.fail()) {
        cout << "Error: failed to open file: " << filename;
        exit(1);
    }

    // Read in customer list.
    
    int size = 0;
    while (!infile.eof()) 
    {
        infile >> custList[size];
        custList[size].setAcct_number(10001 + size);
        if (size == MAX_CUSTOMERS)
            break;
        size++;
    }
    // Get customer address changes
    for (int i = 0;  i < size; i++)
    {   
        char answer;
        string input;
        cout << "Address change for  " << custList[i].getAcctNumber() << "? (y or n) : ";
        cin >> answer;
        if (answer == 'y') {
            cin.ignore();  // newline
            getline(cin, input);
            custList[i].setAddress(input);
            break;
        }
    }

    // Write out customer list.
    for (int i = 0; i < size - 1; i++)
    {
        cout << custList[i];
    }

    return 0;
}


