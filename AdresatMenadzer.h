#ifndef ADRESATMENADZER_H
#define ADRESATMENADZER_H

#include "Adresat.h"
#include "PlikZAdresatami.h"

#include <iostream>
#include <vector>


using namespace std;

class AdresatMenadzer {
    vector <Adresat> adresaci;
    //int idZalogowanegoUzytkownika;// dlaczego to dziala
    PlikZAdresatami plikZAdresatami;
    Adresat podajDaneNowegoAdresata();
    int ID_ZALOGOWANEGO_UZYTKOWNIKA;

public:
    AdresatMenadzer (string nazwaPlikuZAdresatami, int idZalogowanegoUzytkonika) : plikZAdresatami (nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkonika){};
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika);
    void wypiszAdresatowZalogowanegoUzytkownika();
    void dodajAdresataDoVectora(int idZalogowanegoUzytkownika);
    void dodajAdresata ();


};
#endif // ADRESATMENADZER_H
