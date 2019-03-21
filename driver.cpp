//---------------------------------Driver.cpp---------------------------------
// Group: Jordan Lawson, Shelby Mirziteh, Kier Fisher
// 03/14/2019
// 03/20/2019
// -------------------------------------------------------------------------
// implements Video Rental inventory system
// -------------------------------------------------------------------------

#include "Video.h"
#include "Customer.h"
#include "Store.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "Welcome to Blockbuster inventory system!" << endl
         << endl;
    Store Blockbuster;
    ifstream movies("data4movies.txt");
    if (!movies)
    {
        cout << "data4movies.txt could not be opened." << endl
             << endl;
        return 1;
    }
    else
        cout << "Opening data4movies.txt" << endl;
    Blockbuster.initializeInventory(movies);

    ifstream customers("data4customers.txt");
    if (!customers)
    {
        cout << "data4customers.txt could not be opened." << endl
             << endl;
        return 1;
    }
    else
        cout << "Opening data4customers.txt" << endl
             << endl;
    Blockbuster.initializeCustomers(customers);

    ifstream commands("data4commands.txt");
    if (!commands)
    {
        cout << "data4commands.txt could not be opened." << endl
             << endl;
        return 1;
    }
    else
        cout << "Opening data4commands.txt" << endl
             << endl;
    Blockbuster.processCommands(commands);

    return 0;
}