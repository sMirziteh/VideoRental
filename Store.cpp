#include "Store.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Store::Store() {
}

Store::~Store() {
	for (unsigned i = 0; i < dramaList.size(); i++) {
		delete dramaList[i];
		dramaList[i] = nullptr;
	}
	for (unsigned i = 0; i < classicList.size(); i++) {
		delete classicList[i];
		classicList[i] = nullptr;
	}
	for (unsigned i = 0; i < funnyList.size(); i++) {
		delete funnyList[i];
		funnyList[i] = nullptr;
	}
}

void Store::initializeInventory(ifstream& invFile)
{
	bool isAdded = false;
	char genre;
	int stock, month, year;
	string director, title, first, last;

	string line;
	//read each line from the file
	while (getline(invFile, line))
	{
		isAdded = false;
		stringstream stream(line);

		char garbageComma;	//for eleminating extra commas
		stream >> genre;
		stream >> garbageComma;

		if (genre == 'F' || genre == 'D' || genre == 'C')
		{
			stream >> stock;
			stream >> garbageComma;

			//split string on ',' character
			getline(stream, director, ',');
			//eleminate leading whitespace
			director = director.substr(1, director.length());

			//split string on ',' character
			getline(stream, title, ',');
			//eleminate leading whitespace
			title = title.substr(1, title.length());

			//if classical movie, get actor's first and last
			//name and the release month
			if (genre == 'C')
			{
				if (updateStock(title, stock))
				{
					isAdded = true;
					continue;
				}
				stream >> first;
				stream >> last;
				stream >> month;
			}
			//get the year from the stream
			stream >> year;
		}

		//Something other than F, D, or C was entered as the genre
		else
		{
			cout << "Invalid Genre" << endl;
			continue;	//continue to the next line of input
		}

		if (!isAdded)
		{
			//two Video pointers to avoid compiler errors for initialization
			//of currentVideo object
			if (genre == 'F')
			{
				Comedy *currentVideo = new Comedy(genre, stock, director, title, year);
				funnyList.push_back(currentVideo);
			}
			else if (genre == 'D')
			{
				Drama *currentVideo = new Drama(genre, stock, director, title, year);
				dramaList.push_back(currentVideo);
			}
			else
			{
				Classical *currentVideo = new Classical(genre, stock, director, title,
					first, last, month, year);
				classicList.push_back(currentVideo);
			}

		}
	}

	// Sort all movie vectors
	sort();
}

void Store::initializeCustomers(ifstream& custFile)
{
	int id;
	string first, last;

	while (custFile >> id >> first >> last)
	{
		Customer *cust = new Customer(id, first, last);
		customerList.add(cust);
	}
}

void Store::processCommands(ifstream& commFile)
{
	bool isAdded = false;
	char command;
	char genre;
	char videoType;
	int ID, month, year;
	string director, title, first, last;

	string line;
	//read each line from the file
	while (getline(commFile, line))
	{
		stringstream stream(line);

		// Get command character
		stream >> command;

		// If command is borrow or return
		if (command == 'B' || command == 'R')
		{
			stream >> ID;
			// If we get a nullptr, the customer doesn't exist
			if (customerList.get(ID) == nullptr) {
				cout << "Customer does not exist!" << endl;
				// Skip the rest of this iteration and go to next command.
				continue;
			}

			stream >> videoType;
			stream >> genre;
			// If we get any video type other than D then incorrect input
			if (videoType != 'D') {
				cout << "Invalid Video Type!" << endl;
				continue;
			}
			else if (genre == 'F' || genre == 'D' || genre == 'C')
			{
				Video *temp;
				// If classical movie format is month year first last
				if (genre == 'C')
				{

					stream >> month;
					stream >> year;
					stream >> first;
					stream >> last;
					Classical *cTemp = new Classical();
					cTemp->setGenre('C');
					cTemp->setMajActFN(first);
					cTemp->setMajActLN(last);
					cTemp->setReleaseMonth(month);
					cTemp->setReleaseYear(year);
					temp = cTemp;
					Classical *clasTemp = cTemp;
					clasTemp = cTemp;

					// If video is found, update the stock of the video
					if (containsVideo(clasTemp)) {
						if (command == 'B') {
							if (!updateStock(temp->getTitle(), -1))
								cout << "No available copies" << endl;
						}
						else if (command == 'R') {
							if (!Store::isBorrowed(ID, temp))
								cout << "Movie wasn't borrowed" << endl;
							else
								updateStock(temp->getTitle(), 1);
						}
					}
					else {
						cout << "Movie does not exist!" << endl;
					}


				}

				// If drama movie format is director, movie,
				else if (genre == 'D')
				{
					//split string on ',' character
					getline(stream, director, ',');
					//eleminate leading whitespace
					director = director.substr(1, director.length());
					//split string on ',' character
					getline(stream, title, ',');
					//eleminate leading whitespace
					title = title.substr(1, title.length());
					Drama *dTemp = new Drama();
					dTemp->setGenre('D');
					dTemp->setDirector(director);
					dTemp->setTitle(title);
					temp = dTemp;
				}
				// If funny movie format is Title, year
				else {
					//split string on ',' character
					getline(stream, title, ',');
					//eleminate leading whitespace
					title = title.substr(1, title.length());
					stream >> year;
					Comedy *fTemp = new Comedy();
					fTemp->setReleaseYear(year);
					fTemp->setTitle(title);
					temp = fTemp;
				}

				// If video is found, update the stock of the video
				if (containsVideo(temp)) {
					if (command == 'B') {
						if (!updateStock(temp->getTitle(), -1))
							cout << "No available copies" << endl;
					}
					else if (command == 'R') {
						if (!Store::isBorrowed(ID, temp))
							cout << "Movie wasn't borrowed" << endl;
						else
							updateStock(temp->getTitle(), 1);
					}
				}
				else {
					cout << "Movie does not exist!" << endl;
				}
			}

			//Something other than F, D, or C was entered as the genre
			else
			{
				cout << "Invalid Genre" << endl;
				continue;	//continue to the next line of input
			}

		}

		// If command is inventory
		else if (command == 'I') {
			// Output comedies, dramas, and classics
			for (unsigned i = 0; i < funnyList.size(); i++) {
				cout << *funnyList[i] << endl;
			}
			for (unsigned i = 0; i < dramaList.size(); i++) {
				cout << *dramaList[i] << endl;
			}
			for (unsigned i = 0; i < classicList.size(); i++) {
				cout << *classicList[i] << endl;
			}
		}

		// If command is history
		else if (command == 'H') {
			stream >> ID;
			Customer *temp = customerList.get(ID);
			// If we get a nullptr, the customer doesn't exist
			if (temp == nullptr) {
				cout << "Customer does not exist!" << endl;
				// Skip the rest of this iteration and go to next command.
				continue;
			}
			temp->showTransactions();
		}

		//Something other than B,R,H,I
		else
		{
			cout << "Invalid Command" << endl;
			continue;	//continue to the next line of input
		}
	}
}

bool Store::updateStock(string curTitle, int curStock)
{
	for (int i = 0; i < (int)classicList.size(); i++)
	{
		Video *temp = classicList[i];
		if (temp->getTitle() == curTitle)
		{
			if (temp->getStock() == 0)
				return false;
			int stock = temp->getStock() + curStock;
			temp->setStock(stock);
			return true;
		}
	}
	return false;
}

bool Store::containsVideo(Video *other)
{
	for (int i = 0; i < (int)dramaList.size(); i++)
	{
		Video *temp = dramaList[i];
		if ((other->getDirector() == temp->getDirector())
			|| (other->getTitle() == temp->getTitle()))
			return true;
	}
	for (int i = 0; i < (int)funnyList.size(); i++)
	{
		Video *temp = funnyList[i];
		if ((other->getDirector() == temp->getDirector())
			|| (other->getTitle() == temp->getTitle()))
			return true;
	}
	return false;
}

bool Store::containsVideo(Classical *other)
{
	for (int i = 0; i < (int)classicList.size(); i++)
	{
		Classical *temp = classicList[i];
		if (other->getMajActFN() == temp->getMajActFN())
			return true;
	}
	return false;
}

void Store::sort() {
	// Using Bubble Sort

	// Classics sorted by release date then major actor
	unsigned i, j;
	bool swapped;

	// Iterate through the vector until sorted
	for (i = 0; i < classicList.size() - 1; i++)
	{
		swapped = false;

		// Iterate through vector to do the comparisons
		for (j = 0; j < classicList.size() - i - 1; j++)
		{
			if (classicList[i] > classicList[j + 1])
			{
				swap(classicList[j], classicList[j + 1]);
				swapped = true;
			}
		}

		// If no swap occurs during inner loop we know vector is sorted.
		if (swapped == false)
			break;
	}
	// Drama sorted by director then title
	for (i = 0; i < classicList.size() - 1; i++)
	{
		swapped = false;
		for (j = 0; j < classicList.size() - i - 1; j++)
		{
			if (classicList[i] > classicList[j + 1])
			{
				swap(classicList[j], classicList[j + 1]);
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break 
		if (swapped == false)
			break;
	}
	// Funnies sorted by title then year
	for (i = 0; i < classicList.size() - 1; i++)
	{
		swapped = false;
		for (j = 0; j < classicList.size() - i - 1; j++)
		{
			if (classicList[i] > classicList[j + 1])
			{
				swap(classicList[j], classicList[j + 1]);
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break 
		if (swapped == false)
			break;
	}
}

//checks to see if the given video has been borrowed by the
//given customer, represented by their ID
bool Store::isBorrowed(int ID, Video *vid)
{
	Customer *cust = customerList.get(ID);
	return cust->Customer::isBorrowed(vid);
}

//TEST
void Store::printCust()
{
	customerList.print();
}
void Store::printInv()
{
	for (int i = 0; i < (int)funnyList.size(); i++)
	{
		cout << *funnyList[i] << endl;
	}
	for (int i = 0; i < (int)dramaList.size(); i++)
	{
		cout << *dramaList[i] << endl;
	}
	for (int i = 0; i < (int)classicList.size(); i++)
	{
		cout << *classicList[i] << endl;
	}
}