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

public:
    //musi byc konstruktor
    //AdresatMenadzer();
    //AdresatMenadzer (string nazawaPlikuZAdresatami) : plikZAdresatami (nazawaPlikuZAdresatami){};
    //UzytkownikMenadzer (string nazwaPlikuZUzytkonikami) : plikZUzytkownikami (nazwaPlikuZUzytkonikami){};
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku (int idZalogowanegoUzytkownika);
    void wypiszAdresatowZalogowanegoUzytkownika();
    void dodajAdresataDoVectora(int idZalogowanegoUzytkownika);


};
#endif // ADRESATMENADZER_H
