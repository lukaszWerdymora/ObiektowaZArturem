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
string MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst){
   if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}
