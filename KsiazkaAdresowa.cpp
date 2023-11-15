#include "KsiazkaAdresowa.h"
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"


void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
     uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
 }

int KsiazkaAdresowa::logowanieUzytkownika() {

     int idZalogowanegoUzytkownika = uzytkownikMenedzer.logowanieUzytkownika();

if (idZalogowanegoUzytkownika != 0) {
        adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
        menuUzytkownika(idZalogowanegoUzytkownika);  // Przekazujemy idZalogowanegoUzytkownika do menu
    }
    return idZalogowanegoUzytkownika;
 }

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {

 uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
 }

int KsiazkaAdresowa::dodajAdresata(int idZalogowanegoUzytkownika){

uzytkownikMenedzer.czyUzytkownikJestZalogowany();  //uzytkownikMenedzer.czyUzytkownikJestZalgoowany();

if (idZalogowanegoUzytkownika != 0)
     {
     return adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika);
     }

return adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){

    adresatMenedzer.wyswietlWszystkichAdresatow();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {

    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> wybor;

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {

    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    //cout << "2. Wyszukaj po imieniu" << endl;
   // cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
   // cout << "5. Usun adresata" << endl;
  //  cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "9. Wyswietl uzytkownikow" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> wybor;

    return wybor;
}

void KsiazkaAdresowa::menuUzytkownika(int idZalogowanegoUzytkownika) {

    char wybor;

    while (true) {
        wybor = wybierzOpcjeZMenuUzytkownika();

        switch (wybor) {
            case '1':
                dodajAdresata(idZalogowanegoUzytkownika);
                break;
            /*case '2':
                wyszukajPoImieniu();
                break;
            case '3':
                wyszukajPoNazwisku();
                break;*/
            case '4':
                wyswietlWszystkichAdresatow();
                break;
           /* case '5':
                usunAdresata();
                break;
            case '6':
                edytujAdresata();
                break;*/
            case '7':
                zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                 uzytkownikMenedzer.wylogowanieUzytkownika();
                return;
                case '9':
                 uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
                return;
            default:
                cout << "Niepoprawny wybor. Sprobuj ponownie." << endl;
                break;
        }
    }
}

void KsiazkaAdresowa::menuGlowne() {

    char wybor;

    while (true) {
        wybor = wybierzOpcjeZMenuGlownego();

        switch (wybor) {
            case '1':
                rejestracjaUzytkownika();
                break;
            case '2':
                logowanieUzytkownika();
                break;
            case '9':
                exit(0);
            default:
                cout << "Niepoprawny wybor. Sprobuj ponownie." << endl;
                break;
        }
    }
}
