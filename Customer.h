#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <vector>
#include "Video.h"
using namespace std;

class Customer
{
  friend ostream &operator<<(ostream &, const Customer &);

private:
  string firstName;
  string lastName;
  struct Trans
  {
    char txType;
    char mediaType;
    Video V;
  };

public:
  Customer();
  Customer(const int &customerID, const string &firstName, const string lastName);
  ~Customer();
  void addTransaction(const char &txType, const char &mediaType, const Video &);
  void showTransactions();
  int getID() const;

protected:
  int customerID;
  vector<Trans> transactions;
};

#endif