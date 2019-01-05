#ifndef UZYTKOWNIKMENADZER_H
#define UZYTKOWNIKMENADZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
using namespace std;

class UzytkownikMenadzer {
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;
    //string nazwaPliku;
public:
    UzytkownikMenadzer (string nazwaPlikuZUzytkonikami) : plikZUzytkownikami (nazwaPlikuZUzytkonikami){};
    void wczytajUzytkownikowZPliku();
    void rejstracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika(/*int idZalogowanegoUzytkownika*/);
    void wylogowanie ();
    void wypiszUzytkownikowTestNaWylogowanie();

};
#endif // UZYTKOWNIKMENADZER_H
