#include "Video.h"
#include "Customer.h"
#include "Store.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	Store Blockbuster;

	//cout << "Opening inv" << endl;
	ifstream movies("data4movies.txt");
	if (!movies)
	{
		cout << "data4movies.txt could not be opened." << endl;
		return 1;
	}
	Blockbuster.initializeInventory(movies);
	//Blockbuster.printInv();

	//cout << "Opening cust" << endl;
	ifstream customers("data4customers.txt");
	if (!customers)
	{
		cout << "data4customers.txt could not be opened." << endl;
		return 1;
	}
	Blockbuster.initializeCustomers(customers);

	//cout << "Opening commands" << endl;
	ifstream commands("data4commands.txt");
	if (!commands)
	{
		cout << "data4commands.txt could not be opened." << endl;
		return 1;
	}
	Blockbuster.processCommands(commands);
	
	return 0;
}