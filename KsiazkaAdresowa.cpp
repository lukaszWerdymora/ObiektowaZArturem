#include "KsiazkaAdresowa.h"
//moje

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenadzer.rejstracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkonikow(){
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}
int KsiazkaAdresowa::logowanieUzytkownika (){

   idZalogowanegoUzytkownika = uzytkownikMenadzer.logowanieUzytkownika();
}
void KsiazkaAdresowa :: zmianaHaslaZalogowanegoUzytkownika(){

    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();

}
void KsiazkaAdresowa :: wylogowanie(){
    uzytkownikMenadzer.wylogowanie();
}
void KsiazkaAdresowa :: wczytajAdresatowZalogowanegoUzytkownikaZPliku (){
    adresatMenadzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa :: wypiszAdresatowZalogowanegoUzytkownika(){
    adresatMenadzer.wypiszAdresatowZalogowanegoUzytkownika();
}
void KsiazkaAdresowa :: dodajAdresataDoVectora(){
    adresatMenadzer.dodajAdresataDoVectora(idZalogowanegoUzytkownika);
}
