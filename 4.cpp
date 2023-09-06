#include <iostream>
#include <fstream>

using namespace std;

class Komputer
{
private:
    int ram;
    int dysk;
    string rodzaj;
    int rdzenie;
    double czestotliwosc;
public:
    static Komputer* instancja;

    Komputer(int r, int d, string ro, int rd, double c) {
        ram = r;
        dysk = d;
        rodzaj = ro;
        rdzenie = rd;
        czestotliwosc = c;
    }

    Komputer()
    {
        ram = instancja->ram;
        dysk = instancja->dysk;
        rodzaj = instancja->rodzaj;
        rdzenie = instancja->rdzenie;
        czestotliwosc = instancja->czestotliwosc;
    }


    int get_ram()
    {
        return ram;
    }

    void set_ram(int r)
    {
        ram = r;
    }

    int get_dysk()
    {
        return dysk;
    }

    void set_dysk(int d)
    {
        dysk = d;
    }

    string get_rodzaj()
    {
        return rodzaj;
    }

    void set_rodzaj(string r)
    {
        rodzaj = r;
    }

    int get_rdzenie()
    {
        return rdzenie;
    }

    void set_rdzenie(int r)
    {
        rdzenie = r;
    }

    double get_czestotliwosc()
    {
        return czestotliwosc;
    }

    void set_czestotliwosc(double c)
    {
        czestotliwosc = c;
    }

    void wyswietl()
    {
        cout << "ram: " << ram << ", dysk: " << rodzaj << " " << dysk << ", procesor: " << rdzenie << " " << czestotliwosc << "Mhz" << endl;
    }
};

Komputer* Komputer::instancja = new Komputer(8, 4, "HDD", 3, 1.8);


char* wczytaj_plik(char* nazwa, int& r)
{
    ifstream plik(nazwa);

    if (!plik.is_open()) {
        return nullptr;
    }

    char c;
    int rozmiar = 0;
    char* tablica = nullptr;

    while (plik.get(c))
    {
        char* temp = new char[rozmiar + 1];

        for (int i = 0; i < rozmiar; i++) {
            temp[i] = tablica[i];
        }

        if (c == '\n')
        {
            temp[rozmiar] = ' ';
        }
        else
        {
            temp[rozmiar] = c;
        }

        delete[] tablica;
        tablica = temp;


        rozmiar++;
    }

    
    r = rozmiar;

    return tablica;
}

void wypisz(char* tablica, int rozmiar, int n)
{
    int l = 0;

    for (int i = 0; i < rozmiar; i++)
    {
        cout << tablica[i];
        l++;

        if (l==n)
        {
            cout << endl;
            l = 0;
        }
    }

    cout << endl;
}

void zwolnij(char* tablica)
{
    delete[] tablica;
}

int main()
{
    Komputer* k1 = new Komputer(8, 2, "HDD", 2, 2.5);

    k1->wyswietl();

    Komputer::instancja->set_czestotliwosc(1.9);

    Komputer* k2 = new Komputer();

    k2->wyswietl();

    cout << "Zad 2" << endl;

    char nazwa[] = "plik.txt";

    int rozmiar;

    char* tab = wczytaj_plik(nazwa,rozmiar);

    for (int i = 0; i < rozmiar; i++) {
        cout << tab[i];
    }
    cout << endl;

    cout << "Zad 2.2" << endl;

    wypisz(tab, rozmiar, 4);

    zwolnij(tab);
    
    cout << "Zad 2.3" << endl;

    cout << tab[5] << endl;


    return 0;
}
