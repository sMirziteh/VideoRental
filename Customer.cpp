#include "Customer.h"

Customer::Customer() {}

Customer::Customer(const int &id, const string &fn, const string ln)
{
    customerID = id;
    firstName = fn;
    lastName = ln;
}

Customer::~Customer()
{
}

int Customer::getID() const
{
    return customerID;
}

ostream &operator<<(ostream &output, const Customer &C)
{
    output << C.customerID << " " << C.lastName << " " << C.firstName;
    return output;
}
