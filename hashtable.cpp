// ------------------------------------------------ HashTable.cpp -------------------------------------------------------
// Jordan Lawson CSS343
// 3/15/19
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Assignment 4's Hash Table class
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions.
// Assumptions: Only dealing with customer objects
// --------------------------------------------------------------------------------------------------------------------

#include "hashtable.h"
HashTable::HashTable() {
	// Default list size will be 10
	customerList.resize(10);
	for (int i = 0; i < (int)customerList.size(); i++) {
		delete customerList[i];
		customerList[i] = nullptr;
	}
}

HashTable::~HashTable() {
	for (int i = 0; i < (int)customerList.size(); i++) {
		delete customerList[i];
		customerList[i] = nullptr;
	}
}

// Get object from hashtable
void HashTable::add(Customer* newCustomer) {

	int location = hash(newCustomer->getID());

	// Increment location until an empty spot is found.
	while (customerList[location] != nullptr) {
		// Premptively check if the vector is full, if so, add new customer to the end and return, ending method early
		if (isFull()) {
			customerList.push_back(newCustomer);
			return;
		}
		location++;
		// Start at the beginning of the vector if we've reached the end without finding a spot.
		if (location >= (int)customerList.size()) {
			location = 0;
		}
	}
	customerList[location] = newCustomer;
}

//gets the customer using the given ID
Customer* HashTable::get(int ID) {
	int location = hash(ID);

	for (int i = location; i < (int)customerList.size(); i++) {
		if (customerList[i]) {
			if (customerList[i]->getID() == ID) {
				return customerList[i];
			}
		}
	}

	for (int i = 0; i < location; i++) {
		if (customerList[i]) {
			if (customerList[i]->getID() == ID) {
				return customerList[i];
			}
		}
	}

	return nullptr;
}

//removes the given customer from the vector
void HashTable::remove(int ID) {
	int location = hash(ID);

	// Increment location until our item is found
	while (customerList[location]->getID() != ID) {
		location++;
		// Start at the beginning of the vector if we've reached the end without finding our item.
		if (location > (int)customerList.size()) {
			location = 0;
		}
		// If location == the item's hash, then we know we've already fully traversed the vector so break.
		else if (location == hash(ID)) {
			return;
		}
	}

	// Remove found customer.
	customerList[location] = nullptr;
}

int HashTable::hash(int ID) {
	return ID % 10;
}

//returns whether the vector is full or not
bool HashTable::isFull() {
	for (int i = 0; i < (int)customerList.size(); i++) {
		if (customerList[i] == nullptr) {
			return false;
		}
	}
	return true;
}