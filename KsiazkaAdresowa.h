#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include <vector>

//#include "Uzytkownik.h"
#include "UzytkownikMenadzer.h"
#include "AdresatMenadzer.h"
using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenadzer uzytkownikMenadzer;
    AdresatMenadzer adresatMenadzer;
    int idZalogowanegoUzytkownika;

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
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku ();
    void wypiszAdresatowZalogowanegoUzytkownika();
    void dodajAdresataDoVectora();
};
#endif // KSIAZKAADRESOWA_H
