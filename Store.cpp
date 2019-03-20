#include "Store.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Store::Store()
{
}

Store::~Store()
{
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
			Video *vid;
			if (genre == 'F')
			{
				Video *currentVideo = new Comedy(genre, stock, director, title, year);
				vid = currentVideo;
				funnyList.push_back(vid);
			}
			else if (genre == 'D')
			{
				Video *currentVideo = new Drama(genre, stock, director, title, year);
				vid = currentVideo;
				dramaList.push_back(vid);
			}
			else
			{
				Video *currentVideo = new Classical(genre, stock, director, title,
					first, last, month, year);
				vid = currentVideo;
				classicList.push_back(vid);
			}

		}
	}

	// Sort all movie vectors
	sort();
}

void Store::initializeCustomers(ifstream& custFile)
{
	int id;
	string first, last, line;

	while (getline(custFile, line))
	{
		stringstream stream(line);
		stream >> id;
		stream >> first;
		stream >> last;
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
		isAdded = false;
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
			// If we get any video type other than D then incorrect input
			if (videoType != 'D') {
				cout << "Invalid Video Type!" << endl;
				continue;
			}

			else if (genre == 'F' || genre == 'D' || genre == 'C')
			{

				// If classical movie format is month year first last
				if (genre == 'C')
				{
					stream >> month;
					stream >> year;
					stream >> first;
					stream >> last;
					Classical temp;
					temp.setGenre('C');
					temp.setMajActFN(first);
					temp.setMajActLN(last);
					temp.setReleaseMonth(month);
					temp.setReleaseYear(year);
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
					Drama temp;
					temp.setGenre('D');
					temp.setDirector(director);
					temp.setTitle(title);
				}
				// If funny movie format is Title, year
				else if (genre == 'F') {
					//split string on ',' character
					getline(stream, title, ',');
					//eleminate leading whitespace
					title = title.substr(1, title.length());
					stream >> year;
					Comedy temp;
					temp.setReleaseYear(year);
					temp.setTitle(title);
				}

				// If video is found, update the stock of the video
				if (containsVideo(temp)) {
					if (command == 'B') {
						updateStock(temp, -1);
					}
					else if (command == 'R') {
						updateStock(temp, 1);
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
		if (command == 'I') {
			// Output comedies, dramas, and classics
			for (int i = 0; i < (int)funnyList.size(); i++) {
				cout << funnyList[i] << endl;
			}
			for (int i = 0; i < (int)dramaList.size(); i++) {
				cout << dramaList[i] << endl;
			}
			for (int i = 0; i < (int)classicList.size(); i++) {
				cout << classicList[i] << endl;
			}
		}

		// If command is history
		if (command == 'H') {
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
	
	bool found = false;
	/*
	for (int i = 0; i < (int)videoList.size(); i++)
	{
		Video *temp = videoList[i];
		if (temp->getGenre == 'C' && temp->getTitle == curTitle)
		{
			int stock = temp->getStock + curStock;
			temp->setStock(stock);
			return true;
		}
	}
	*/
	return found;
}

bool Store::containsVideo(Video *other)
{
	bool found = false;
	/*
	for (int i = 0; i < (int)videoList.size(); i++)
	{
		Video *temp = videoList[i];
		char genre = temp->getGenre;

		if (genre == other->getGenre)
		{

			if (temp->getDirector == other->getDirector &&
				temp->getTitle == other->getTitle &&
				temp->getReleaseYear == other->getReleaseYear)
				return true;
		}
	}
	*/
	return found;
}

void Store::sort() {
	// Using Bubble Sort

	// Classics sorted by release date then major actor
	int i, j;
	bool swapped;

	// Iterate through the vector until sorted
	for (i = 0; i < (int) classicList.size() - 1; i++)
	{
		swapped = false;

		// Iterate through vector to do the comparisons
		for (j = 0; j < (int)classicList.size() - i - 1; j++)
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
	for (i = 0; i < (int)classicList.size() - 1; i++)
	{
		swapped = false;
		for (j = 0; j < (int)classicList.size() - i - 1; j++)
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
	for (i = 0; i < (int)classicList.size() - 1; i++)
	{
		swapped = false;
		for (j = 0; j < (int)classicList.size() - i - 1; j++)
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