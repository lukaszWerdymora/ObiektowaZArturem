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
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) :uzytkownikMenadzer(nazwaPlikuZUzytkownikami)
    {
    uzytkownikMenadzer.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika ();
    void wypiszWszystkichUzytkonikow ();
    //int logowanieUzytkownika (vector <Uzytkownik> &uzytkownicy);
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanie();
};
#endif // KSIAZKAADRESOWA_H
