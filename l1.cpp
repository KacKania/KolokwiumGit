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
#include "Przedmiot.h"

using namespace std;
std::ostream& operator<<(ostream& str, const Przedmiot& p);

//te same efekty ognia + te same efekty =4
int zliczaniePrzedmiot(Przedmiot skarbiec[], int rozmiar)
{
    int licznik = 0;

    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = i + 1; j < rozmiar; j++) 
        {
            if (skarbiec[i].efektyMagiczne == skarbiec[j].efektyMagiczne) 
            {
                licznik++;
            }
        }
    }
    return licznik;
}


int zliczanie(Przedmiot skarbiec[], int rozmiar)
{
    int licznikOgien = 0;
    int licznikLeczenie = 0;
    for (int i = 0; i < rozmiar; i++)
    {
        if (skarbiec[i].efektyMagiczne == efektOgnia)
        {
            licznikOgien = licznikOgien +1;
        }
        else if (skarbiec[i].efektyMagiczne == efektLeczenia)
        {
            licznikLeczenie = licznikLeczenie + 1;
        }
    } if (licznikOgien >= licznikLeczenie)
    {
        cout << "wiecej jest ognia : ";
        return licznikOgien;
    }
    else
    {
        cout << " wiecej jest leczenia: ";
        return licznikLeczenie;
    }
}




int main()
{
    int rozmiar = 5;

    Przedmiot wisiorek = wypelnijPrzedmiot("Amulet zaliczenia warunkowego ;)", 100, TypRzadkosci::unikatowa, efektOgnia);
    Przedmiot miecz = wypelnijPrzedmiot("Miecz super ostry", 50, TypRzadkosci::niecodzienna, efektOgnia);
    Przedmiot zbroja = wypelnijPrzedmiot("ciezki pancerz", 200, TypRzadkosci::rzadka, efektLeczenia);
    Przedmiot tarcza = wypelnijPrzedmiot("Nasusa)", 200, TypRzadkosci::unikatowa, efektLeczenia);
    Przedmiot buty = wypelnijPrzedmiot("Buty wiatru)", 70, TypRzadkosci::popspolita, efektLeczenia);

    // wyświetlenie przedmiotów
    cout << wisiorek << efektOgnia(1) << endl;
    cout << miecz << efektOgnia(2) << endl;
    cout << zbroja << efektLeczenia(2) << endl;
    cout << tarcza << efektLeczenia(3) << endl;
    cout << buty << efektOgnia(0) << endl << endl;

    Przedmiot skarbiec[] = {

    wisiorek,miecz, zbroja, tarcza, buty
        
    };
        
    for (int i = 0; i < 5; i++)
    {
        
        cout << skarbiec[i] << skarbiec[i].efektyMagiczne(skarbiec[i].punkty_many);

        cout << endl;


    }
    cout << endl;
    cout << "Liczba przedmiotow o takich samych efektach: ";
    cout << zliczaniePrzedmiot(skarbiec, rozmiar);
    cout << endl;
    cout << zliczanie(skarbiec, rozmiar);

    return 0;
}

#endif

#ifdef ZadanieW


//#include "fun.h"



/*int main()
{
    const int rozmiar = 22;
    int tablica[rozmiar] = {};

    cout << funkcja(tablica, 5, 3, 2) << endl;
    cout << funkcja(tablica, 5, 2, 5) << endl;
    cout << funkcja(tablica, 5, 2, 4) << endl;
    cout << funkcja(tablica, 4, 1, 4) << endl;
    cout << funkcja(tablica, 3, 1, 5) << endl;


    return 0;
}*/

#endif

#ifdef ZadanieP

#include <iostream>
#include "wstawianie.h"

using namespace std;

int algorytmSort2d()
{

    int wiersz = 4;
    int kolumna = 2;
    int tab[wiersz][kolumna] = { {1,2,3,5,4},{4,2,3,1,5},{2,2,1,4,4} };

}

void wpisz(double(*tab)[NUM], int kolumna, int wiersze)
{
    if (wiersze == null)
    {
        wiersze = 10;
    }

    if (wiersze % 2 == 0 || wiersze == 0)
    {
        sortowanieWstawianieTest();
    }
    else
    {
        quicksort();
    }

}



int main()
{
    sortowanieWstawianieTest();
  
    
   

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


