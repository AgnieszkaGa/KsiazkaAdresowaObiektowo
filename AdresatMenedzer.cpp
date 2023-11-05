#include "AdresatMenedzer.h"
#include "PlikZAdresatami.h"

void AdresatMenedzer::pobierzAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();

}

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{

}

/*void AdresatMenedzer::dodajAdresata()
{
    int dodajAdresata( int idZalogowanegoUzytkownika, int idOstatniegoAdresata)

    Adresat adresat;
    system("cls");

    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
    adresaci.push_back(adresat);
    dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;

}*/
