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

	//TEST
	void printCust();
	void printInv();

private:
	void sort();
	vector<Drama*> dramaList;
	vector<Classical*> classicList;
	vector<Comedy*> funnyList;
	HashTable customerList;

	bool containsVideo(Video*);
	bool containsVideo(Classical*);
	bool updateStock(string, int);
	bool isBorrowed(int, Video*);
};

#endif