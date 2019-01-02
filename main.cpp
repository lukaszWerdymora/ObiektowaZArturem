#include <iostream>
#include "KsiazkaAdresowa.h"
using namespace std;

int main()
{

    KsiazkaAdresowa ksiazkaadresowa ("Uzytkownicy1.txt");
    ksiazkaadresowa.wypiszWszystkichUzytkonikow();
    ksiazkaadresowa.rejestracjaUzytkownika();
    //ksiazkaadresowa.rejestracjaUzytkownika();
    ksiazkaadresowa.wypiszWszystkichUzytkonikow();
    return 0;
}
