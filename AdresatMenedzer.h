#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata();
    void wyswietlIloscWyszukanychAdresatow();
    int podajIdWybranegoAdresata();
    char wybierzOpcjeZMenuEdycja();

    public:

    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami (nazwaPlikuZAdresatami)
    {
        {
            idZalogowanegoUzytkownika = 0;
        }
    };

    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wyszukajAdrastaowPoImieniu();

};
#endif
