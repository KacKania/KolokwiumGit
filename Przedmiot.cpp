#include "Przedmiot.h"
#include <cstring>
using namespace std;

Przedmiot wypelnijPrzedmiot(const char* nazwa, sztukiZlota wartosc, TypRzadkosci typ, Magic efektyMagiczne) {
    Przedmiot nowy;
    strncpy_s(nowy.nazwa, nazwa, ROZMIAR_TXT);
    nowy.nazwa[ROZMIAR_TXT] = '\0';
    nowy.wartosc = wartosc;
    nowy.rzadkosc = typ;

    nowy.efektyMagiczne = efektyMagiczne;
    return nowy;
}

std::ostream& operator<<(ostream& str, const Przedmiot& p)
{
    static const char* NAZWY_TYPOW_RZADKOSCI[] = { "Pospolity","Niecodzienny","Rzadki","Unikatowy" };
    str << "\"" << p.nazwa << "\"" << " [" << p.wartosc << "]" << " {"
        << NAZWY_TYPOW_RZADKOSCI[(int)p.rzadkosc] << "}";
    return str;
}



const char* efektOgnia(int punkty_many) {
    if (punkty_many == 0 && punkty_many<0) {
        return "fireball";
    }
    else if (punkty_many == 1) {
        return "maly plomien";
    }
    else if (punkty_many == 2) {
        return "duza kula ognia";
    }
    else {
        return "Ognista apokalipsa";
    }
}

const char* efektLeczenia(int punkty_many) {
    if (punkty_many == 0 && punkty_many < 0) {
        return "apteczka";
    }
    else if (punkty_many == 1) {
        return "maly opatrunek";
    }
    else if (punkty_many == 2) {
        return "duzy opatrunek";
    }
    else {
        return "Adrenalina";
    }
}


