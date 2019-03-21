//---------------------------------Video.cpp---------------------------------
// Shelby Mirziteh CSS_343 C
// Group: Jordan Lawson, Shelby Mirziteh, Kier Fisher
// 03/14/2019
// 03/20/2019
// -------------------------------------------------------------------------
// implements Video class for video rental program.
// -------------------------------------------------------------------------

#include "Video.h"

// ------------------------------default constr------------------------
// Constructor
// Description: instantiates new empty Video object
// -------------------------------------------------------------------
Video::Video()
{
}

// ------------------------------constructor------------------------
// Constructor
// Description: instantiates new Video object with given values
// -------------------------------------------------------------------
Video::Video(const char &g, const int &s, const string &d,
	const string &t, const int &ry)
{
	genre = g;
	stock = s;
	director = d;
	title = t;
	releaseYear = ry;
}

// ------------------------------destructor------------------------
// destructor for video class and children
// -------------------------------------------------------------------
Video::~Video()
{
}

// ------------------------------Comedy constr------------------------
// Constructor
// Description: instantiates new empty Comedy video
// -------------------------------------------------------------------
Comedy::Comedy() : Video()
{
}

// ------------------------------Comedy constr------------------------
// Constructor
// Description: instantiates new Comedy video w/ values
// -------------------------------------------------------------------
Comedy::Comedy(const char &g, const int &s, const string &d,
	const string &t, const int &ry) : Video(g, s, d, t, ry)
{
}

//<<<<<<< HEAD
// ------------------------------Drama constr------------------------
// Constructor
// Description: instantiates new empty Drama video
// -------------------------------------------------------------------
//=======
bool Comedy::operator>(const Comedy& rhs) const {
	// Funnies sorted by title then year
	if (getTitle() > rhs.getTitle()) {
		return true;
	}
	else if (getTitle() == rhs.getTitle()) {
		if (getReleaseYear() > rhs.getReleaseYear()) {
			return true;
		}
	}
	return false;
}

//>>>>>>> Jordan
Drama::Drama() : Video()
{
}

// ------------------------------Drama constr------------------------
// Constructor
// Description: instantiates new Drama video w/ values
// -------------------------------------------------------------------
Drama::Drama(const char &g, const int &s, const string &d,
	const string &t, const int &ry) : Video(g, s, d, t, ry)
{
}

//<<<<<<< HEAD
// ------------------------------Classical constr------------------------
// Constructor
// Description: instantiates new empty Classical video
// -------------------------------------------------------------------
//=======
bool Drama::operator>(const Drama& rhs) const {
	// Drama sorted by director then title
	if (getDirector() > rhs.getDirector()) {
		return true;
	}
	else if (getDirector() == rhs.getDirector()) {
		if (getTitle() > rhs.getTitle()) {
			return true;
		}
	}
	return false;
}

//>>>>>>> Jordan
Classical::Classical() : Video()
{
}

// ------------------------------Classical constr------------------------
// Constructor
// Description: instantiates new Classical video w/ values
// -------------------------------------------------------------------
Classical::Classical(const char &g, const int &s, const string &d,
	const string &t, const string &maFN,
	const string &maLN, const int &rm, const int &ry)
	: Video(g, s, d, t, ry)
{
	majActFN = maFN;
	majActLN = maLN;
	releaseMonth = rm;
}

//<<<<<<< HEAD
// ------------------------------modifyStock------------------------
// increases or decreases video stock by the amount provided
// -------------------------------------------------------------------
//=======
bool Classical::operator>(const Classical& rhs) const {
	// Classics sorted by release date then major actor
	if (getReleaseYear() > rhs.getReleaseYear()) {
		return true;
	}
	else if (getReleaseYear() == rhs.getReleaseYear()) {
		if (getReleaseMonth() > rhs.getReleaseMonth()) {
			return true;
		}
		if (getReleaseMonth() == rhs.getReleaseMonth()) {
			if ((getMajActFN() + getMajActLN()) > (rhs.getMajActFN() + rhs.getMajActLN())) {
				return true;
			}
		}
	}

	return false;
}

//>>>>>>> Jordan
void Video::modifyStock(int s)
{
	//if negative, decrease stock
	if (s < 0)
	{
		stock -= s;
	}
	else //increase
	{
		stock += s;
	}
}

// ------------------------------*Getters*------------------------
// accessors for Video class attributes
// pretty straight forward
// -------------------------------------------------------------------
int Video::getStock() const
{
	return stock;
}

char Video::getGenre() const
{
	return genre;
}

int Video::getReleaseYear() const
{
	return releaseYear;
}

string Video::getDirector() const
{
	return director;
}

string Video::getTitle() const
{
	return title;
}

string Classical::getMajActFN() const
{
	return majActFN;
}

string Classical::getMajActLN() const
{
	return majActLN;
}

int Classical::getReleaseMonth() const
{
	return releaseMonth;
}

// ------------------------------*Setters*------------------------
// mutators for Video class attributes
// pretty straight forward
// -------------------------------------------------------------------

void Video::setStock(int s)
{
	stock = s;
}

void Video::setGenre(char g)
{
	genre = g;
}

void Video::setReleaseYear(int ry)
{
	releaseYear = ry;
}

void Video::setDirector(string d)
{
	director = d;
}

void Video::setTitle(string t)
{
	title = t;
}

void Classical::setMajActFN(string fn)
{
	majActFN = fn;
}

void Classical::setMajActLN(string ln)
{
	majActLN = ln;
}

void Classical::setReleaseMonth(int rm)
{
	releaseMonth = rm;
}

// ------------------------------Overloaded << ------------------------
// overloaded output operators for the parent Video class and a separate
// for classical movies
// -------------------------------------------------------------------
ostream &operator<<(ostream &output, const Video &v)
{
	output << v.getTitle() << " " << v.getDirector() << " " << v.getReleaseYear() << " ";
	return output;
}

ostream &operator<<(ostream &output, const Classical &C)
{
	output << C.getTitle() << " " << C.getDirector() << " "
		<< C.getMajActFN() << " " << C.getMajActLN() << " "
		<< C.getReleaseMonth() << " " << C.getReleaseYear() << " ";
	return output;
}