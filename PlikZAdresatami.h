#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

class PlikZAdresatami {

    const string NAZWA_PLIKU_Z_ADRESATAMI;
    string nazwaTymczasowegoPlikuZAdresatami="Adresaci_Tymczasowy.txt";
    fstream plikTekstowy;
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int idOstatniegoAdresata;;// proba przeslania Id ostaniego adresata
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty();



public:
    PlikZAdresatami (string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI (nazwaPlikuZAdresatami){
        idOstatniegoAdresata=0;
    };

    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku( Adresat adresat);
    int pobierzIdOstatniegoAdresata();
    int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);
    void usunOdczytywanyPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(string nazwaTymczasowegoPlikuZRozszerzeniem, string nazwaPlikuZRozszerzeniem);

};
#endif // PLIKZADRESATAMI_H
