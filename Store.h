#ifndef STORE_H
#define STORE_H
#include <string>
#include <vector>
#include "Video.h"
#include "Customer.h"
#include "hashtable.h"


using namespace std;

class Store
{
public:
	Store();
	~Store();
	void initializeInventory(ifstream&);
	void initializeCustomers(ifstream&);
	void processCommands(ifstream&);

	//TEST METHODS
	void printCust();
	void printInv();
	void printComm();
	//END

private:
	vector<Video*> dramaList;
	vector<Classical*> classicList;
	vector<Video*> funnyList;
	HashTable customerList;

	bool containsVideo(Video*);
	bool containsClassical(Classical*);
	bool updateStock(string, int);
};

#endif