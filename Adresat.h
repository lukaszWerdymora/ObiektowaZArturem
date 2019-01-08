#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat {
    int id, idUzytkownika;
    string imie, nazwisko, numerTelefonu, email, adres;
public:
    void ustawId            (int noweId);
    void ustawIdUzytkownika (int nowyIdUzytkownika);
    void ustawImie          (string noweImie);
    void ustawNazwisko      (string noweNazwisko);
    void ustawNumerTelefonu (string nowyNumerTelefonu);
    void ustawEmail         (string nowyEmail);
    void ustawAdres         (string nowyAdres);

    int pobierzId();
    int pobierzIdUzytkownika();
    string pobierzImie ();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();

};
#endif // ADRESAT_H
