#include <iostream>
#include <ctime>
#include <cstdlib>

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

#define RND_ZZ (double)rand() / RAND_MAX
#define RND_ZO (double)rand() / (RAND_MAX + 1)
#define RND_OZ (rand() + 1.0) / (RAND_MAX + 1)
#define RND_OO (rand() + 1.0) / (RAND_MAX + 2)

class Generator
{
	double m_a;
	double m_b;
	bool m_czyLewaGranicaOtwarta;
	bool m_czyPrawaGranicaOtwarta;
	double m_losowania[4];
	int m_index = 0;
	int m_ziarno;
	double losuj();
	bool sprawdzPowtorzenie(double x);
public:

	void setAll(double a, double b, bool lewaGranica, bool prawaGranica, int ziarno)
	{
		setA(a);
		setB(b);
		setLewaGranica(lewaGranica);
		setPrawaGranica(prawaGranica);
		setZiarno(ziarno);
	}
	void setA(double a) { m_a = a; }
	void setB(double b) { m_b = b; }
	void setLewaGranica(bool granica) { m_czyLewaGranicaOtwarta = granica; }
	void setPrawaGranica(bool granica) { m_czyPrawaGranicaOtwarta = granica; }
	void setZiarno(int ziarno){ m_ziarno = ziarno; }

	double generujLosowa();
};

double Generator::losuj()
{
	double wylosowana;

	if (!m_czyLewaGranicaOtwarta && !m_czyPrawaGranicaOtwarta)
	{
		wylosowana = m_a + RND_ZZ * (m_b - m_a);
	}
	else if (!m_czyLewaGranicaOtwarta && m_czyPrawaGranicaOtwarta)
	{
		wylosowana = m_a + RND_ZO * (m_b - m_a);
	}
	else if (m_czyLewaGranicaOtwarta && !m_czyPrawaGranicaOtwarta)
	{
		wylosowana = m_a + RND_OZ * (m_b - m_a);
	}
	else if (m_czyLewaGranicaOtwarta && m_czyPrawaGranicaOtwarta)
	{
		wylosowana = m_a + RND_OO * (m_b - m_a);
	}

	return wylosowana;
}

bool Generator::sprawdzPowtorzenie(double x)
{
	bool sprawdz;
	for (int i = 0; i < 4; i++)
	{
		if (x != m_losowania[i])
			sprawdz = true;
		else
			sprawdz = false;
	}

	return sprawdz;
}

double Generator::generujLosowa()
{
	double los = losuj();

	if (sprawdzPowtorzenie(los))
	{
		m_losowania[m_index] = los;
		m_index++;
		if (m_index > 3)
			m_index = 0;
		return los;
	}
	else
		generujLosowa();

}

int main()
{
	srand(time(0));

	Generator g;
	g.setAll(2.5, 2.6, 1, 1, time(0));

	cout << g.generujLosowa() << endl;
	cout << g.generujLosowa() << endl;
	cout << g.generujLosowa() << endl;
	cout << g.generujLosowa() << endl;
	cout << g.generujLosowa() << endl;
	cout << g.generujLosowa() << endl;
}

#endif

#ifdef ZadanieP

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA PODSTAWOWEGO

#endif

#ifdef ZadanieA

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA AMBITNEGO

#endif




