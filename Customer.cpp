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

void Customer::addTransaction(const char &ttype, const char &mtype,
                              const Video &vid)
{
    Trans tx;
    tx.txType = ttype;
    tx.mediaType = mtype;
    tx.V = vid;
    transactions.push_back(tx);
}

void Customer::showTransactions()
{
    for (int i = transactions.size() - 1; i >= 0; i--)
    {
        cout << transactions[i].txType << " " << customerID << " " << transactions[i].V.getTitle() << endl;
    }
}

ostream &
operator<<(ostream &output, const Customer &C)
{
    output << C.customerID << " " << C.lastName << " " << C.firstName;
    return output;
}
