#include "Customer.h"
// #include "Trans.h"

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

// void Customer::addTransaction(Trans &t)
// {
//     transactions.push_back(t);
// }

// void Customer::showTransactions()
// {
//     for (int i = 0; i < transactions.size(); i++)
//     {
//         cout << transactions[i] << endl;
//     }
// }

ostream &operator<<(ostream &output, const Customer &C)
{
    output << C.customerID << " " << C.lastName << " " << C.firstName;
    return output;
}
