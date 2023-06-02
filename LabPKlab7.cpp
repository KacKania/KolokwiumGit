#include <iostream>

#define ZadanieW

/* Zmieniając ostatnią literę w poniższej instrukcji na D (dodatkowe), lub P (podstawowe)
*  wybierasz aktywne zadanie.
*
*  UWAGA: jeśli rozwiązanie zadań wymaga podziału programu na pliki to dodaj je wszystkie do
*  projektu, ale przy każdym zadaniu "includuj" tylko te, które jego dotyczą.
*  Poniższe bloki dotyczą zadań z zajeć.
*/
 

#ifdef ZadanieD

#include <iostream>
#include <cstring>
#include <string>
#include "naglowek.h"
using namespace std;

int main()
{
    // sejf z 1 uprawnionym uzytkown
    Osoba uprawniony1;
    Sejf sejf(&uprawniony1);

    // Zapis i odczyt danych przez uprawnioną osobę
    sejf.zapisDanych(0, 1, &uprawniony1);
    int odczytaneDane = sejf.odczytajDane(0, &uprawniony1);
    cout << "Odczytane dane: " << odczytaneDane << endl;

    // zapis i odczyt przez nieuprawnionego
    Osoba nieuprawniony;
    sejf.zapisDanych(1, 2, &nieuprawniony);
    int odczytaneDane1 = sejf.odczytajDane(1, &nieuprawniony);
    cout << "Odczytane dane przez kogos innego: " << odczytaneDane1 << endl;

    return 0;
}


#endif

#ifdef ZadanieW

#include <iostream>
#include <cstring>
#include <string>
#include "klasa.h"
using namespace std;


int main()
{
    Flota flota;

    // Dodaj samochody do floty
    SamochodCiezarowy samochod1(1, 3000, TypTowaru::ciekly, "SK21156");
    SamochodCiezarowy samochod2(2, 3500, TypTowaru::sypki, "SWD45445");
    SamochodCiezarowy samochod3(3, 7200, TypTowaru::paczkowany, "SRB20220");

    flota.dodajSamochod(&samochod1);
    flota.dodajSamochod(&samochod2);
    flota.dodajSamochod(&samochod3);

    // samochody z floty
    cout << "samochody floty: "<<endl;
    cout << flota;


    flota.usunSamochod(&samochod2);

    // sprawdzenie
    cout << "samochody po usunieciu: "<<endl;
    cout << flota;

    return 0;
}


#endif

#ifdef ZadanieP

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA PODSTAWOWEGO

#endif

#ifdef ZadanieA

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA AMBITNEGO

#endif

/* 
	Poniższe bloki warunkowe dotyczą zadań kolokwialnych.
	Oddając zadania z zajęć, skasuj poniższe bloki.
	Oddając zadania z kolokwium skasuj powyższe bloki.
*/


#ifdef Blok1

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA Z BLOKU 1

#endif

#ifdef Blok2

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA Z BLOKU 2

#endif

#ifdef Blok3

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA Z BLOKU 3

#endif

#ifdef Blok4

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA Z BLOKU 4

#endif


