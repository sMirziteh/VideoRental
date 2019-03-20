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
#include "Customer.h"
<<<<<<< HEAD
=======
#include <vector>
>>>>>>> Jordan

class HashTable
{
public:
	HashTable();
	~HashTable();
	void add(Customer *);
	Customer *get(int);
<<<<<<< HEAD
	void remove(Customer *);
=======
	void remove(int);
>>>>>>> Jordan
	int hash(int);
	bool isFull();

private:
<<<<<<< HEAD
	vector<Customer> objectList(10) = {nullptr};
=======
	vector<Customer *> customerList;
>>>>>>> Jordan
};

#endif // HASHTABLE_H