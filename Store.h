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

private:
	vector<Video*> dramaList;
	vector<Video*> classicList;
	vector<Video*> funnyList;
	HashTable customerList;

	bool containsVideo(Video*);
	bool updateStock(string, int);
};

#endif