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
        cout<<"Nie uda�o si� otowrzyc pliku";
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

