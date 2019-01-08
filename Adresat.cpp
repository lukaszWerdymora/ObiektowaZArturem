#include "Adresat.h"

void Adresat :: ustawId (int nowyId){
    id=nowyId;
}
void Adresat :: ustawIdUzytkownika (int nowyIdUzytkownika){
    idUzytkownika=nowyIdUzytkownika;
}

void Adresat :: ustawImie (string noweImie){
    imie=noweImie;
}
void Adresat :: ustawNazwisko (string noweNazwisko){
    nazwisko=noweNazwisko;
}
void Adresat :: ustawNumerTelefonu (string nowyNumerTelefonu){
    numerTelefonu=nowyNumerTelefonu;
}
void Adresat :: ustawEmail (string nowyEmail){
    email=nowyEmail;
}
void Adresat :: ustawAdres (string nowyAdres){
    adres=nowyAdres;
}

int Adresat :: pobierzId(){
    return id;
}
int Adresat :: pobierzIdUzytkownika (){
    return idUzytkownika;
}
string Adresat :: pobierzImie (){
    return imie;
}
string Adresat :: pobierzNazwisko(){
    return nazwisko;
}
string Adresat :: pobierzNumerTelefonu(){
    return numerTelefonu;
}
string Adresat :: pobierzEmail(){
    return email;
}
string Adresat :: pobierzAdres(){
    return adres;
}

/*




*/
