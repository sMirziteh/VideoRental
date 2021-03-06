#include "Video.h"
#include "Customer.h"
#include "Store.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream custFile("data4customers.txt");
	ifstream invFile("data4movies.txt");
	ifstream commFile("data4commands.txt");
	if (custFile && invFile && commFile)
	{
		cout << "Tests Started" << endl << endl;

		Store store;
		store.initializeCustomers(custFile);
		cout << "End initialization of customers" << endl;
		store.printCust();
		cout << endl;

		store.initializeInventory(invFile);
		cout << "End initialization of inventory" << endl;
		store.printInv();
	}

	/*
	Classical c('C', 10, "George Cukor", "Holiday", "Katherine", "Hepburn", 9, 1939);
	Drama d('D', 10, "Steven Spielberg", "Schindler's List", 1993);
	Comedy cd('F', 10, "Nora Ephron", "You've Got Mail", 1998);
	cout << c << endl;
	cout << d << endl;
	cout << cd << endl;

	Customer A(1111, "Mickey", "Mouse"), B(1000, "Minnie", "Mouse");
	cout << A << endl;
	cout << B << endl;

	B.addTransaction('B', 'D', cd);
	B.showTransactions();
	return 0;
	*/
}