#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include <vector>

//#include "Uzytkownik.h"
#include "UzytkownikMenadzer.h"
using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenadzer uzytkownikMenadzer;

public:
    KsiazkaAdresowa();
    void rejestracjaUzytkownika ();
    void wypiszWszystkichUzytkonikow ();

};
#endif // KSIAZKAADRESOWA_H
