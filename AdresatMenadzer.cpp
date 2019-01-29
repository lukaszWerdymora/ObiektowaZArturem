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
void AdresatMenadzer :: wyszukajAdresatowPoNazwisku() {
    string nazwiskoPoszukiwanegoAdresata="";
    system ("cls");
    cin.clear();
    cin.ignore(1000, '\n');

    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;
        cout << "Wyszukaj adresatow o nazwisku: ";
        getline (cin, nazwiskoPoszukiwanegoAdresata);
        nazwiskoPoszukiwanegoAdresata= MetodyPomocnicze ::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);
        for (int i=0; i<adresaci.size(); i++) {
            if (adresaci[i].pobierzNazwisko()==nazwiskoPoszukiwanegoAdresata) {
                wypiszAdresata(i);
            }
        }
    } else {

        cout<<"Ksiazka adresowa jest pusta\n";
    }
}
int AdresatMenadzer :: usunAdresata() {
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();
    char znak;
    bool czyIstniejeAdresat = false;

    for (int i=0; i<adresaci.size(); i++) {
        if (adresaci[i].pobierzId()==idUsuwanegoAdresata) {
            czyIstniejeAdresat=true;
            cout<<endl<<"Potwierdz wciskajac 't': ";
            znak = wczytajZnak();
            if (znak=='t') {
                cout<< "Znalzalem ID i chce go usunac "<<idUsuwanegoAdresata<<endl;
                wypiszAdresata(idUsuwanegoAdresata-1);
                numerLiniiUsuwanegoAdresata = plikZAdresatami.zwrocNumerLiniiSzukanegoAdresata(idUsuwanegoAdresata);
                plikZAdresatami.usunWybranaLinieWPliku(numerLiniiUsuwanegoAdresata);
                adresaci.erase(adresaci.begin()+i);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return idUsuwanegoAdresata;

            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (czyIstniejeAdresat==false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return 0;
}

Adresat AdresatMenadzer :: edytujAdresata() {
    system("cls");
    Adresat tymczasowyAdresat;
    int idEdytowanegoAdresata = 0;
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;
    wybor = wybierzOpcjeZMenuEdycja();

    for (int i=0; i<adresaci.size(); i++) {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata) {
            czyIstniejeAdresat = true;
            tymczasowyAdresat=wczytajEdytowanegoAdresata(idEdytowanegoAdresata);
            switch (wybor) {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(wczytajLinie()));
                tymczasowyAdresat.ustawImie(adresaci[i].pobierzImie());
                break;

                case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(wczytajLinie()));
                tymczasowyAdresat.ustawNazwisko(adresaci[i].pobierzNazwisko());
                break;

                case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(wczytajLinie());
                tymczasowyAdresat.ustawNumerTelefonu(adresaci[i].pobierzNumerTelefonu());
                break;

                case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(wczytajLinie());
                tymczasowyAdresat.ustawEmail(adresaci[i].pobierzEmail());
                break;

                case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(wczytajLinie()));
                tymczasowyAdresat.ustawAdres(adresaci[i].pobierzAdres());
                break;

                case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;

                default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
                }

            }
        }
        if (czyIstniejeAdresat == false) {
            cout << endl << "Nie ma takiego adresata." << endl << endl;
        }


    plikZAdresatami.zaktualizujDaneEdytowanegoAdresata(tymczasowyAdresat, idEdytowanegoAdresata);
    return tymczasowyAdresat;
    system("pause");
}
Adresat AdresatMenadzer :: wczytajEdytowanegoAdresata (int idEdytowanegoAdresata){
    Adresat adresat;
    idEdytowanegoAdresata-=1;// vector jest od 0 a Id od 1
    adresat.ustawId(adresaci[idEdytowanegoAdresata].pobierzId());
    adresat.ustawIdUzytkownika(adresaci[idEdytowanegoAdresata].pobierzIdUzytkownika());
    adresat.ustawImie(adresaci[idEdytowanegoAdresata].pobierzImie());
    adresat.ustawNazwisko(adresaci[idEdytowanegoAdresata].pobierzNazwisko());
    adresat.ustawNumerTelefonu(adresaci[idEdytowanegoAdresata].pobierzNumerTelefonu());
    adresat.ustawEmail(adresaci[idEdytowanegoAdresata].pobierzEmail());
    adresat.ustawAdres(adresaci[idEdytowanegoAdresata].pobierzAdres());

    return adresat;
}
char AdresatMenadzer :: wczytajZnak() {
    string wejscie = "";
    char znak  = {0};

    while (true) {
        getline(cin, wejscie);

        if (wejscie.length() == 1) {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

int AdresatMenadzer :: podajIdWybranegoAdresata() {
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

int AdresatMenadzer :: wczytajLiczbeCalkowita() {
    cin.clear();
    cin.ignore(1000, '\n');

    string wejscie = "";
    int liczba = 0;

    while (true) {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba) {
            break;
        } else {
            cout << "To nie jest liczba. Wpisz ponownie. " << endl;
        }


    }
    return liczba;
}

void AdresatMenadzer :: wypiszAdresata(int idAdresata) {
    cout<<adresaci[idAdresata].pobierzId()<<'|';
    cout<<adresaci[idAdresata].pobierzImie()<<'|';
    cout<<adresaci[idAdresata].pobierzNazwisko()<<'|';
    cout<<adresaci[idAdresata].pobierzAdres()<<'|';
    cout<<adresaci[idAdresata].pobierzNumerTelefonu()<<'|';
    cout<<adresaci[idAdresata].pobierzEmail()<<'|'<<endl;
}
char AdresatMenadzer :: wybierzOpcjeZMenuEdycja() {
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}

string AdresatMenadzer :: wczytajLinie() {
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
