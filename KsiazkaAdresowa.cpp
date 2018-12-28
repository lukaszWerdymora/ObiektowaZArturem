#include "KsiazkaAdresowa.h"
//moje
KsiazkaAdresowa::KsiazkaAdresowa(){
    uzytkownikMenadzer.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenadzer.rejstracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkonikow(){
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}


