#include <iostream>
#include "fun.h"
using namespace std;



int main()
{
	const int rozmiar = 22;
	int tablica[rozmiar] = {};

	cout<<funkcja(tablica, rozmiar, 3, 3)<<endl;
	cout << funkcja(tablica, rozmiar, 3, 3)<<endl;
	cout << funkcja(tablica, rozmiar, 2, 4) << endl;
	cout << funkcja(tablica, rozmiar, 1, 5) << endl;
	cout << funkcja(tablica, rozmiar, 1, 5) << endl;

	
	return 0;
}