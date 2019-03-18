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

void Store::initializeInventory(ifstream invFile)
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
			}
			else if (genre == 'D')
			{
				Video *currentVideo = new Drama(genre, stock, director, title, year);
				vid = currentVideo;
			}
			else
			{
				Video *currentVideo = new Classical(genre, stock, director, title,
					first, last, month, year);
				vid = currentVideo;
			}
			videoList.push_back(vid);
		}
	}
}

void Store::initializeCustomers(ifstream custFile)
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

void Store::processCommands(ifstream commFile)
{

}

bool Store::updateStock(string curTitle, int curStock)
{
	bool found = false;
	for (int i = 0; i < videoList.size(); i++)
	{
		Video *temp = videoList[i];
		if (temp->getGenre == 'C' && temp->getTitle == curTitle)
		{
			int stock = temp->getStock + curStock;
			temp->setStock(stock);
			return true;
		}
	}
	return found;
}

bool Store::containsVideo(Video *other)
{
	bool found = false;

	for (int i = 0; i < videoList.size(); i++)
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
	return found;
}