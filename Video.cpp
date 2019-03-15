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

Comedy::~Comedy()
{
}

Drama::Drama() : Video()
{
}
Drama::Drama(const char &g, const int &s, const string &d,
             const string &t, const int &ry) : Video(g, s, d, t, ry)
{
}

Drama::~Drama()
{
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

Classical::~Classical()
{
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