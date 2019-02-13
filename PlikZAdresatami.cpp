#include "PlikZAdresatami.h"


vector <Adresat> PlikZAdresatami :: wczytajAdresatowZalogowanegoUzytkownikaZPliku( int idZalogowanegoUzytkownika ) {
    Adresat adresat;
    vector <Adresat> adresaci;


    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;

        plikTekstowy.close();
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);

    }


    return adresaci;
}

int PlikZAdresatami :: pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze :: konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}
Adresat PlikZAdresatami :: pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:

                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:

                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:

                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:

                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:

                adresat.ustawAdres(pojedynczaDanaAdresata);

                break;
            case 6:

                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 7:

                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

string PlikZAdresatami :: pobierzLiczbe(string tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int PlikZAdresatami :: pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

int PlikZAdresatami :: pobierzIdOstatniegoAdresata () {
    return idOstatniegoAdresata;
}


void PlikZAdresatami :: dopiszAdresataDoPliku (Adresat adresat) {

    string liniaZDanymiAdresata;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::app);

    if (plikTekstowy.good()==true) {
        liniaZDanymiAdresata=zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);
        if (czyPlikJestPusty()==true) {
            plikTekstowy<<liniaZDanymiAdresata;
        } else {
            plikTekstowy<<endl<<liniaZDanymiAdresata;
        }
        plikTekstowy.close();

    } else {
        cout<<"Nie uda³o siê otowrzyc pliku";
        system("pause");
    }
    idOstatniegoAdresata++;
}
bool PlikZAdresatami :: czyPlikJestPusty() {
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}


string PlikZAdresatami :: zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata="";

    liniaZDanymiAdresata+=MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId())+'|';
    liniaZDanymiAdresata+=MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika())+'|';
    liniaZDanymiAdresata+=adresat.pobierzImie()+'|';
    liniaZDanymiAdresata+=adresat.pobierzNazwisko()+'|';
    liniaZDanymiAdresata+=adresat.pobierzAdres()+'|';
    liniaZDanymiAdresata+=adresat.pobierzNumerTelefonu()+'|';
    liniaZDanymiAdresata+=adresat.pobierzEmail()+'|';

    return liniaZDanymiAdresata;
}


void PlikZAdresatami :: usunAdresataZPliku (int idUsuwanegoAdresata) {

    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int idAdresataZPliku = 1;
    int dlugoscPliku = 0;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);
    odczytywanyPlikTekstowy.seekp(0, ios::end);
    dlugoscPliku=odczytywanyPlikTekstowy.tellp();
    odczytywanyPlikTekstowy.seekp(0, ios::beg);



    if (odczytywanyPlikTekstowy.good()==true && idUsuwanegoAdresata!=0 ) {

        while (getline( odczytywanyPlikTekstowy, wczytanaLinia)) {

            idAdresataZPliku=pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
            if (idAdresataZPliku == idUsuwanegoAdresata) {}
            else if (idAdresataZPliku == 1 && idAdresataZPliku != idUsuwanegoAdresata)  {
                tymczasowyPlikTekstowy << wczytanaLinia;
            }

            else if (idAdresataZPliku == 2 && idUsuwanegoAdresata == 1)                 {
                tymczasowyPlikTekstowy << wczytanaLinia;
            }

            else if (idAdresataZPliku > 2 && idUsuwanegoAdresata == 1)                  {
                tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }

            else if (idAdresataZPliku > 1 && idUsuwanegoAdresata != 1)                  {
                tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }

        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunOdczytywanyPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);
    } else {
        cout<<"Nie udalo sie otowrzyc pliku\n";
    }

}

void PlikZAdresatami :: usunWybranaLinieWPliku(int numerUsuwanejLinii) {


    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && numerUsuwanejLinii != 0) {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia)) {
            // Tych przypadkow jest tyle, gdyz chcemy osiagnac taki efekt,
            // aby na koncu pliku nie bylo pustej linii
            if (numerWczytanejLinii == numerUsuwanejLinii) {}

            else if (numerWczytanejLinii == 1 && numerWczytanejLinii != numerUsuwanejLinii)
                tymczasowyPlikTekstowy << wczytanaLinia;
            else if (numerWczytanejLinii == 2 && numerUsuwanejLinii == 1)
                tymczasowyPlikTekstowy << wczytanaLinia;
            else if (numerWczytanejLinii > 2 && numerUsuwanejLinii == 1)
                tymczasowyPlikTekstowy << endl << wczytanaLinia;
            else if (numerWczytanejLinii > 1 && numerUsuwanejLinii != 1)
                tymczasowyPlikTekstowy << endl << wczytanaLinia;

            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunOdczytywanyPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);
    }
}

void PlikZAdresatami :: usunOdczytywanyPlik(string nazwaPlikuZRozszerzeniem) {
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami :: zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(string nazwaTymczasowegoPlikuZRozszerzeniem, string nazwaPlikuZRozszerzeniem) {
    if (rename(nazwaTymczasowegoPlikuZRozszerzeniem.c_str(), nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami :: aktulizacjaDanaychEdytowanegoAdresata (Adresat adresat, int idEdytowanegoAdresata) {//nowy sposob
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia="";
    string liniaZAktualizowanymAdresatem="";
    int idAdresataZPliku=1;
    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good()==true) {
        while (getline(odczytywanyPlikTekstowy,wczytanaLinia )) {
            idAdresataZPliku=pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
            if (idAdresataZPliku==adresat.pobierzId()) {
                liniaZAktualizowanymAdresatem=zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);
                if (idAdresataZPliku==1) {
                    tymczasowyPlikTekstowy<<liniaZAktualizowanymAdresatem;
                } else if (idAdresataZPliku>1) {
                    tymczasowyPlikTekstowy<<endl<<liniaZAktualizowanymAdresatem;
                }
            } else {
                if (idAdresataZPliku==1) {
                    tymczasowyPlikTekstowy<<wczytanaLinia;
                } else if (idAdresataZPliku>1) {
                    tymczasowyPlikTekstowy<<endl<<wczytanaLinia;
                }
            }
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();
    } else {
        cout<<"Nie udalo sie otworzyc pliku\n";
    }
    usunOdczytywanyPlik(NAZWA_PLIKU_Z_ADRESATAMI);
    zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);

}


///////////////////smieci
/*
void PlikZAdresatami :: zaktualizujDaneEdytowanegoAdresata(Adresat adresat, int idEdytowanegoAdresata) {

    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    numerLiniiEdytowanegoAdresata = zwrocNumerLiniiSzukanegoAdresata(idEdytowanegoAdresata);
    //cout<<"to jest numer linii: "<<numerLiniiEdytowanegoAdresata<< " ";
    //system("pause");
    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);
    //liniaZDanymiAdresata=pobierzLinieZPlikuAdresaci (numerLiniiEdytowanegoAdresata);
    cout<<"to jest caly jeden adresat: "<<liniaZDanymiAdresata<<" ";
    system("pause");
    edytujWybranaLinieWPliku(numerLiniiEdytowanegoAdresata, liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

string PlikZAdresatami :: pobierzLinieZPlikuAdresaci (int numerLinii) { // pobiera linie do zmiany danych adresata
    string wczytanaLinia= "";
    int aktualnieOdczytywanaNumerLinii=1;
    fstream odczytywanyPlikTekstowy;
    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (odczytywanyPlikTekstowy.good()==true) {

        while (getline (odczytywanyPlikTekstowy, wczytanaLinia)) {
            if (aktualnieOdczytywanaNumerLinii==numerLinii) {
                //cout<<"to jest aktualnie odczytwany numer linii: "<<aktualnieOdczytywanaNumerLinii<<"\n";//sprawdzenie
                //cout<<"to jest numer linii: "<<numerLinii<<"\n";//sprawdzenie
                //cout<<wczytanaLinia;//sprawdzenie
                //system("pause");//sprawdzenie
                odczytywanyPlikTekstowy>>wczytanaLinia;
                return wczytanaLinia;
            }
            aktualnieOdczytywanaNumerLinii++;
        }

        odczytywanyPlikTekstowy.close();
    } else {
        cout<<"Nie udalo sie otoworzyc pliku";
        //return 0;
    }
}

int PlikZAdresatami :: zwrocNumerLiniiSzukanegoAdresata(int idAdresata) {
    bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy;

    plikTekstowy.open (NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true && idAdresata != 0) {
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                czyIstniejeAdresat = true;
                plikTekstowy.close();
                return numerLiniiWPlikuTekstowym;
            } else
                numerLiniiWPlikuTekstowym++;
        }
        if (czyIstniejeAdresat = false) {
            plikTekstowy.close();
            return 0;
        }
    }
    return 0;
}


void PlikZAdresatami :: edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true) {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia)) {
            if (numerWczytanejLinii == numerEdytowanejLinii) {
                cout<<"to jest numer Wczytanej Linii: "<<numerWczytanejLinii<<"\n";//sprawdzenie
                cout<<"to jest numer Edytowanej Linii: "<<numerEdytowanejLinii<<"\n";//sprawdzenie
                system("pause");//sprawdzenie
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresataOddzielonePionowymiKreskami;
            }

            else {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }

            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunOdczytywanyPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);
    }
}
*/
