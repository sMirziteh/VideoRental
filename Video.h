#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Video
{
  friend ostream &operator<<(ostream &, const Video &);

public:
  Video();
  Video(const char &genre, const int &stock,
        const string &director, const string &title, const int &releaseYear);
  ~Video();

  void modifyStock(int s);
  void setStock(int s);
  int getStock() const;
  void setGenre(char g);
  char getGenre() const;
  void setReleaseYear(int ry);
  int getReleaseYear() const;
  void setDirector(string d);
  string getDirector() const;
  void setTitle(string t);
  string getTitle() const;

protected:
  char genre;
  int stock;
  int releaseYear;
  string director;
  string title;
};

class Comedy : public Video
{
public:
  Comedy();
  Comedy(const char &genre, const int &stock,
         const string &director, const string &title, const int &releaseYear);
  ~Comedy();
};

class Drama : public Video
{
public:
  Drama();
  Drama(const char &genre, const int &stock,
        const string &director, const string &title, const int &releaseYear);
  ~Drama();
};

class Classical : public Video
{
public:
  friend ostream &operator<<(ostream &, const Classical &);
  Classical();
  Classical(const char &genre, const int &stock,
            const string &director, const string &title, const string &majActFN, const string &majActLN,
            const int &releaseMonth, const int &releaseYear);
  ~Classical();
  string getMajActFN() const;
  void setMajActFN(string fn);
  string getMajActLN() const;
  void setMajActLN(string ln);
  int getReleaseMonth() const;
  void setReleaseMonth(int rm);

protected:
  string majActFN;
  string majActLN;
  int releaseMonth;
};

#endif