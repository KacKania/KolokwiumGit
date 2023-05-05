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
#include <cstdio>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

//kod z zad. przykladowego B
int ileLiczb(FILE* plik)
{
    int wynik = 0;
    if (plik != nullptr)
    {
        rewind(plik);
        while (true)
        {
            double liczba;
            fscanf_s(plik, "%lf;", &liczba);
            if (feof(plik)) return wynik;
            else wynik++;
        }
    }
}

//ile liczb z fget_s
int ileLiczbNowaLinia(FILE* plik)
{
    constexpr size_t ROZMIAR = 100;
    int wynik = 1;
    char tekst[ROZMIAR] = {};
    if (plik != nullptr)
    {
        rewind(plik);
        while (true)
        {
            fgets(tekst, ROZMIAR, plik);
            if (feof(plik)) return wynik;
            else wynik++;
        }
    }
}

// cennik dystans
/*const int TabOdleglosc[][2] =
{
    {100, 5},
    {500, 10},
    {1000, 15},
};*/

// opcje szybkosci
/*const char* TabOpcjeSzybkosc[] =
{
    "do 7 dni",
    "do 4 dni",
    "do 2 dni",
};*/

//ceny na podstawie szybkosci
/*const int TabCenaSzybkosc[] =
{
    2,
    4,
    6,
};*/




int main()
{
    FILE* plikSzybkosc;
    fopen_s(&plikSzybkosc, "szybkosc.txt", "r");

    int rozmiarSzybkosc = ileLiczb(plikSzybkosc);
    double* TabCenaSzybkosc = new(std::nothrow) double[rozmiarSzybkosc] {};


    if (plikSzybkosc != nullptr && TabCenaSzybkosc != nullptr)
    {
        rewind(plikSzybkosc);

        int indeks = 0;
        while (true)
        {
            fscanf_s(plikSzybkosc, "%lf;", TabCenaSzybkosc + indeks);
            if (feof(plikSzybkosc)) break;
            indeks++;
        }
    }
    fclose(plikSzybkosc);



    setlocale(LC_ALL, "");
    constexpr size_t ROZMIAR = 100;
    FILE* plikOpcje;
    fopen_s(&plikOpcje, "opcje.txt", "r");


    int rozmiarOpcje = ileLiczbNowaLinia(plikOpcje);
    char** TabOpcjeSzybkosc = new(std::nothrow) char* [rozmiarOpcje] {};

    rewind(plikOpcje);
    int indeks = 0;
    while (true)
    {
        TabOpcjeSzybkosc[indeks] = new char[ROZMIAR];
        fgets(TabOpcjeSzybkosc[indeks], ROZMIAR, plikOpcje);
        if (TabOpcjeSzybkosc[indeks][strlen(TabOpcjeSzybkosc[indeks]) - 1] == '\n')
            TabOpcjeSzybkosc[indeks][strlen(TabOpcjeSzybkosc[indeks]) - 1] = '\0'; // usuwanie znaku nowej linii


        if (feof(plikOpcje)) break;
        indeks++;
    }
    fclose(plikOpcje);




    setlocale(LC_ALL, "");
    FILE* plikDystans;
    fopen_s(&plikDystans, "dystans.txt", "r");

    int rozmiarDystans = ileLiczbNowaLinia(plikDystans);
    int** TabOdleglosc = new(std::nothrow) int* [rozmiarDystans];
    rewind(plikDystans);
    int indeks2 = 0;
    char tekst[100];
    while (true)
    {
        // fscanf_s(plikSzybkosc, "%lf;", TabCenaSzybkosc + indeks);
        // TabOdleglosc[indeks] = new char[ROZMIAR];
        fgets(tekst, ROZMIAR, plikDystans);
        string wartosc = string(tekst);
        string::size_type pos = wartosc.find(';');

        int ii = stoi(wartosc.substr(0, pos));
        int jj = stoi(wartosc.substr(pos + 1));

        for (int i = 0; i < rozmiarDystans; i++)
        {
            TabOdleglosc[i] = new int[2] {};
            TabOdleglosc[i][0] = ii;
            TabOdleglosc[i][1] = jj;
        }

        if (feof(plikDystans)) break;
        indeks2++;
    }
    fclose(plikDystans);


    const int NumerOdleglosc = sizeof(TabOdleglosc) / sizeof(TabOdleglosc[0]);

    //wyswietlanie TabOdleglosc
    std::cout << "|CENNIK NA PODSTAWIE ODLEGLOSCI|" << endl << endl;
    for (int i = 0; i < NumerOdleglosc; i++)
    {
        int odleglosc = TabOdleglosc[i][0];
        int CenaOdleglosc = TabOdleglosc[i][1];
        std::cout << i + 1 << " : " << odleglosc << " KM - " << CenaOdleglosc << " PLN" << endl;
    }

    std::cout << endl;

    //wyswietlanie Tab szybkosc dostawy
    for (int i = 0; i < rozmiarOpcje; i++) {
        char* OpcjeSzybkosc = TabOpcjeSzybkosc[i];
        int CenaSzybkosc = TabCenaSzybkosc[i];
        std::cout << i + 1 << " : " << OpcjeSzybkosc << " - " << CenaSzybkosc << " PLN" << endl;
    }

    //wybieranie opcji (uzytkownik)
    std::cout << endl;
    int odleglosc, Szybkosc;
    std::cout << "Podaj odleglosc (KM): ";
    std::cin >> odleglosc;
    int PomOdlegosc = 0;
    //sprawdzenie odleglosci
    if (odleglosc <= 0 || odleglosc > 1000)
    {
        std::cout << "Niepoprawna odleglosc" << endl;
        return 0;
    }

    for (int i = 0; i < NumerOdleglosc; i++)
    {
        if (odleglosc <= TabOdleglosc[i][0])
        {
            PomOdlegosc = TabOdleglosc[i][1];
            break;
        }
    }

    std::cout << endl << "Wybierz opcje dostawy (wpisz numer): ";
    std::cin >> Szybkosc;

    //obliczanie ceny
    if (Szybkosc < 1 || Szybkosc > rozmiarDystans)
    {
        std::cout << "Niepoprawny numer opcji" << endl;
    }
    else
    {
        int CenaSzybkosc = TabCenaSzybkosc[Szybkosc - 1];
        float CenaDostawy = PomOdlegosc * CenaSzybkosc;
        std::cout << endl << "Cena dostawy: " << CenaDostawy << " PLN" << endl;
    }

    return 0;
}


#endif

#ifdef ZadanieW
#include <iostream>
#include <cstdio>
#include <string>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct Punkt
{
    double x;
    double y;
};

void ZapPlik(Punkt punkty[], int rozmiar, const char* nazwa_pliku)
{

    FILE* plik;
    if (fopen_s(&plik, nazwa_pliku, "w") != 0)
    {
        printf("BLAD! NIE OTWORZYLO SIE: %s\n", nazwa_pliku);
        return;
    }



    for (int i = 0; i < rozmiar; i++)
    {
        fprintf(plik, "%.2f;%.2f\n", punkty[i].x, punkty[i].y);
    }

    fclose(plik);
    printf("Zapis do pilku: %s\n", nazwa_pliku);
}



Punkt CzytPlik(const char* nazwa_pliku, int n)
{
    Punkt punkt = { 0, 0 };

    FILE* plik;
    if (fopen_s(&plik, nazwa_pliku, "r") != 0)
    {
        printf("BLAD! NIE OTWORZYLO SIE: %s\n", nazwa_pliku);
        return punkt;
    }

    int licznik = 0;
    double x, y;



    while (fscanf_s (plik, "%lf;%lf", &x, &y) == 2 && !feof(plik))
    {
        licznik++;
        if (licznik == n) {
            punkt.x = x;
            punkt.y = y;
            break;
        }
    }



    fclose(plik);
    return punkt;
}




int main()
{
    Punkt punkty[5] = { {1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10} };

    ZapPlik(punkty, 5, "punkty.txt");

    int n;
    cout << "PODAJ NUMER DO ODCZYTU: ";
    cin >> n;

    Punkt punkt = CzytPlik("punkty.txt", n);

    printf("JEST TO PUNKT %d   x = %.2f,   y = %.2f\n", n, punkt.x, punkt.y);

    return 0;
}










#endif

#ifdef ZadanieP
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


enum class Plec
{
    Mezczyzna, Kobieta
};

enum class Stopien 
{
    I, II, III
};



struct Student 
{
    char imie[40];
    char nazwisko[60];
    Plec plec;
    Stopien stopien;
    int semester;
};

void Zapis(const char* filename, const Student& student)
{
    FILE* plik1 = nullptr;
    fopen_s(&plik1, filename, "wt");
    if (!plik1) {
        printf("NIE DZIALA");
        return;
    }

    //BITY (statcast) Konwertuje wyrażenie na typ identyfikatora typu na podstawie typów, które znajdują się w wyrażeniu.

    int zm = (student.semester & 0x7) | //ogranicz do 0-7 3bit
        ((static_cast<int>(student.stopien) & 0x3) << 3) |  //student.stopien ograniczoną do 2 bitów (czyli wartości od 0 do 3), które są przesunięte o 3 bity w lewo bo <<
        ((static_cast<int>(student.plec) & 0x1) << 5); //0x1, czyli 0001 + <<

    fprintf(plik1, "%d;%s;%s;%d\n", zm, student.imie, student.nazwisko);

    fclose(plik1);
}

void Czytaj(const char* filename, Student& student)
{
    FILE* plik2 = nullptr;
    fopen_s(&plik2, filename, "rt");
    if (!plik2) {
        printf("NIE DZIALA");
        return;
    }

    int zm;
    char imie[40];
    char nazwisko[60];

    fscanf_s(plik2, "%d;%40[^;];%60[^;];%d\n", &zm, imie, _countof(imie), nazwisko, _countof(nazwisko), &student.semester);

    student.plec = static_cast<Plec>((zm >> 5) & 0x1);
    student.stopien = static_cast<Stopien>((zm >> 3) & 0x3);
    student.semester =zm & 0x7;

    strcpy_s(student.imie, imie);
    strcpy_s(student.nazwisko, nazwisko);

    fclose(plik2);
}

int main()
{


    const char* imiep = "student.txt";
    Student student = { "Aleksander", "Szybki", Plec::Mezczyzna, Stopien::II, 1 };
    Zapis(imiep, student);

    Student czytajS;
    Czytaj(imiep,czytajS);



    printf ("imie: %s\n", czytajS.imie);
    printf ("naziwksko: %s\n", czytajS.nazwisko);
    printf ("plec: %s\n", czytajS.plec == Plec::Mezczyzna ? "Mezczyzna" : "Kobieta");
    printf ("stopien: %d\n", static_cast<int>(czytajS.stopien));
    printf ("Semester: %d\n", czytajS.semester);

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


