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

}

HashTable::~HashTable() {
	for (int i = 0; i < objectList.size(); i++) {
		delete objectList[i];
		objectList[i] = nullptr;
	}
}

// Get object from hashtable
void HashTable::add(Customer* newItem) {

	int location = hash(newItem.memberID);

	// Increment location until an empty spot is found.
	while (objectList[location] != nullptr) {
		// Premptively check if the vector is full, if so, add new customer to the end and return, ending method early
		if (isFull) {
			objectList.push_back(newItem);
			return;
		}
		location++;
		// Start at the beginning of the vector if we've reached the end without finding a spot.
		if (location > objectList.size()) {
			location = 0;
		}
	}
	objectList[location] = newItem;
}


Customer* HashTable::get(int ID) {
	int location = hash(ID);

	// Increment location until our item is found
	while (objectList[location].memberID != ID) {
		location++;
		// Start at the beginning of the vector if we've reached the end without finding our item.
		if (location > objectList.size()) {
			location = 0;
		}
		// If location == the item's hash, then we know we've already fully traversed the vector so break.
		else if (location == hash(ID)) {
			return newItem;
		}
	}

	return objectList[location];
}

int HashTable::hash(int ID) {
	return ID % 10;
}

bool HashTable::isFull() {
	for (int i = 0; i < objectList.size(); i++) {
		if (objectList[i] == nullptr) {
			return false;
		}
	}
	return true;
}