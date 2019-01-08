#include "AdresatMenadzer.h"

//musi byc konstruktor
/*
AdresatMenadzer :: AdresatMenadzer(){

}
*/
void AdresatMenadzer :: wczytajAdresatowZalogowanegoUzytkownikaZPliku ( int idZalogowanegoUzytkownika){
    adresaci=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku ( idZalogowanegoUzytkownika);
}

void AdresatMenadzer :: wypiszAdresatowZalogowanegoUzytkownika(){
    for (int i=0; i<adresaci.size(); i++){
        cout<<adresaci[i].pobierzId()<<'|';
        cout<<adresaci[i].pobierzImie()<<'|';
        cout<<adresaci[i].pobierzNazwisko()<<'|';
        cout<<adresaci[i].pobierzAdres()<<'|';
        cout<<adresaci[i].pobierzNumerTelefonu()<<'|';
        cout<<adresaci[i].pobierzEmail()<<'|'<<endl;
    }
}
/*
    for (int i=0; i<uzytkownicy.size(); i++) {

        cout<<uzytkownicy[i].pobierzId()<<'|';
        cout<<uzytkownicy[i].pobierzLogin()<<'|';
        cout<<uzytkownicy[i].pobierzHaslo()<<'|'<<endl;

    }
    */
void AdresatMenadzer :: dodajAdresataDoVectora (int idZalogowanegoUzytkownika){
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

/*
void ustawId            (int noweId);
    void ustawIdUzytkownika (int nowyIdUzytkownika);
    void ustawImie          (string noweImie);
    void ustawNazwisko      (string noweNazwisko);
    void ustawNumerTelefonu (string nowyNumerTelefonu);
    void ustawEmail         (string nowyEmail);
    void ustawAdres         (string nowyAdres);

*/
