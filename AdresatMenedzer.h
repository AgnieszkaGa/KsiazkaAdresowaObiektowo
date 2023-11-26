#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "Uzytkownik.h"

using namespace std;

class AdresatMenedzer
{
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat &adresat);
    MetodyPomocnicze metodyPomocnicze;
    //char wybierzOpcjeZMenuEdycja();



    public:

    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami (nazwaPlikuZAdresatami)
    {
            idZalogowanegoUzytkownika = 0;
    };

     void ustawIdZalogowanegoUzytkownika(int noweId)
    {
        idZalogowanegoUzytkownika = noweId;
    }

    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void dodajAdresata();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlWszystkichAdresatow();

};
#endif
