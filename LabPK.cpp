#include <iostream>

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

class Osoba
{

};

class ZamekCyfrowy
{
	double m_klucz;
public:
	ZamekCyfrowy(double klucz) { m_klucz = klucz; }
	bool Porownaj(double klucz);
	
};

bool ZamekCyfrowy::Porownaj(double klucz)
{
	if (m_klucz == klucz)
		return 1;
	else
		return 0;
}

class Sejf
{
	int m_dane[5] = {};
	ZamekCyfrowy m_zamek;
	Osoba* m_osoby[3] = {};
public:
	Sejf(double klucz)
		:m_zamek(klucz)
	{}
	void ZapiszDane(Osoba* o, double klucz, int* dane, const int rozmiar);
	int* OdczytajDane(Osoba* o, double klucz);
	void dodajOsobe(Osoba *o, int index);

};

void Sejf::ZapiszDane(Osoba* o, double klucz, int *dane, const int rozmiar)
{
	bool zgodnoscOsoba = 0;

	for (int i = 0; i < 3; i++)
	{
		if (m_osoby[i] == o)
			zgodnoscOsoba = 1;
	}
	bool zgodnoscKlucz = m_zamek.Porownaj(klucz);

	if (zgodnoscKlucz && zgodnoscOsoba)
		memcpy(m_dane, dane, sizeof(m_dane));
	else
		cout << "Bledny klucz lub nieupowazniona osoba!" << endl;
}

int* Sejf::OdczytajDane(Osoba* o, double klucz)
{
	bool zgodnoscOsoba = 0;

	for (int i = 0; i < 3; i++)
	{
		if (m_osoby[i] == o)
			zgodnoscOsoba = 1;
	}
	bool zgodnoscKlucz = m_zamek.Porownaj(klucz);

	if (zgodnoscKlucz && zgodnoscOsoba)
		return m_dane;
	else
		cout << "Bledny klucz lub nieupowazniona osoba!" << endl;
}

void Sejf::dodajOsobe(Osoba *o, int index)
{
	m_osoby[index]=o;
}


int main()
{
	int dane[5] = { 5,7,123,6456,123 };
	Osoba o1, o2, o3, o4, o5;

	Sejf s1(12.57);

	s1.dodajOsobe(&o1, 0);
	s1.dodajOsobe(&o2, 1);

	s1.ZapiszDane(&o1, 12.57, dane,5);

	cout << "Odczyt danych przez osobe upowazniana: " << endl;
	int dane2[5];
	int* wsk = s1.OdczytajDane(&o2, 12.57);
	for (int i = 0; i < 5; i++)
	{
		cout << wsk[i] << endl;
	}

	cout << "Odczyt danych przez osobe nieupowazniana: " << endl;
	int* wsk2 = s1.OdczytajDane(&o5, 12.57);
}
#endif

#ifdef ZadanieP

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA PODSTAWOWEGO

#endif

#ifdef ZadanieA

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA AMBITNEGO

#endif




