#include "Video.h"
#include <iostream>
using namespace std;

int main()
{
    Classical c('C', 10, "George Cukor", "Holiday", "Katherine", "Hepburn", 9, 1939);
    Drama d('D', 10, "Steven Spielberg", "Schindler's List", 1993);
    Comedy cd('F', 10, "Nora Ephron", "You've Got Mail", 1998);
    cout << c << endl;
    cout << d << endl;
    cout << cd << endl;
    return 0;
}