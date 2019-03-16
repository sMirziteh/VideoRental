#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <vector>
// #include "Trans.h"
using namespace std;

class Customer
{
  friend ostream &operator<<(ostream &, const Customer &);
  // friend Trans;

private:
  string firstName;
  string lastName;

public:
  Customer();
  Customer(const int &customerID, const string &firstName, const string lastName);
  ~Customer();

  int getID() const;
  // void showTransactions();
  // void addTransaction(Trans &t);

protected:
  int customerID;
  // vector<Trans> transactions;
};

#endif