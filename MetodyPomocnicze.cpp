#include "MetodyPomocnicze.h"

string MetodyPomocnicze :: konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

int MetodyPomocnicze:: konwersjaStringNaInt (string sLiczba){
    int liczba;
    liczba=atoi(sLiczba.c_str());

    return liczba;
}
