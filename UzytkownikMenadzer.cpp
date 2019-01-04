#include "UzytkownikMenadzer.h"
void UzytkownikMenadzer :: wczytajUzytkownikowZPliku() {
    uzytkownicy=plikZUzytkownikami.wczytajUzytkownikowZPliku();
}


void UzytkownikMenadzer::rejstracjaUzytkownika()

{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UzytkownikMenadzer::wypiszWszystkichUzytkownikow() {
    for (int i=0; i<uzytkownicy.size(); i++) {

        cout<<uzytkownicy[i].pobierzId()<<'|';
        cout<<uzytkownicy[i].pobierzLogin()<<'|';
        cout<<uzytkownicy[i].pobierzHaslo()<<'|'<<endl;

    }
}
Uzytkownik UzytkownikMenadzer::podajDaneNowegoUzytkownika() {

    Uzytkownik uzytkownik;


    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    do {
        cout <<  "Podaj login: ";

        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";

    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);
    return uzytkownik;

}

int UzytkownikMenadzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}




bool UzytkownikMenadzer::czyIstniejeLogin( string login) {
    for (int i=0; i<uzytkownicy.size(); i++) {

        if (uzytkownicy[i].pobierzLogin()== login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;

}
//03.01.19

int UzytkownikMenadzer :: logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    cin >> login;

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> Uzytkownik :: pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> haslo;

                if (itr -> Uzytkownik :: pobierzHaslo()  == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = itr-> Uzytkownik :: pobierzId();
                    return idZalogowanegoUzytkownika;
                    //return itr-> Uzytkownik :: pobierzId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}
void UzytkownikMenadzer :: zmianaHaslaZalogowanegoUzytkownika(/*int idZalogowanegoUzytkownika*/)// tu moze chyba byc bez parametru
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> Uzytkownik :: pobierzId() == idZalogowanegoUzytkownika)
        {
            itr -> Uzytkownik :: ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

/* przenies do plikuZUzytkownikami
void UzytkownikMenadzer :: zapiszWszystkichUzytkownikowDoPliku()
{
    //fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    vector <Uzytkownik>::iterator itrKoniec = --uzytkownicy.end();

    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), ios::out);

    if (plikTekstowy.good() == true)
    {
        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(*itr);

            if (itr == itrKoniec)
            {
               plikTekstowy << liniaZDanymiUzytkownika;
            }
            else
            {
                plikTekstowy << liniaZDanymiUzytkownika << endl;
            }
            liniaZDanymiUzytkownika = "";
        }
        plikTekstowy.close();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << nazwaPlikuZUzytkownikami << endl;
    }
}
*/
