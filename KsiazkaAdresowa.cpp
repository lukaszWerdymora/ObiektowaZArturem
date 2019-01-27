#include "KsiazkaAdresowa.h"
//moje

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenadzer.rejstracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkonikow(){
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::logowanieUzytkownika (){

   uzytkownikMenadzer.logowanieUzytkownika();
   if (uzytkownikMenadzer.czyUzytkownikJestZalogowany()){
    adresatMenadzer = new AdresatMenadzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenadzer.pobierzIdZalowanegoUzytkownika());

   }

}
void KsiazkaAdresowa :: zmianaHaslaZalogowanegoUzytkownika(){

    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();

}
void KsiazkaAdresowa :: wylogowanie(){
    uzytkownikMenadzer.wylogowanie();
    delete adresatMenadzer;
    adresatMenadzer=NULL;
}
void KsiazkaAdresowa :: wczytajAdresatowZalogowanegoUzytkownikaZPliku (){
    adresatMenadzer->wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzytkownikMenadzer.pobierzIdZalowanegoUzytkownika());
}

void KsiazkaAdresowa :: wypiszAdresatowZalogowanegoUzytkownika(){
    adresatMenadzer->wypiszAdresatowZalogowanegoUzytkownika();
}
void KsiazkaAdresowa :: dodajAdresataDoVectora(){
    adresatMenadzer->dodajAdresataDoVectora(idZalogowanegoUzytkownika);
}
void KsiazkaAdresowa :: dopiszAdresata(){
    adresatMenadzer->dodajAdresata();
}
void KsiazkaAdresowa :: wyszukajAdresatowPoImieniu(){
    adresatMenadzer->wyszukajAdresatowPoImieniu();
}
void KsiazkaAdresowa :: wyszukajAdresatowPoNazwisku(){
    adresatMenadzer-> wyszukajAdresatowPoNazwisku();
}
void KsiazkaAdresowa :: usunAdresata(){
    adresatMenadzer-> usunAdresata();
}
