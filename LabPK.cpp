#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

#define ZadanieD

#ifdef ZadanieD
int ileWierszy(FILE* plik)
{
	int ilosc = 0;
	char tekst[100] = {};

	while (fscanf(plik, "%[^\n] ", &tekst) != EOF)
	{
		ilosc++;
	}
	return ilosc;
}
ostream& operator<< (ostream& ekr, FILE* plik)
{
	char znak;
	if (plik != nullptr)
	{
		rewind(plik);
		while (!feof(plik))
		{
			znak = fgetc(plik);
			ekr << znak;
		}
	}
	return ekr;
}
int main()
{
	setlocale(LC_ALL, "");
	constexpr size_t ROZMIAR = 100;
	FILE* tdostawa = nullptr;
	FILE* todleglosc = nullptr;
	todleglosc = fopen("taryfa_odleglosc.txt", "r");
	tdostawa = fopen("taryfa_dostawa.txt", "r");
	int rodleglosc = ileWierszy(todleglosc);
	int rdostawa = ileWierszy(tdostawa);

	double* odleglosc_km = new double[rodleglosc];
	double* odleglosc_cena = new double[rodleglosc];
	double* dostawa_cena = new double[rdostawa];

	rewind(todleglosc);
	for (int i = 0; i < rodleglosc; i++)
	{
		fscanf(todleglosc, "%d", odleglosc_km);

	}
	
	
	rewind(tdostawa);
	for (int i = 0; i < rdostawa; i++)
	{
		fscanf(tdostawa, "%d", dostawa_cena);
	}

	fclose(todleglosc);
	todleglosc = nullptr;


	double odleglosc;
	int ster_dostawa;
	double taryfa_odleglosc = 0;
	double taryfa_dostawa = 0;
	double cena = 0;
	cout << "Podaj odleglosc " << endl;
	cin >> odleglosc;
	cout << " Wybierz sposob dostawy podajac [nr indeksu]: " << endl;
	cout << tdostawa << endl;
	cin >> ster_dostawa;

	fclose(tdostawa);
	tdostawa = nullptr;

	for (int i = 0; i < rodleglosc; i++)
	{
		if (odleglosc <= 0)
		{
			cout << "za mala odleglosc";
			break;
		}
		
		if (odleglosc <= odleglosc_km[i])
		{
			taryfa_odleglosc = odleglosc_cena[i];
			break;
		}
	}
	for (int i = 0; i <= ster_dostawa; i++)
	{
		if (ster_dostawa<0)
		{
			cout << "Zly indeks!"; break;
		}
		else
		{
			taryfa_dostawa = dostawa_cena[i]; 
		}
			
	}

	cena = taryfa_dostawa * taryfa_odleglosc;


	cout << "Cena: " << cena;





}

#endif

#ifdef ZadanieW



#endif

#ifdef ZadanieP



#endif

#ifdef ZadanieA



#endif



