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
					continue;

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
			Classical *currentVideo = new Classical(genre, stock, director, title,
				first, last, month, year);
			//vid = currentVideo;
			classicList.push_back(currentVideo);
		}

		
	}
}

void Store::initializeCustomers(ifstream& custFile)
{
	int id;
	string first, last;
	//TEST
	cout << "before loop" << endl;
	while (custFile >> id >> first >> last)
	{
		Customer *cust = new Customer(id, first, last);
		customerList.add(cust);
		
		//TEST
		cout << "customer added: " 
			<< id << " " << first << " " << last << endl;
	}
	//TEST
	cout << "after loop" << endl;
}

void Store::processCommands(ifstream& commFile)
{
	char command, genre = '-', videoType;
	int ID, month, year;
	string director, title, first, last, entry;

	string line;
	//read each line from the file
	while (getline(commFile, line))
	{
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
			if (command != 'H') {
				stream >> videoType;
				if (videoType != 'D') {
					cout << "Invalid Video Type" << endl;
					continue;
				}
				stream >> genre;
				
				// If classical movie format is month year first last
				if (genre == 'C')
				{
					stream >> month;
					stream >> year;
					stream >> first;
					stream >> last;

					//TEST CODE
					cout << "----- " << "classical, month = " << month << " year = " << year << " actor = " << first << " " << last << " ----" << endl;
					//END
				}
				//If genre is comedy format is title, year
				else if (genre == 'F')
				{
					//split string on ',' character
					getline(stream, title, ',');
					//eleminate leading whitespace
					title = title.substr(1, title.length());

					//split string on ',' character
					getline(stream, entry, ',');
					//eleminate leading whitespace
					entry = entry.substr(1, entry.length());
					year = stoi(entry);

					//TEST CODE
					cout << "---- " << "comedy, title = " << title << " year = " << year << " ----" << endl;
					//END
				}
				//If genre is drama, format is director, title, (<-extra comma at end)
				else if (genre == 'D')
				{
					//split string on ',' character
					getline(stream, title, ',');
					//eleminate leading whitespace
					title = title.substr(1, title.length());

					//split string on ',' character
					getline(stream, director, ',');
					//eleminate leading whitespace
					director = director.substr(1, director.length());

					//TEST CODE
					cout << "---- " << "drama, director = " << director << " title = " << title << " ----" << endl;
					//END
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
	}
}

bool Store::updateStock(string curTitle, int curStock)
{
	for (int i = 0; i < (int)classicList.size(); i++)
	{
		Classical *temp = classicList[i];
		if (temp->Video::getTitle() == curTitle)
		{
			int stock = temp->Video::getStock() + curStock;
			temp->Video::setStock(stock);
			return true;
		}
	}
	return false;
}

bool Store::containsVideo(Video *other)
{
	string title = other->getTitle();
	string director = other->getDirector();

	for (int i = 0; i < (int)dramaList.size(); i++)
	{
		Video *temp = dramaList[i];
		if (temp->getTitle() == title)
			return true;
		else if (temp->getDirector() == director)
			return true;
	}

	for (int i = 0; i < (int)funnyList.size(); i++)
	{
		Video *temp = funnyList[i];
		if (temp->getTitle() == title)
			return true;
		else if (temp->getDirector() == director)
			return true;
	}

	return false;
}

bool Store::containsClassical(Classical *other)
{
	int month = other->getReleaseMonth();
	int year = other->Video::getReleaseYear();
	string actorFirst = other->getMajActFN();
	string actorLast = other->getMajActLN();

	for (int i = 0; i < (int)classicList.size(); i++)
	{
		Classical *temp = classicList[i];
		if (month == temp->getReleaseMonth() && year == temp->Video::getReleaseYear()
			&& actorFirst == temp->getMajActFN() && actorLast == temp->getMajActLN())
			return true;
	}

	return false;
}

//TEST METHODS
void Store::printComm()
{

}

void Store::printCust()
{
	customerList.print();
}

void Store::printInv()
{
	for (int i = 0; i < (int)dramaList.size(); i++)
	{
		cout << dramaList[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < (int)funnyList.size(); i++)
	{
		cout << funnyList[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < (int)classicList.size(); i++)
	{
		cout << classicList[i] << endl;
	}
}