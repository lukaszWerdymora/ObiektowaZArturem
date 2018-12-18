#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Uzytkownik.h"
using namespace std;

class KsiazkaAdresowa {
    int idZalogowanegoUzytkownika;
    string nazwaPlikuZUzytkownikami;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    vector <Uzytkownik> uzytkownicy;
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin( string login);
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    string konwerjsaIntNaString(int liczba);
    bool czyPlikJestPusty(fstream &plikTekstowy);
public:
    KsiazkaAdresowa();
    void rejstracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

};
