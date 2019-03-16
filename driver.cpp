#include "Video.h"
#include "Customer.h"
#include "Trans.h"
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

    Customer A(1111, "Mickey", "Mouse"), B(1000, "Minnie", "Mouse");
    cout << A << endl;
    cout << B << endl;

    Trans T('B', 'D', B, cd);
    cout << T << endl;

    // B.addTransaction(T);
    // B.showTransactions();
    return 0;
}