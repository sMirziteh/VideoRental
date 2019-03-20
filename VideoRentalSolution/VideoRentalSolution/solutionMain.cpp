#include "Video.h"
#include "Customer.h"
#include "Store.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	
	ifstream custfile("data4customers.txt");
	ifstream invfile("data4movies.txt");
	ifstream commfile("data4commands.txt");
	if (custfile)
		cout << "cust file found" << endl;
	if (invfile)
		cout << "inv file found" << endl;
	if (commfile)
		cout << "comm file found" << endl;

	Store store;
	store.initializeCustomers(custfile);
	store.printCust();
	

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

	/*//Command Processing Testing
	Store Blockbuster;
	ifstream movies("data4movies.txt");
	if (!movies) {
		cout << "data4movies.txt could not be opened." << endl;
		return 1;
	}
	Blockbuster.initializeInventory(movies);

	ifstream customers("data4customers.txt");
	if (!customers) {
		cout << "data4customers.txt could not be opened." << endl;
		return 1;
	}
	Blockbuster.initializeCustomers(customers);

	ifstream commands("data4commands.txt");
	if (!commands) {
		cout << "data4commands.txt could not be opened." << endl;
		return 1;
	}
	Blockbuster.processCommands(commands);
	*/
}