#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
   // AdresatMenedzer adresatMenedzer; - prawidlowe rozwiazanie

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
     uzytkownikMenedzer.wczytajUzytkownikowZPliku();
};
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
   // void logowanieUzytkownika();

  // void dodajAdresata();
};
#endif
