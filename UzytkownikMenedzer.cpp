#include "UzytkownikMenedzer.h"
#include "PlikZUzytkownikami.h"
#include "Uzytkownik.h"


void UzytkownikMenedzer::rejestracjaUzytkownika() {

    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustawId (pobierzIdNowegoUzytkownika());

   string login;


    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;

    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika(){

    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login) {

    for (size_t i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }
    return false;
}

int UzytkownikMenedzer::pobierzId(){

    if (czyUzytkownikJestZalogowany())
    {
        return idZalogowanegoUzytkownika;
        cout << "Pokaz id zalogowanegouzytkownika w Uzytkownikamenedzer :: " << idZalogowanegoUzytkownika << endl;
    }
    else { cout << "Brak zalogowanego uzytkownika" << endl;
    return 0;
    }
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow() {

    for (size_t i = 0; i < uzytkownicy.size(); i++)
    {
          cout << " Id uzytkownika " << uzytkownicy[i].pobierzId() << endl;
          cout << " Login uzytkownika " << uzytkownicy[i].pobierzLogin() << endl;
          cout << " Haslo uzytkownika " << uzytkownicy[i].pobierzHaslo() << endl << endl;
    }
    system("pause");
}

 void UzytkownikMenedzer::wczytajUzytkownikowZPliku() {

   uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

int  UzytkownikMenedzer::logowanieUzytkownika() {

    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    cin >> login;

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> haslo;

                if (itr -> pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    return idZalogowanegoUzytkownika;
                }
            }

            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika() {

    Uzytkownik uzytkownik;

    uzytkownik.ustawId (pobierzIdNowegoUzytkownika());
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenedzer::wylogowanieUzytkownika() {

    idZalogowanegoUzytkownika = 0;
    cout << " Wylogowano " << endl;
    //uzytkownicy.clear();
    system("pause");
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany() {

    if (idZalogowanegoUzytkownika > 0)
    {
        cout << "Uzytkownik jest zalogowany " << endl;
        return true;
    }
    else
    {
        cout << "Nie jest zalogowany " << endl;
        return false;
    }

}



