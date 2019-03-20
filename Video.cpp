#include "Video.h"

Video::Video()
{
}

Video::Video(const char &g, const int &s, const string &d,
             const string &t, const int &ry)
{
    genre = g;
    stock = s;
    director = d;
    title = t;
    releaseYear = ry;
}

Video::~Video()
{
}

Comedy::Comedy() : Video()
{
}
Comedy::Comedy(const char &g, const int &s, const string &d,
               const string &t, const int &ry) : Video(g, s, d, t, ry)
{
}

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

Drama::Drama() : Video()
{
}
Drama::Drama(const char &g, const int &s, const string &d,
             const string &t, const int &ry) : Video(g, s, d, t, ry)
{
}

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

Classical::Classical() : Video()
{
}
Classical::Classical(const char &g, const int &s, const string &d,
                     const string &t, const string &maFN,
                     const string &maLN, const int &rm, const int &ry)
    : Video(g, s, d, t, ry)
{
    majActFN = maFN;
    majActLN = maLN;
    releaseMonth = rm;
}

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
			if ((getMajActFN() + getMajActLN()) > (rhs.getMajActFN + rhs.getMajActLN)) {
				return true;
			}
		}
	}

	return false;
}

void Video::modifyStock(int s)
{
    if (s < 0)
    {
        stock -= s;
    }
    else
    {
        stock += s;
    }
}

void Video::setStock(int s)
{
    stock = s;
}

int Video::getStock() const
{
    return stock;
}

void Video::setGenre(char g)
{
    genre = g;
}

char Video::getGenre() const
{
    return genre;
}

void Video::setReleaseYear(int ry)
{
    releaseYear = ry;
}

int Video::getReleaseYear() const
{
    return releaseYear;
}

void Video::setDirector(string d)
{
    director = d;
}

string Video::getDirector() const
{
    return director;
}

void Video::setTitle(string t)
{
    title = t;
}

string Video::getTitle() const
{
    return title;
}

string Classical::getMajActFN() const
{
    return majActFN;
}
void Classical::setMajActFN(string fn)
{
    majActFN = fn;
}
string Classical::getMajActLN() const
{
    return majActLN;
}
void Classical::setMajActLN(string ln)
{
    majActLN = ln;
}
int Classical::getReleaseMonth() const
{
    return releaseMonth;
}
void Classical::setReleaseMonth(int rm)
{
    releaseMonth = rm;
}

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