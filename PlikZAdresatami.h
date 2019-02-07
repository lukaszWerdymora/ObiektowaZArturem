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
    int idOstatniegoAdresata;// proba przeslania Id ostaniego adresata
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty();
    //void zaktualizujDaneEdytowanegoAdresata(int idEdytowanegoAdresata);// to moze bêdzie publiczne
    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    string pobierzLinieZPlikuAdresaci (int numerLinii);// pobiera linie do zmiany danych adresata




public:
    PlikZAdresatami (string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI (nazwaPlikuZAdresatami){
        idOstatniegoAdresata=0;
    };

    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku( Adresat adresat);
    int pobierzIdOstatniegoAdresata();
    int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);
    void usunAdresataZPliku (int idUsuwanegoAdresata);
    void usunOdczytywanyPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(string nazwaTymczasowegoPlikuZRozszerzeniem, string nazwaPlikuZRozszerzeniem);
    void zaktualizujDaneEdytowanegoAdresata(Adresat adresat, int idEdytowanegoAdresata);


};
#endif // PLIKZADRESATAMI_H
