#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctype.h>
#include <cmath>

using namespace std;
/* Zmieniając ostatnią literę w poniższej instrukcji na D (dodatkowe), lub P (podstawowe)
*  wybierasz aktywne zadanie.
*
*  UWAGA: jeśli rozwiązanie zadań wymaga podziału programu na pliki to dodaj je wszystkie do
*  projektu, ale przy każdym zadaniu "includuj" tylko te, które jego dotyczą.
*
*/
#define ZadanieD 

#ifdef ZadanieD

// TU UMIEŚĆ KOD ROZWIAZANIA WYBRANEGO ZADANIA DOMOWEGO 

class Point
{
	int m_x, m_y;
	char m_symbol;
	static int s_szerokosc;
	static int s_wysokosc;
	static int licznik;
	int m_nrInstancji = licznik;
	static Point instancje[];
	static void sprawdz(Point p);
public:
	Point();
	Point(int x, int y, char symbol);
	~Point();
	void setX(int x);
	void setY(int y);
	void setSymbol(char sym)
	{
		if (isalpha(sym))
			m_symbol = sym;
		else m_symbol = 0;
	}
	static void setRozmiarEkranu(int x, int y);
	int getX() { return m_x; }
	int getY() { return m_y; }
	char getSymbol() { return m_symbol; }
};

Point Point::instancje[1000];
int Point::s_szerokosc = 1920;
int Point::s_wysokosc = 1080;
int Point::licznik = 0;

Point::Point()
{
	setX(s_szerokosc / 2);
	setY(s_wysokosc / 2);
	setSymbol(NULL);
	instancje[licznik] = *this;
	licznik++;
}

Point::Point(int x, int y, char symbol)
{
	setX(x);
	setY(y);
	setSymbol(symbol);
	instancje[licznik] = *this;
	licznik++;
}

Point::~Point()
{
	for (int i = m_nrInstancji; i < licznik; i++)
	{
		instancje[i] = instancje[i + 1];
	}
	licznik--;
}

void Point::setX(int x)
{
	if (x < 0)
	{
		m_x = 0;
	}
	else if (x > s_szerokosc)
	{
		m_x = s_szerokosc;
	}
	else
	{
		m_x = x;
	}
}

void Point::setY(int y)
{
	if (y < 0)
	{
		m_y = 0;
	}
	else if (y > s_wysokosc)
	{
		m_y = s_wysokosc;
	}
	else
	{
		m_y = y;
	}
}

void Point::setRozmiarEkranu(int x, int y)
{
	if (x < 0)
	{
		s_szerokosc = 0;
	}
	if (y < 0)
	{
		s_wysokosc = 0;
	}

	if (x % 2 == 0 && y % 2 == 0)
	{
		s_szerokosc = x;
		s_wysokosc = y;
	}
	else if (x % 2 != 0)
	{
		s_szerokosc = x - 1;
	}
	else if (y% 2 != 0)
	{
		s_wysokosc = y - 1;
	}

	for (int i = 0; i < licznik; i++)
	{
		sprawdz(instancje[i]);
	}
}

void Point::sprawdz(Point p)
{
	if (p.getX() > s_szerokosc)
		p.setX(s_szerokosc);
	else if (p.getY() > s_wysokosc)
		p.setY(s_wysokosc);
}

ostream& operator<<(ostream& str, Point p)
{
	str << p.getSymbol() << "X :" << p.getX() << " Y: " << p.getY() <<endl;
	return str;
}

int main()
{
	
	Point p1(354, 123, 'a');
	Point p2(123, 345, 'b');
	Point p3(675, 245, 'c');
	Point p4(451, 178, 'd');
	Point p5(1567, 1003, 'e');


	cout << "Przed zmiana rozmiar 1920 x 1080" << endl;
	cout << p1 << p2 << p3 << p4 << p5;

	Point::setRozmiarEkranu(1200, 800);

	cout << "po zmianie rozmiaru na 1200 x 800" << endl;
	cout << p1 << p2 << p3 << p4 << p5;


}

#endif

#ifdef ZadanieP

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA PODSTAWOWEGO

#endif

#ifdef ZadanieA

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA AMBITNEGO

#endif




