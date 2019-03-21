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
#include <vector>

class HashTable
{
  public:
	HashTable();
	~HashTable();
	void add(Customer *);
	Customer *get(int);
	void remove(int);
	int hash(int);
	bool isFull();

	//TEST
	void print();

  private:
	vector<Customer *> customerList;
};

#endif // HASHTABLE_H