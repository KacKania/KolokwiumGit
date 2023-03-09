#include "Funckje.h"

void Sortuj(int(*tab)[kolumny],const int wiersze)
{

	for (int i = 0; i < wiersze; i++)
	{
		if (wiersze % 2 == 0)
		{
			SortIter(tab[i], kolumny);
		}
		else
		{
			int* tabtemp = SortRek(tab[i], 0, kolumny);
			_memccpy(tab[i], tabtemp, 10, kolumny);
		}
	}
}

void Sortuj(int(*tab)[kolumny])
{
	int wiersze = 10;
	for (int i = 0; i < wiersze; i++)
	{
		if (wiersze % 2 == 0)
		{
			SortIter(tab[i], kolumny);
		}
		else
		{
			int *tabtemp=SortRek(tab[i], 0, kolumny);
			_memccpy(tab[i], tabtemp, 10, kolumny);
		}
	}

}
// zrodlo: https://eduinf.waw.pl/inf/alg/003_sort/0004.php
void SortIter(int tab[],  int rozmiar)
{
	for (int j = 0; j < rozmiar - 1; j++)
		for (int n = 0; n < rozmiar - 1; n++)
			if (tab[n] > tab[n + 1]) swap(tab[n], tab[n + 1]);
}
// zrodlo: https://cpp0x.pl/kursy/Algorytmy/Sortowanie-danych/Sortowanie-szybkie-ang-quick-sort/450
int *SortRek(int taborg[], int left, int right)
{
	int tab[kolumny];
	_memccpy(tab,taborg,10,kolumny);
    int i = left;
    int j = right-1;
    int x = tab[(left + right) / 2];
    do
    {
        while (tab[i] < x)
            i++;

        while (tab[j] > x)
            j--;

        if (i <= j)
        {
            swap(tab[i], tab[j]);

            i++;
            j--;
        }
    } while (i <= j);

    if (left < j) SortRek(tab, left, j);

    if (right > i) SortRek(tab, i, right);
	
	int* wsk = tab;
	return wsk;
}

void wypisz(int(*tab)[kolumny], const int wiersze)
{
	for (size_t i = 0; i < wiersze; i++)
	{
		for (size_t j = 0; j < kolumny; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}