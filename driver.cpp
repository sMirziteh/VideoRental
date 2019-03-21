//---------------------------------DRIVER---------------------------------
// Group: Jordan Lawson, Shelby Mirziteh, Kier Fisher
// 03/14/2019
// 03/20/2019
// -------------------------------------------------------------------------
// Main driver for video rental system
// -------------------------------------------------------------------------

#include "Video.h"
#include "Customer.h"
#include "Store.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "Welcome to Blockbuster video!" << endl;
    cout << "This system tracks inventory and customer transaction history" << endl;
    //create store
    Store Blockbuster;

    //read video list file
    ifstream movies("data4movies.txt");
    if (!movies)
    {
        cout << "data4movies.txt could not be opened." << endl;
        return 1;
    }

    //set inventory for videos
    Blockbuster.initializeInventory(movies);

    //read customer list file
    ifstream customers("data4customers.txt");
    if (!customers)
    {
        cout << "data4customers.txt could not be opened." << endl;
        return 1;
    }

    //set customer accounts
    Blockbuster.initializeCustomers(customers);

    //read command file
    ifstream commands("data4commands.txt");
    if (!commands)
    {
        cout << "data4commands.txt could not be opened." << endl;
        return 1;
    }

    //execute commands
    Blockbuster.processCommands(commands);

    return 0;
}