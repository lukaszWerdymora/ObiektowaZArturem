#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

class PlikZAdresatami {
    string nazwaPlikuZAdresatami;
    fstream plikTekstowy;
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int idOstatniegoAdresataZalogowanegoUzytkownika;// proba przeslania Id ostaniego adresata
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);

public:
    //PlikZAdresatami (string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami (NAZWAPLIKUZADRESATAMI){};
    //PlikZAdresatami(string NAZWAPLIKUZADRESATAMI): nazwaPlikuZAdresatami (NAZWAPLIKUZADRESATAMI){};
    PlikZAdresatami();
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

};
#endif // PLIKZADRESATAMI_H
