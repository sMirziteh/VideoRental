#include "Trans.h"

Trans::Trans()
{
}

Trans::Trans(const char &ttype, const char &mtype,
             const Customer &cust, const Video &vid)
{
    txType = ttype;
    mediaType = mtype;
    C = cust;
    V = vid;
}

Trans::~Trans()
{
}

ostream &operator<<(ostream &output, const Trans &T)
{
    output << T.txType << " " << T.C.getID() << " " << T.mediaType << " "
           << " " << T.V.getTitle();
    return output;
}