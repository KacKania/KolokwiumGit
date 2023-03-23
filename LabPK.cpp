#include <iostream>

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

void zwolnienie_pamieci(int*** tab2D, int wiersze)
{
	bool rodzaj;			//true ciagla	false fragmentaryczna

	if (**tab2D != nullptr)
	{
		for (int i = 0; i < wiersze; i++)
		{
			if (tab2D[i][0] < tab2D[i + 1][0])
			{
				rodzaj = true;
			}
			else
			{
				rodzaj = false;
				break;
			}
		}

		if (rodzaj)
		{
			delete[] tab2D[0];
			delete[] * *tab2D;
		}
		else
		{
			for (int i = 0; i < wiersze; i++)
			{
				delete[] tab2D[i];
			}
			delete[] * *tab2D;
		}
		tab2D = nullptr;
	}

	//sprawdzanie rozmiaru

	/*
	for (int rozmiar : tab2D)
	{
		int* tab = new int[rozmiar] {};
		unsigned char* wsk = (unsigned char*)tab;
	}
	*/
 }
#endif

#ifdef ZadanieP

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA PODSTAWOWEGO

#endif

#ifdef ZadanieA

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA AMBITNEGO

#endif




