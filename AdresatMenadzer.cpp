#include "AdresatMenadzer.h"


void AdresatMenadzer :: wczytajAdresatowZalogowanegoUzytkownikaZPliku ( int idZalogowanegoUzytkownika) {
    adresaci=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku ( idZalogowanegoUzytkownika);
}

void AdresatMenadzer :: wypiszAdresatowZalogowanegoUzytkownika() {
    for (int i=0; i<adresaci.size(); i++) {
        cout<<adresaci[i].pobierzId()<<'|';
        cout<<adresaci[i].pobierzImie()<<'|';
        cout<<adresaci[i].pobierzNazwisko()<<'|';
        cout<<adresaci[i].pobierzAdres()<<'|';
        cout<<adresaci[i].pobierzNumerTelefonu()<<'|';
        cout<<adresaci[i].pobierzEmail()<<'|'<<endl;
    }
    system("pause");
}

void AdresatMenadzer :: dodajAdresataDoVectora (int idZalogowanegoUzytkownika) {
    Adresat adresat;

    cout<<"\nPodaj dane adresata ktorego chcesz dodac do ksiazki adresowej\n";
    adresat.ustawId(adresaci.size()+1);
    adresat. ustawIdUzytkownika(idZalogowanegoUzytkownika);
    adresat.ustawImie("Genowefa");
    adresat.ustawNazwisko("Pigwa");
    adresat.ustawAdres("Pacanow");
    adresat.ustawNumerTelefonu("654456465321");
    adresat.ustawEmail("pigwa@qp.pl");

    adresaci.push_back(adresat);
    cout<<"Dodano adresata";

    system("pause");
}
void AdresatMenadzer :: dodajAdresata() {
    Adresat adresat;
    adresat= podajDaneNowegoAdresata();
    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);


    cout<<"Nowy adresat dodany\n";
    system("pause");
}
Adresat AdresatMenadzer :: podajDaneNowegoAdresata() {
    Adresat adresat;
    string daneAdresata;
    cin.clear();
    cin.ignore(1000, '\n');
    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    cout<<"Podaj dane nowego adresata\nImie: ";
    //cin>>daneAdresata;
    getline (cin, daneAdresata);
    daneAdresata=MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(daneAdresata);
    adresat.ustawImie(daneAdresata);
    daneAdresata="";

    cout<<"Nazwisko: ";
    //cin>>daneAdresata;
    getline (cin, daneAdresata);
    daneAdresata=MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(daneAdresata);
    adresat.ustawNazwisko(daneAdresata);
    daneAdresata="";

    cout<<"Adres: ";
    //cin>>daneAdresata;
    getline (cin, daneAdresata);
    daneAdresata=MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(daneAdresata);
    adresat.ustawAdres(daneAdresata);
    daneAdresata="";

    cout<<"Numer telefonu: ";
    cin>>daneAdresata;
    adresat.ustawNumerTelefonu(daneAdresata);
    daneAdresata="";

    cout<<"Adres email: ";
    cin>>daneAdresata;
    adresat.ustawEmail(daneAdresata);
    daneAdresata="";

    return adresat;
}

void AdresatMenadzer :: wyszukajAdresatowPoImieniu() {
    string imiePoszukiwanegoAdresata="";
    system ("cls");
    cin.clear();
    cin.ignore(1000, '\n');

    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;
        cout << "Wyszukaj adresatow o imieniu: ";
        getline (cin, imiePoszukiwanegoAdresata);
        imiePoszukiwanegoAdresata= MetodyPomocnicze ::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);
        for (int i=0; i<adresaci.size(); i++) {
            if (adresaci[i].pobierzImie()==imiePoszukiwanegoAdresata) {
                wypiszAdresata(i);
            }
        }
    } else {

        cout<<"Ksiazka adresowa jest pusta\n";
    }
}
void AdresatMenadzer :: wypiszAdresata(int idAdresata) {
    cout<<adresaci[idAdresata].pobierzId()<<'|';
    cout<<adresaci[idAdresata].pobierzImie()<<'|';
    cout<<adresaci[idAdresata].pobierzNazwisko()<<'|';
    cout<<adresaci[idAdresata].pobierzAdres()<<'|';
    cout<<adresaci[idAdresata].pobierzNumerTelefonu()<<'|';
    cout<<adresaci[idAdresata].pobierzEmail()<<'|'<<endl;
}

