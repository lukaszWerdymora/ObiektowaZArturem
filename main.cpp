#include <iostream>
#include "KsiazkaAdresowa.h"
#include "UzytkownikMenadzer.h"
using namespace std;

int main()
{

    KsiazkaAdresowa ksiazkaadresowa ("Uzytkownicy1.txt", "Adresaci.txt");

    //ksiazkaadresowa.wypiszWszystkichUzytkonikow();


    ksiazkaadresowa.logowanieUzytkownika();
    ksiazkaadresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    ksiazkaadresowa.wypiszAdresatowZalogowanegoUzytkownika();
    //ksiazkaadresowa.dopiszAdresata();

    //ksiazkaadresowa.wyszukajAdresatowPoImieniu();
    //ksiazkaadresowa.wyszukajAdresatowPoNazwisku();
    //ksiazkaadresowa.usunAdresata();

    ksiazkaadresowa.edytujAdresata();
    ksiazkaadresowa.wypiszAdresatowZalogowanegoUzytkownika();


    return 0;
}

