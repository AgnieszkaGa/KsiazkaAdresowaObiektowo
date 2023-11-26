#include <fstream>
#include <algorithm>
#include "AdresatMenedzer.h"
#include "PlikZAdresatami.h"
#include "Adresat.h"
#include "MetodyPomocnicze.h"

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku(){

   adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

void AdresatMenedzer::dodajAdresata(){

    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
    cout << "Adresat dodany." << endl;
    system ("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(){

    Adresat adresat;

    string imie = "", nazwisko = "", numerTelefonu = "", email  = "", adres = "";

    adresat.ustawId (plikZAdresatami.getIdOstatniegoAdresata () + 1);
    adresat.ustawIdUzytkownika (idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
  // cin >> imie;
    cin.ignore();
    imie = metodyPomocnicze.wczytajLinie();
    imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);

     cout << "Podaj nazwisko: ";
    //cin >> nazwisko;
    nazwisko = metodyPomocnicze.wczytajLinie();
    nazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    numerTelefonu = metodyPomocnicze.wczytajLinie();
    adresat.ustawNumerTelefonu(numerTelefonu);

    cout << "Podaj email: ";
    //cin >> email;
    email = metodyPomocnicze.wczytajLinie();
    adresat.ustawEmail (email);

    cout << "Podaj adres: ";
   // cin >> adres;
    adres = metodyPomocnicze.wczytajLinie();
    adresat.ustawAdres(adres);

    return adresat;
}

string AdresatMenedzer::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst){

    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

void AdresatMenedzer::wyswietlDaneAdresata( Adresat &adresat){

    cout << endl << "Id:         " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()  {

     adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);

    system("cls");
    if (!adresaci.empty())
        {

        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;

        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }}

    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}
