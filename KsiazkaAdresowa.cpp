#include "KsiazkaAdresowa.h"
#include "UzytkownikMenedzer.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
  //  uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

 void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
 {
     uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
 }

int KsiazkaAdresowa::logowanieUzytkownika()
 {
     int idZalgowanegoUzytkownia = uzytkownikMenedzer.logowanieUzytkownika();
     if (idZalgowanegoUzytkownia >0)
     {uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(idZalgowanegoUzytkownia);
    // uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
 }
 return idZalgowanegoUzytkownia;
 }
     /*uzytkownikMenedzer.logowanieUzytkownika();
     po zalogowaniu UzytkownikMenedzer powinien pobrac swoje idZalogowanegoUzytkownika przy pomocy getter
      - czyli trzeba swtworzyc w klasie UzytkownikMenedzer getter dla pola idZalogowanegoUzytkownika
      i przy pomocy settera ustawic je w klasie (i setter dla analogicznego pola idZalogowanegoUzytkownika w klasie AdresatManager)

     - w klasie AdresatMenager stworzyc publicznametode pobierzAdresatowZalogowanegoUzytkownikaZPliku() i wywola ja w metodzie lgowanie Uzytkownika
     w klasie Ksiazka Adresowa - gdy id ZalgowoanegoUzytkownika w klasie AdresatMenager bedzie juz ustawione

     adrestaMenedzer.pobierzAdresatowZalogowanegoUzytkownikaZPliku();

     // moze byc tez adresatMenedzer.dodajAdresata();

 }*/

 /*void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
 {
     uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
 }*/
