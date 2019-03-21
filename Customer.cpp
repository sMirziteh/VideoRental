//---------------------------------Customer.cpp---------------------------------
// Shelby Mirziteh CSS_343 C
// Group: Jordan Lawson, Shelby Mirziteh, Kier Fisher
// 03/14/2019
// 03/20/2019
// -------------------------------------------------------------------------
// Implements Customer class for video rental program.
// tracks transactions for each customer
// -------------------------------------------------------------------------

#include "Customer.h"

// ------------------------------default constr------------------------
// Constructor
// Description: instantiates new empty Customer object
// -------------------------------------------------------------------
Customer::Customer() {}

// ------------------------------ constrstructor------------------------
// Constructor
// Description: instantiates new customer with given values
// -------------------------------------------------------------------
Customer::Customer(const int &id, const string &fn, const string ln)
{
	customerID = id;
	firstName = fn;
	lastName = ln;
}

// ------------------------------destructor------------------------
// Destructor for Customer
// -------------------------------------------------------------------
Customer::~Customer()
{
}

// ------------------------------getID---------------------------------
// retrives customer ID
// -------------------------------------------------------------------
int Customer::getID() const
{
	return customerID;
}

// ------------------------------addTransaction------------------------
// adds transaction struct to transaction data structure with
// given attributes
// -------------------------------------------------------------------
void Customer::addTransaction(const char &ttype, const char &mtype,
	const Video &vid, const Classical &clas)
{
	Trans tx;
	tx.txType = ttype;
	tx.mediaType = mtype;
	
	if (clas.getGenre() == 'C')
	{
		tx.C.setMajActFN(clas.getMajActFN());
		tx.C.setMajActLN(clas.getMajActLN());
		tx.C.setReleaseMonth(clas.getReleaseMonth());
		tx.C.setReleaseYear(clas.getReleaseYear());
		tx.C.setGenre('C');
	}
	else
		tx.V = vid;

	transactions.push_back(tx);
}

// ------------------------------showTransactions------------------------
// shows all transactions in Trans data structure
// -------------------------------------------------------------------
void Customer::showTransactions()
{
	for (int i = (int)(transactions.size() - 1); i >= 0; i--)
	{
		if (transactions[i].C.getGenre() == 'C')
		{
			cout << transactions[i].txType << " " << customerID << " " << transactions[i].C.getReleaseMonth()
				<< " " << transactions[i].C.getReleaseYear() << " " << transactions[i].C.getMajActFN() << " "
				<< transactions[i].C .getMajActLN() << endl;
		}
		else
			cout << transactions[i].txType << " " << customerID << " " << transactions[i].V.getTitle() << endl;
	}
	cout << "End Transaction History" << endl;
}

// ----------------------------overloaded << ------------------------
// overloaded output for Customer object
// -------------------------------------------------------------------
ostream &
operator<<(ostream &output, const Customer &C)
{
	output << C.customerID << " " << C.lastName << " " << C.firstName;
	return output;
}

//uses a reverse iterator to loop through the transactions vector starting 
//from the end.
bool Customer::isBorrowed(Video *vid)
{
	vector<Trans>::reverse_iterator i = transactions.rbegin();
	for (; i != transactions.rend(); ++i)
	{
		//if movie has been borrowed and returned in the past, return false
		//i.e. movie Borrowed, movie Returned should return false
		if (i->V.getTitle() == vid->getTitle() &&
			i->txType == 'R')
		{
			return false;
		}
		//if movie has been borrowed and not returned, return true
		else if (i->V.getTitle() == vid->getTitle() &&
			i->txType == 'B')
		{
			return true;
		}
	}
	return false;
}