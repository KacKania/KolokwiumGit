#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Zarowka
{
public:
    const char* producent;
    bool stan;
    int moc;

    Zarowka(const char* p, int m)
    {
        producent = p;
        moc = m;
    }

    virtual void wlacz()
    {
        stan = true;
    }

    void wylacz()
    {
        stan = false;
    }

    virtual double zuzycie()
    {
        if (stan)
        {
            return moc;
        }
        else
        {
            return 0;
        }
    }

    virtual void wyswietl()
    {
        cout << producent << " moc = " << moc << ", zuzycie = " << zuzycie();

        if (stan)
        {
            cout << ", wlaczona";
        }
        else
        {
            cout << ", wylaczona";
        }

        cout << endl;
    }
};

class ZarowkaSciemnialna : public Zarowka
{
public:
    int jasnosc;

    ZarowkaSciemnialna(const char* p, int m) : Zarowka(p, m) {

    }

    void wlacz() override
    {
        jasnosc = 1 + rand() % 100; //losuj od 1 do 100
        stan = true;
    }

    double zuzycie() override
    {
        return moc * jasnosc / 100.0;
    }

    void wyswietl() override
    {
        cout << producent << " moc = " << moc << ", zuzycie = " << zuzycie();

        if (stan)
        {
            cout << ", wlaczona";
        }
        else
        {
            cout << ", wylaczona";
        }

        cout << endl;
    }
};

class Pokoj
{
public:
    Zarowka** zarowki;
    int ile;

    Pokoj(Zarowka** z, int n)
    {
        zarowki = z;

        if (n < 0)
        {
            ile = 0;
        }
        else if (n > 10)
        {
            ile = 10;
        }
        else
        {
            ile = n;
        }
    }

    void wlacz()
    {
        for (int i = 0; i < ile; i++)
        {
            zarowki[i]->wlacz();
        }
    }

    void wylacz()
    {
        for (int i = 0; i < ile; i++)
        {
            zarowki[i]->wylacz();
        }
    }

    double zuzycie()
    {
        double zsuma = 0;

        for (int i = 0; i < ile; i++)
        {
            zsuma += zarowki[i]->zuzycie();
        }

        return zsuma;
    }

    void wyswietl()
    {
        cout << "Zarowki w pokoju" << endl;

        for (int i = 0; i < ile; i++)
        {
            zarowki[i]->wyswietl();
        }

        cout << "Pokoj zuzycie = " << zuzycie() << endl;
    }

};


int main()
{
    srand(time(0));

    const char* nazwa = "Philips";

    Zarowka z1(nazwa, 50);

    z1.wyswietl();

    z1.wlacz();

    z1.wyswietl();

    const char* nazwa1 = "Philips sciemnialna";

    ZarowkaSciemnialna zs1(nazwa1,40);

    zs1.wyswietl();

    zs1.wlacz();

    zs1.wyswietl();

    Zarowka* ztab[] = {&z1, &zs1};

    Pokoj p1(ztab, 2);

    p1.wylacz();

    p1.wyswietl();

    p1.wlacz();

    p1.wyswietl();
    

    return 0;
}
