#ifndef TRANS_H
#define TRANS_H
#include <iostream>
#include <string>
#include <vector>
#include "Customer.h"
#include "Video.h"
using namespace std;

class Trans
{
  friend ostream &operator<<(ostream &, const Trans &);
  friend Customer;
  friend Video;

protected:
  char txType;
  char mediaType;
  Customer C;
  Video V;

public:
  Trans();
  Trans(const char &txType, const char &mediaType,
        const Customer &, const Video &);
  ~Trans();
};

#endif