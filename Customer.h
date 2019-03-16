#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Customer
{
    friend ostream &operator<<(ostream &, const Customer &);

  private:
    int customerID;
    string firstName;
    string lastName;
    // vector<Trans> transactions;

  public:
    Customer();
    Customer(const int &customerID, const string &firstName, const string lastName);
    ~Customer();

    int getID();
    // void showTransactions();
};

#endif