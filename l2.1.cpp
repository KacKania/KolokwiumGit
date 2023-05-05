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
#include <string>
#include <cstring>

using namespace std;

constexpr size_t TEXT_LENGHT = 5;
using tekst = char[TEXT_LENGHT];

class Autor
{
public:
    const char* inicjaly() { return getInicjaly; }
    void setInicjaly(const char* inicjaly)
    {
        strncpy_s(getInicjaly, inicjaly, 4);
        
    }
private:
    tekst getInicjaly = "";
};

class Fotografia 
{

private:
    Autor getAutor;
    unsigned int getSzerokosc;
    unsigned int getWysokosc;
    unsigned int getRok;
    unsigned int getMiesiac;
    unsigned int getDzien;
    unsigned int getGodzina;
    unsigned int getMinuta;
    unsigned int getSekunda;

private:  unsigned int wymiar()  { return getSzerokosc * getWysokosc; }

public:
  
    //Getery:
    Autor autor()  { return getAutor; }
    unsigned int szerokosc()  { return getSzerokosc; }
    unsigned int wysokosc()  { return getWysokosc; }
    unsigned int rok()  { return getRok; }
    unsigned int miesiac()  { return getMiesiac; }
    unsigned int dzien()  { return getDzien; }
    unsigned int godzina()  { return getGodzina; }
    unsigned int minuta()  { return getMinuta; }
    unsigned int sekunda()  { return getSekunda; }

    //Setery:
    void setAutor(Autor autor)
    {
        getAutor = autor;
    }

    void setData(unsigned int rok, unsigned int miesiac, unsigned int dzien)
    {
        getRok = rok;
        getMiesiac = miesiac;
        getDzien = dzien;
    }

    void setGodzina(unsigned int godzina, unsigned int minuta, unsigned int sekunda)
    {
        getGodzina = godzina;
        getMinuta = minuta;
        getSekunda = sekunda;
    }

    void setWymiar(unsigned int szerokosc, unsigned int wysokosc) 
    {
        if (szerokosc > 0) {
            getSzerokosc = szerokosc;
        }
        else {
            getSzerokosc = 1;
        }

        
        if (wysokosc > 0) {
            getWysokosc = wysokosc;
        }
        else {
            getWysokosc = 1;
        }

    }

    double rozmiar(unsigned int BitNaPx) 
    {
        unsigned int liczba_pikseli = wymiar();
        unsigned int rozmiar_piksla_bajty = BitNaPx / 8;
        unsigned int rozmiar_bajty = liczba_pikseli * rozmiar_piksla_bajty + 720;
        return static_cast<double>(rozmiar_bajty) / (1024 * 1024);
    }
};
std::ostream& operator<<(ostream& os,  Fotografia& f)
{
    os << f.autor().inicjaly() << ": " << f.szerokosc() << "x" << f.wysokosc() << " [" << f.godzina() << ":" << f.minuta() << " " << f.dzien() << "/" << f.miesiac() << "/" << f.rok() << "] - ";
    os.precision(3);
    os << fixed << f.rozmiar(24) << " MB";
    return os;
}

int main() 
{
    Autor autor;
    autor.setInicjaly("JK");
    Fotografia foto;
    foto.setAutor(autor);
    foto.setData(2023, 4, 27);
    foto.setGodzina(16, 31,21);
    foto.setWymiar(1920, 1080);
    cout << foto << endl;

    foto.setWymiar(1280, 720);
    cout << foto << endl;

    return 0;
}


#endif

#ifdef ZadanieW

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;


class Ulamek
{
private:
    int m_licznik;
    int m_mianownik;

public:
    Ulamek(int licznik = 0, int mianownik = 1) : m_licznik(licznik), m_mianownik(mianownik)
    {
        if (m_mianownik < 0)
        {  // zmienic znak ulamka
            m_licznik = -m_licznik;
            m_mianownik = -m_mianownik;
        }
        if (m_mianownik == 0) // nie przez 0
        { 
            cout << "Blad: mianownik nie moze byc rowny zero" << endl;
            m_licznik = 0;
            m_mianownik = 1;
        }
    }
    // unsigned int szerokosc()  { return getSzerokosc; }
    int getLicznik()
    {
        return m_licznik;
    }

    int getMianownik() const
    {
        return m_mianownik;
    }

    void setLicznik(int licznik)
    {
        m_licznik = licznik;
    }

    void setMianownik(int mianownik)
    {
        if (mianownik > 0) {
            m_mianownik = mianownik;
        }
        else if (mianownik < 0) {
            m_licznik = -m_licznik; //albo abs
            m_mianownik = -mianownik;
        } else
        {
            cout << "Blad: mianownik nie moze byc rowny zero" << endl;
        }
    }

    double naPrzecinek()
    {
        return static_cast<double>(m_licznik) / static_cast<double>(m_mianownik);
    }

    void wypiszWlasciwy() 
    {
        int calkowita = m_licznik / m_mianownik;
        int reszta = m_licznik % m_mianownik;
        cout << calkowita << " | " << reszta << " / " << m_mianownik << endl;
    }
    //2.1
    void setZbiorczy(int licznik, int mianownik)
    {
        setMianownik(mianownik);
        setLicznik(licznik);
    }


    void setDziesietny(double dziesietny, int dokladnosc = 2)
    {
        double ulamekDziesietny = dziesietny;
        int mianownik = pow(10, dokladnosc);
        int licznik = round(ulamekDziesietny * mianownik);
        int nwd = dzielnik(licznik, mianownik);

        m_licznik = licznik / nwd;
        m_mianownik = mianownik / nwd;
    }

private: //do skrocenia
    int dzielnik(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return dzielnik(b, a % b);
    }


    Ulamek pomnoz(Ulamek& inny)
    {
        int pomLicznik = m_licznik * inny.getLicznik();
        int pomMianownik = m_mianownik * inny.getMianownik();

        return Ulamek(pomLicznik, pomMianownik);
    }


};

int main()
{
    Ulamek u1(22, 7);

    cout << "Liczby po kropce:" << endl;
    u1.setMianownik(7);
    cout << u1.naPrzecinek() << endl;

    double dziesietny = 0.12345;
    int dokladnosc = 3;
    Ulamek u2;

    u2.setDziesietny(dziesietny, dokladnosc);
    if (u2.getMianownik() != 0)
    {
        cout << "Ulamek: " << u2.getLicznik() << "/" << u2.getMianownik() << endl;
    }
    else
    {
        cout << "Nie udalo sie skonwertowac liczby dziesietnej na ulamek" << endl<<endl;
    }
  // Ulamek u3 = Ulamek(1, 2).pomnoz(Ulamek(3, 4)); // Ulamek u3 = u1 * u2
    
   // cout << u3.getLicznik() << "/" << u3.getMianownik() << endl; // wyświetli "3/8"
    //  Ulamek u3 = Ulamek u1 
    
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


