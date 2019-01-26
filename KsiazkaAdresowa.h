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
    AdresatMenadzer *adresatMenadzer;
    int idZalogowanegoUzytkownika;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    :uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI (nazwaPlikuZAdresatami)
    {

    adresatMenadzer= NULL;
    };
    ~KsiazkaAdresowa (){
        delete adresatMenadzer;
        adresatMenadzer=NULL;
    }
    void rejestracjaUzytkownika ();
    void wypiszWszystkichUzytkonikow ();

    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanie();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku ();
    void wypiszAdresatowZalogowanegoUzytkownika();
    void dodajAdresataDoVectora();
    void dopiszAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
};
#endif // KSIAZKAADRESOWA_H
