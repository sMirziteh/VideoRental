// ------------------------------------------------ HashTable.h -------------------------------------------------------
// Jordan Lawson CSS343
// 3/15/19
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Assignment 4's Hash Table class
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions.
// Assumptions: 
// --------------------------------------------------------------------------------------------------------------------

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "customer.h"

class HashTable {
public:
	HashTable();
	~HashTable();
	void add(Customer*);
	Customer* get(int);
	void remove(Customer*);
	int hash(int);
	bool isFull();

private:
	vector<Customer> objectList(10) = { nullptr };
};


#endif // HASHTABLE_H