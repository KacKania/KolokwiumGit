
#include "Funckje.h"

/* Zmieniając ostatnią literę w poniższej instrukcji na D (dodatkowe), lub P (podstawowe)
*  wybierasz aktywne zadanie.
*
*  UWAGA: jeśli rozwiązanie zadań wymaga podziału programu na pliki to dodaj je wszystkie do
*  projektu, ale przy każdym zadaniu "includuj" tylko te, które jego dotyczą.
*
*/
#define ZadanieP 

#ifdef ZadanieD

// TU UMIEŚĆ KOD ROZWIAZANIA WYBRANEGO ZADANIA DOMOWEGO 
enum class Klasa { powszechny, rzadki, unikalny, epicki };
const char* const KLASA[] = { "powszechny", "rzadki", "unikalny", "epicki" };
enum class Typ { bron, zbroja, amulet, pierscien, helm, tarcza, buty };
const char* const TYP[] = { "bron", "zbroja", "amulet", "pierscien", "helm", "tarcza", "buty" };
using text = char[50];
using zloto = int;
using ciezar = double;

struct Przedmiot
{
	ciezar waga;
	zloto wartosc;
	Klasa rzadkosc;
	Typ typ;
	text nazwa;
	double obrazenia;
	int wytrzymalosc;
	string(*zaklecie)(int);
};

void stworzPrzedmiot(Przedmiot& p, ciezar w, zloto wart, Klasa rzadk, Typ t, const char* n, double obr, int wytrz, string (*funkcja) (int))
{
	p.waga = w;
	p.wartosc = wart;
	p.rzadkosc = rzadk;
	p.typ = t;
	strcpy_s(p.nazwa, n);
	p.obrazenia = obr;
	p.wytrzymalosc = wytrz;
	p.zaklecie = funkcja;
}

ostream& operator<<(ostream& str, Przedmiot const& p)
{
	str << p.nazwa << " (Klasa: " << KLASA[(int)p.rzadkosc] << "| Typ:" << TYP[(int)p.typ] << ")" << "\n" << "waga: " << p.waga << "\nwartosc: " << p.wartosc << " szt zlota"
		<< "\n" << "obrazenia: " << p.obrazenia << "\nwytrzymalosc: " << p.wytrzymalosc << "\nBonus: " << p.zaklecie << endl;
	return str;
}

string OgnisteZaklecie(int mana)
{
	if (mana < 1)
		return "Za mało punktów many!";
	else if (mana > 3)
		return "To zaklęcie nie wymaga tylu punktów many!";
	
	switch ( mana)
	{
	default:
		return "Brak efektu";
		break;
	case 1:
		return "+5% obrazen magicznych";
			break;
	case 2:
		return "+10% obrazen magicznych";
		break;
	case 3:
		return "+15% obrazen magicznych oraz podpalenie";
		break;
	}

}

string  ZaklecieDuszy(int mana)
{
	if(mana < 1)
		return "Za mało punktów many!";
	else if (mana > 3)
	return "To zaklęcie nie wymaga tylu punktów many!";

	switch (mana)
	{
	default:
		return "Brak efektu";
		break;
	case 1:
		return "Silny przeciwko potworm +15";
		break;
	case 2:
		return "Silny przeciwko zwierzetom +25";
		break;
	case 3:
		return "Silny przeciowko ludziom +10";
		break;
	}
}

void LiczIndentyczneEfekty(Przedmiot const* przedmioty, int rozmiar)
{
	int ogniste = 0; int duszy = 0;

	for (int i = 0; i < rozmiar; i++)
	{
		if (przedmioty[i].zaklecie == *OgnisteZaklecie)
			ogniste++;
		else if (przedmioty[i].zaklecie == *ZaklecieDuszy)
			duszy++;
	}

	cout << "Przedmioty z Ognistym Zakleciem: " << ogniste << "\nPrzedmioty z Zakleciem Duszy: " << duszy <<endl;
}

void WypiszEfekty(Przedmiot const * przedmioty, int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		cout << przedmioty[i].nazwa << endl;

		for (int j = 1; j <= 3; j++)
		{
			cout << przedmioty[i].zaklecie(j) << endl;
		}
	}
}


int main()
{
	Przedmiot miecz, zbroja, amulet, pierscien, helm, tarcza, buty, ostrze, kamien, topor;
	stworzPrzedmiot(miecz, 4, 150, Klasa::powszechny, Typ::bron, "Miecz straznika", 6.5, 50, OgnisteZaklecie);
	stworzPrzedmiot(zbroja, 10, 200, Klasa::rzadki, Typ::zbroja, "Zbroja najemnika", 10.4, 100, *ZaklecieDuszy);
	stworzPrzedmiot(amulet, 0.5, 421, Klasa::unikalny, Typ::amulet, "Amulet nekromanty", 14, 22, *ZaklecieDuszy);
	stworzPrzedmiot(pierscien, 0.3, 532, Klasa::unikalny, Typ::pierscien, "Pierscien nieskonczonosci", 23, 15, *OgnisteZaklecie);
	stworzPrzedmiot(helm, 3.4, 185, Klasa::rzadki, Typ::helm, "Helm honoru", 6.3, 65, *OgnisteZaklecie);
	stworzPrzedmiot(tarcza, 12, 115, Klasa::powszechny, Typ::tarcza, "Tarcza obroncy", 11.5, 110, *ZaklecieDuszy);
	stworzPrzedmiot(buty, 7.5, 55, Klasa::powszechny, Typ::buty, "Buty odwagi", 2.5, 72, *OgnisteZaklecie);
	stworzPrzedmiot(ostrze, 11, 1125, Klasa::powszechny, Typ::bron, "Ostrze wiatru", 14.7, 95, *OgnisteZaklecie);
	stworzPrzedmiot(kamien, 3.4, 546, Klasa::unikalny, Typ::amulet, "Kamien nieskonczonosci", 47.6, 27, *ZaklecieDuszy);
	stworzPrzedmiot(topor, 22, 345, Klasa::rzadki, Typ::bron, "Topor orka", 112, 76, *OgnisteZaklecie);


	Przedmiot przedmioty[] = { miecz, zbroja, amulet, pierscien, helm, tarcza, buty, ostrze, kamien, topor };

	LiczIndentyczneEfekty(przedmioty, 10);

	WypiszEfekty(przedmioty, 10);

	cout << miecz.zaklecie(1);
}



#endif

#ifdef ZadanieP

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA PODSTAWOWEGO
int main()
{
	int tab[10][kolumny] = { {4,3,6,1,2,5,6,7,9,5},
							{3,6,3,8,9,1,4,5,6,9},
							{2,6,6,4,8,2,6,3,3,7},
							{6,3,7,2,8,1,4,5,3,6},
							{8,2,1,4,6,3,7,2,5,7},
							{4,3,6,1,2,5,6,7,9,5},
							{3,6,3,8,9,1,4,5,6,9},
							{2,6,6,4,8,2,6,3,3,7},
							{6,3,7,2,8,1,4,5,3,6},
							{8,2,1,4,6,3,7,2,5,7},
												};

	int tab2[6][kolumny] = {{4,3,6,1,2,5,6,7,9,5},
							{3,6,3,8,9,1,4,5,6,9},
							{2,6,6,4,8,2,6,3,3,7},
							{6,3,7,2,8,1,4,5,3,6},
							{8,2,1,4,6,3,7,2,5,7},
							{5,3,4,1,6,7,8,9,0,1},
												};

	cout << "Nieposortowana: " << endl;
	wypisz(tab,10);
	Sortuj(tab);
	cout << "Posortowana: "<< endl;
	wypisz(tab, 10);

	cout << "Nieposortowana: " << endl;
	wypisz(tab2,6);
	Sortuj(tab2,6);
	cout << "Posortowana: " << endl;
	wypisz(tab2,6);

}
#endif

#ifdef ZadanieA

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA AMBITNEGO
enum class Stany
{
	Stan1 = 0,
	Stan2 = 1,
	Stan3 = 2,
	Stan4 = 3
};

struct DaneKom
{
	bool dzialaj;
	Stany aktStan;
};


#endif




