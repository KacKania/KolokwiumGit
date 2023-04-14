#include <iostream>

#define ZadanieP

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
#include<cstdio>
#include <stdexcept>
using namespace std;

bool palindromWlasciwy(const char* tekst)
{
    // wyjatek 1
    if (tekst == nullptr)
    {
        throw domain_error("nullptr");
    }

    int dlugosc = 0;
    while (tekst[dlugosc] != '\0')
    {
        dlugosc++;
    }

    // wyjatek 2
    if (dlugosc > 20)
    {
        throw length_error("dlugosc ponad 20 znakow");
    }

    for (int i = 0; i < dlugosc / 2; i++)
    {
        // wyjatek 3
        if (!((tekst[i] >= 'A' && tekst[i] <= 'Z') || (tekst[i] >= 'a' && tekst[i] <= 'z')))
        {
            throw invalid_argument("znaki inne niz alfabet");
        }

        if (toupper(tekst[i]) != toupper(tekst[dlugosc - 1 - i]))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

// test jednostkowy 1
void testPalindromPotop()
{
    const char* tekst = "Potop";
    cerr << "Slowo: " << tekst << " ";

    try
    {
        if (palindromWlasciwy(tekst))
        {
            cerr << "PASSED - slowo jest palindromem" << endl;
        }
        else
        {
            cerr << "FAILED - slowo nie jest palindromem" << endl;
        }
    }
    catch (...)
    {
        cerr << "INTERUPTED - niespodziewany wyjatek" << endl;
    }
}

// test jednostkowy 2
void testPalindromProgramowanie()
{

    const char* tekst = "proGRAmowanie";
    cerr << "Slowo: " << tekst << " ";

    try
    {
        if (!palindromWlasciwy(tekst))
        {
            cerr << "PASSED - slowo nie jest palindromem" << endl;
        }
        else
        {
            cerr << "FAILED - slowo jest palindromem" << endl;
        }
    }
    catch (...)
    {
        cerr << "INTERUPTED - niespodziewany wyjatek" << endl;
    }
}

// wyjatek 1
void testPalindromNull()
{
    const char* tekst = nullptr;
    cerr << "Slowo: " << "' ' ";

    try
    {
        palindromWlasciwy(tekst);
        cerr << "FAILED - brak wyjatku " << endl;
    }
    catch (const std::domain_error& e)
    {
        cerr << "PASSED - wyjatek: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "INTERUPTED - zly typ wyjatku" << endl;
    }
}

// wyjatek 2
void testPalindromWyjatekDlugoscPow20()
{
    const char* tekst = "Potopgagagagagagagagag";
    cerr << "Slowo: " << tekst << " ";

    try
    {
        palindromWlasciwy(tekst);
        cerr << "FAILED - brak wyjatku " << endl;
    }
    catch (std::length_error& e)
    {
        cerr << "PASSED - wyjatek: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "INTERUPTED - zly typ wyjatku" << endl;
    }
}

// wyjatek 3
void testPalindromNiedozwoloneZnaki()
{
    const char* tekst = "11%dsxzc,.m++_";
    cerr << "Slowo: " << tekst << " ";

    try
    {
        palindromWlasciwy(tekst);
        cerr << "FAILED - brak wyjatku " << endl;
    }
    catch (invalid_argument& e)
    {
        cerr << "PASSED - wyjatek: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "INTERUPTED - zly typ wyjatku" << endl;
    }
}

int main(void) {
    testPalindromPotop();
    testPalindromProgramowanie();
    testPalindromNull();
    testPalindromWyjatekDlugoscPow20();
    testPalindromNiedozwoloneZnaki();
}
#endif

#ifdef ZadanieW

#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;



struct punkty {
    double x, y;
};


struct wspolczynniki {      //liniowa czyli ax+b
    double a, b;
};




wspolczynniki Flinowa(punkty punkt1, punkty punkt2)
{
    wspolczynniki funkcja;

    if (punkt1.x == punkt2.x)
    {
        cerr << "FAILED - TE SAME WSPOLCZYNNIKI " <<endl;
        
    }
    else
    {

        funkcja.a = (punkt2.y - punkt1.y) / (punkt2.x - punkt1.x);
        funkcja.b = punkt1.y - funkcja.a * punkt1.x;
        return funkcja;
    }
}


void test1() {
    punkty punkt1 = { 3.0, 4.5 };
    punkty punkt2 = { 5.0, 6.0 };
    wspolczynniki wynik = Flinowa(punkt1, punkt2);
    wspolczynniki oczekiwany = { 1.0, 1.0 };

    if (wynik.a == oczekiwany.a && wynik.b == oczekiwany.b)
    {
       cout << "passed - 1";
    }
    else {
       cerr << "failed - 1";
    }
}

void test2() {
    punkty punkt1 = { 1.0, 2.0 };
    punkty punkt2 = { 3.0, 4.0 };
    wspolczynniki wynik = Flinowa(punkt1, punkt2);

    if (wynik.a == 0.0 && wynik.b == 0.0)
    {
        cout << "passed - 2";
    }
    else {
        cerr << "failed - 2";
    }
}

void test3() {
    punkty punkt1 = { 1.0, 2.0 };
    punkty punkt2 = { 5.0, 2.0 };
    wspolczynniki wynik = Flinowa(punkt1, punkt2);

    if (wynik.a == 0.0 && wynik.b == 0.0)
    {
        cerr << "PASSED (3) " <<endl;
    }
    else {
        cerr << "FAILED (3)";
    }
}

int main() {
    test1();
    cout << endl;
    test2();
    cout << endl;
    test3();


return 0;
}
#endif

#ifdef ZadanieP

#include <iostream>
#include <stdexcept>
#include <cassert>
#include <assert.h>


using namespace std;

int wyszukajPierwsza(double* tablica, int rozmiar, double wartSzukana)
{
    // Sparwdzenie poprawności danych wejściowych:
    if (rozmiar < 1) throw std::length_error("rozmiar < 1");
    for (int index = 0; index < rozmiar; index++)
    {
        if (tablica[index] == wartSzukana)
            return index;  // Znaleziono pierwsze wystąpienie - przerywam
    }
    throw std::domain_error("Wratosc nie wystąpila");
}

int ileRazyZnak(const char* text, char znak)
{
    int liczbaWystapien = 0;
    while (*text)
        if (*text == znak) liczbaWystapien++;
    text++; // wskaznik tekst jest inkrementowany przedwczesnie przez co pierwszy znak nie zostanie zaliczony (slajd 40)
    return liczbaWystapien;
}


void test_wyszukajPierwsza_1() 
{
    double tab[] = { 1.0 };
    int rozmiar = sizeof(tab) / sizeof(tab[0]);
    double Szukana = 1.0;

    try
    {
        wyszukajPierwsza(tab, rozmiar, Szukana);
        cerr << "PASSED";
    }


    catch (domain_error)
    {
        cerr << " brak wart ";
    }
    catch (...)
    {
        cerr << "INTERUPTED - zly typ wyjatku" << endl;
    }

    
}


void test_wyszukajPierwsza_2()
{
    double tab[] = { 1.0, 2.0, 5.0, 9.0, 4.0 };
    int rozm = sizeof(tab) / sizeof(tab[0]);
    double Szukana = 2.0;
    
    try
    {
        wyszukajPierwsza(tab, rozm, Szukana);
        cerr << "PASSED";
    }


    catch (domain_error)
    {
        cerr << " brak wart ";
    }
    catch (...)
    {
        cerr << "INTERUPTED - zly typ wyjatku" << endl;
    }

   
   
}


void test_wyszukajPierwsza_3()
{
    double tab[] = {1.0};
    double rozmiar = -1.0;
    double Szukana = 1.0;
    try {
        wyszukajPierwsza(tab, rozmiar, Szukana);
        cerr << "ok";
    }
    catch (const std::length_error& ex)
    {
        cerr<<(std::string(ex.what()) == "rozmiar mniejszy od 1");
    }
}

void test_wyszukajPierwsza_4()
{
    double tab[] = { 1.0, 2.0, 3.0, 4.0, 6.0 };
    int rozmiar = sizeof(tab) / sizeof(tab[0]);
    double Szukana = 5.0;
    try
    {
        wyszukajPierwsza(tab, rozmiar, Szukana);
        cerr << "PASSED";
    }


    catch (domain_error)
    {
        cerr << " f4: brak wartosci ";
    }
    catch (...)
    {
        cerr << "INTERUPTED - zly typ wyjatku" << endl;
    }
}


int main()
{
    test_wyszukajPierwsza_1();
    cout << endl;
    test_wyszukajPierwsza_2();
    cout << endl;
     test_wyszukajPierwsza_3() ;
     cout << endl;
    test_wyszukajPierwsza_4() ;


    return 0;
}




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


