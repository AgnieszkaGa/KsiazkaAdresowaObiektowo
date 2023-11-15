#include <iostream>

#include "KsiazkaAdresowa.h"
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt" );
    ksiazkaAdresowa.menuGlowne();

    return 0;
}
