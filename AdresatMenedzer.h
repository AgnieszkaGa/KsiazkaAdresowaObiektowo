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


    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);

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

    void pobierzAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int dodajAdresata();


    void dopiszAdresataDoPliku(Adresat adresat);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);

    void wyswietlWszystkichAdresatow();
    void wyszukajAdrastaowPoImieniu();

};
#endif
