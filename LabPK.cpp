
#include "Funckje.h"



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




