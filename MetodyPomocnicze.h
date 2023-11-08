#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>

#include "Uzytkownik.h"

using namespace std;

class MetodyPomocnicze
{
  public:
    static string konwerjsaIntNaString(int liczba);
    static int konwersjaStringNaInt(string liczba);

};
#endif
