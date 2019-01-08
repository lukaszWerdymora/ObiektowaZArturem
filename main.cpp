#include <iostream>
#include "KsiazkaAdresowa.h"
#include "UzytkownikMenadzer.h"
using namespace std;

int main()
{

    KsiazkaAdresowa ksiazkaadresowa ("Uzytkownicy1.txt");
    ksiazkaadresowa.wypiszWszystkichUzytkonikow();
    //ksiazkaadresowa.rejestracjaUzytkownika();
    //ksiazkaadresowa.rejestracjaUzytkownika();
//    ksiazkaadresowa.logowanieUzytkownika(uzytkownicy);
    ksiazkaadresowa.logowanieUzytkownika();
    ksiazkaadresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    ksiazkaadresowa.wypiszAdresatowZalogowanegoUzytkownika();
    ksiazkaadresowa.dodajAdresataDoVectora();
    ksiazkaadresowa.wypiszAdresatowZalogowanegoUzytkownika();
    return 0;
}

