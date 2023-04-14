#ifndef Przedmiot_h
#define Przedmiot_h


#include <iostream>

constexpr size_t ROZMIAR_TXT = 200;
using text = char[ROZMIAR_TXT + 1];
using sztukiZlota = int;



using Magic = const char* (*)(int);

enum class TypRzadkosci {
    popspolita,
    niecodzienna,
    rzadka,
    unikatowa
};

struct Przedmiot
{
    text nazwa;
    sztukiZlota wartosc;
    TypRzadkosci rzadkosc;
    Magic efektyMagiczne;
    int punkty_many;
    // text(*efekt)(int);
};
using Magic = const char* (*)(int);
Przedmiot wypelnijPrzedmiot(const char* nazwa, sztukiZlota wartosc, TypRzadkosci typ, Magic efektyMagiczne);

const char* efektOgnia(int punkty_many);
const char* efektLeczenia(int punkty_many);





#endif 
