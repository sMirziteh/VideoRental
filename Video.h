//---------------------------------Video.h---------------------------------
// Shelby Mirziteh CSS_343 C
// Group: Jordan Lawson, Shelby Mirziteh, Kier Fisher
// 03/14/2019
// 03/20/2019
// -------------------------------------------------------------------------
// Video class for video rental program.
// Parent video class with subclasses for comedy, drama, and classical
// -------------------------------------------------------------------------

#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Video
{
	//overloaded output operator for Video
	friend ostream &operator<<(ostream &, const Video &);

public:
	//constructors
	Video();
	Video(const char &genre, const int &stock,
		const string &director, const string &title, const int &releaseYear);
	//destructor
	~Video();

	//increases or decreases stock of video by passed value
	void modifyStock(int s);

	//getters
	int getStock() const;
	char getGenre() const;
	int getReleaseYear() const;
	string getDirector() const;
	string getTitle() const;

	//setters
	void setStock(int s);
	void setGenre(char g);
	void setReleaseYear(int ry);
	void setDirector(string d);
	void setTitle(string t);

protected:
	char genre;
	int stock;
	int releaseYear;
	string director;
	string title;
};

//Child Comedy class
//inherits from Video
class Comedy : public Video
{
public:
	//constructors
	Comedy();
	Comedy(const char &genre, const int &stock,
		const string &director, const string &title, const int &releaseYear);
	bool operator>(const Comedy &) const;
};

//Child Drama class
//inherits from Video
class Drama : public Video
{
public:
	//constructors
	Drama();
	Drama(const char &genre, const int &stock,
		const string &director, const string &title, const int &releaseYear);
	bool operator>(const Drama &) const;
};

//Child Classical class
//inherits from Video
//adds additional attributes and accessors
class Classical : public Video
{
public:
	//overloaded << for classical movie
	friend ostream &operator<<(ostream &, const Classical &);

	//constructors
	Classical();
	Classical(const char &genre, const int &stock,
		const string &director, const string &title, const string &majActFN, const string &majActLN,
		const int &releaseMonth, const int &releaseYear);

	//getters
	string getMajActFN() const;
	string getMajActLN() const;
	int getReleaseMonth() const;

	//setters
	void setMajActFN(string fn);
	void setMajActLN(string ln);
	void setReleaseMonth(int rm);
	bool operator>(const Classical &) const;

protected:
	//classical attributes
	string majActFN;  //major actor first name
	string majActLN;  //major actor last name
	int releaseMonth; //release month of movie
};

#endif