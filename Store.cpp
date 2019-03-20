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

		if (command == 'B' || command == 'R' || command == 'H')
		{
			stream >> ID;
			// If we get a nullptr, the customer doesn't exist
			if (customerList.get(ID) == nullptr) {
				cout << "Customer does not exist!" << endl;
				// Skip the rest of this iteration and go to next command.
				continue;
			}
			else if (command != 'H') {


				stream >> videoType;
				if (videoType != 'D') {
					cout << "Invalid Video Type" << endl;
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
						Classical temp();

					}
					//split string on ',' character
					getline(stream, director, ',');
					//eleminate leading whitespace
					director = director.substr(1, director.length());

					//split string on ',' character
					getline(stream, title, ',');
					//eleminate leading whitespace
					title = title.substr(1, title.length());
					//get the year from the stream
					stream >> year;
				}

				//Something other than F, D, or C was entered as the genre
				else
				{
					cout << "Invalid Genre" << endl;
					continue;	//continue to the next line of input
				}
			}
		}

		//Something other than B,R,H,I
		else
		{
			cout << "Invalid Command" << endl;
			continue;	//continue to the next line of input
		}

		if (!isAdded)
		{

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