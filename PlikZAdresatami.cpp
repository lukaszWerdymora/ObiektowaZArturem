#include "PlikZAdresatami.h"

PlikZAdresatami::PlikZAdresatami (){
    nazwaPlikuZAdresatami="Adresaci.txt";
}


vector <Adresat> PlikZAdresatami :: wczytajAdresatowZalogowanegoUzytkownikaZPliku( int idZalogowanegoUzytkownika )
{
    Adresat adresat;
    vector <Adresat> adresaci;
    int idOstatniegoAdresata;
    //int idZalogowanegoUzytkownika;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    //fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;

        plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        //return idOstatniegoAdresata;
        idOstatniegoAdresataZalogowanegoUzytkownika= idOstatniegoAdresata;
    }
    else
        //return 0;
        idOstatniegoAdresataZalogowanegoUzytkownika= 0;
        return adresaci;
}

int PlikZAdresatami :: pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze :: konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}
Adresat PlikZAdresatami :: pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                //adresat.id = atoi(pojedynczaDanaAdresata.c_str());
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                //adresat.idUzytkownika = atoi(pojedynczaDanaAdresata.c_str());
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                //adresat.imie = pojedynczaDanaAdresata;
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                //adresat.nazwisko = pojedynczaDanaAdresata;
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                //adresat.numerTelefonu = pojedynczaDanaAdresata;
                adresat.ustawAdres(pojedynczaDanaAdresata);

                break;
            case 6:
                //adresat.email = pojedynczaDanaAdresata;
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 7:
                //adresat.adres = pojedynczaDanaAdresata;
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

string PlikZAdresatami :: pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int PlikZAdresatami :: pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}


