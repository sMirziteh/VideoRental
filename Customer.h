//---------------------------------Customer.h---------------------------------
// Shelby Mirziteh CSS_343 C
// Group: Jordan Lawson, Shelby Mirziteh, Kier Fisher
// 03/14/2019
// 03/20/2019
// -------------------------------------------------------------------------
// Customer class for video rental program.
// tracks transactions for each customer
// -------------------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <vector>
#include "Video.h"
using namespace std;

class Customer
{
  //overloaded output operator for customer
  friend ostream &operator<<(ostream &, const Customer &);

private:
  string firstName; //customer first name
  string lastName;  //customer last name
  //transaction for customer
  struct Trans
  {
    char txType;    //transaction type (B || R)
    char mediaType; //media type (D)
    Video V;        //video being borrowed or returned
  };

public:
  //constructors
  Customer();
  Customer(const int &customerID, const string &firstName, const string lastName);
  //destructor
  ~Customer();
  //adds transaction to Transaction data structure
  void addTransaction(const char &txType, const char &mediaType, const Video &);
  //displays all customer transactions
  void showTransactions();
  //retrieves customer ID
  int getID() const;
  //checks to see if the video has been borrowed
  bool isBorrowed(Video*);

protected:
  int customerID;             //4-digit customer ID
  vector<Trans> transactions; //data structure for transactions
};

#endif