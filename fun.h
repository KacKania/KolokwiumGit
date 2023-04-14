#pragma once

int funkcja(int* tablica, int liczba_elementow, int wartoscZapis, int indeks)
{
	static int pamiec = -1;
	static int licznik = 0;
	

	if (indeks < 0 || indeks >= liczba_elementow)
	{
		if (indeks == pamiec)
		{
			licznik = licznik + 1;
		}
		else
		{
			pamiec = indeks;
			licznik = 0;
		}
	}
	return licznik;
}

