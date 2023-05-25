#include <iostream>
using namespace std;
/* Zmieniając ostatnią literę w poniższej instrukcji na D (dodatkowe), lub P (podstawowe)
*  wybierasz aktywne zadanie.
*
*  UWAGA: jeśli rozwiązanie zadań wymaga podziału programu na pliki to dodaj je wszystkie do
*  projektu, ale przy każdym zadaniu "includuj" tylko te, które jego dotyczą.
*
*/
#define ZadanieA 

#ifdef ZadanieD

// TU UMIEŚĆ KOD ROZWIAZANIA WYBRANEGO ZADANIA DOMOWEGO 

#endif

#ifdef ZadanieP

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA PODSTAWOWEGO
enum class TypTowaru { ciekly, sypki, paczkowany };
enum class KatPJ { A, B, C, D };

class Pojazd
{
protected:
	char m_numerRej[9];
	double m_predkosc;

	void setPredkosc(double i_pred) { m_predkosc = (i_pred > 160) ? i_pred : 160; }
public:

	void setNumerRej(const char* i_num) { strncpy_s(m_numerRej, i_num, 8); }
	double getPredkosc() { return m_predkosc; }
	const char* getNumerRej() { return m_numerRej; }

	Pojazd(const char* nrRej, double predkosc)
	{
		setNumerRej(nrRej);
		setPredkosc(predkosc);
	}

	virtual double OplataRejestracyjna() = 0;
};

class SamochodOsobowy : public Pojazd
{
protected:
	int m_liczbaPasazerow;

	void setLiczbaPasazerow(int i_lp) { m_liczbaPasazerow = (i_lp > 1) ? i_lp : 1; }
public:

	int getLiczbaPasazerow() { return m_liczbaPasazerow; }

	SamochodOsobowy( double i_pred, int i_lp, const char* i_num)
		:Pojazd(i_num, i_pred)
	{
		setLiczbaPasazerow(i_lp);
	}

	double OplataRejestracyjna() override
	{
		double koszt;
		double nadmiarowa = Pojazd::getPredkosc() - 140;
		if (nadmiarowa < 0)
			nadmiarowa = 0;
		koszt = 500 + (50 * m_liczbaPasazerow) + (5 * nadmiarowa);

		return koszt;
	}
};

class SamochodCiezarowy : public Pojazd
{
protected:
	double m_pojemnosc;
	TypTowaru m_typ;
	
	void setPojemnosc(double i_poj) { m_pojemnosc = (i_poj > 1000) ? i_poj : 1000; }
public:
	void setTyp(TypTowaru i_typ) { m_typ = i_typ; }
	
	TypTowaru getTyp() { return m_typ; }
	double getPojemnosc() { return m_pojemnosc; }

	SamochodCiezarowy(double i_pred, double i_poj, TypTowaru i_typ, const char* i_num)
		:Pojazd(i_num,i_pred)
	{
		setPojemnosc(i_poj);
		setTyp(i_typ);
	}

	double OplataRejestracyjna() override
	{
		double koszt;
		double taryfa;
		switch (m_typ)
		{
		case TypTowaru::sypki:
			taryfa = 200;
			break;
		case TypTowaru::ciekly:
			taryfa = 400;
			break;
		case TypTowaru::paczkowany:
			taryfa = 100;
			break;
		}

		koszt = 1000 + m_pojemnosc + taryfa;

		return koszt;
	}
};

int main()
{
	Pojazd *tab[4] = { new SamochodOsobowy(200, 3,"SR2985678"), new SamochodOsobowy(210, 4, "SK5846760"),
		new SamochodCiezarowy(180, 1300, TypTowaru::paczkowany,"KR8194960"), new SamochodCiezarowy(175, 1500, TypTowaru::sypki, "GDA974569") };

	for (int i = 0; i < 4; i++)
	{
		cout << "Oplata rejestracyjna dla " << tab[i]->getNumerRej() << ": " << tab[i]->OplataRejestracyjna() << endl;
	}
}

#endif

#ifdef ZadanieA

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA AMBITNEGO

class Fighter
{
protected:
	int m_health;
	int m_attackStrength;
	int setValue(int val) { return (val >= 0) ? val : 0; }
	Fighter(int hlth, int attStr)
	{
		m_health = setValue(hlth);
		m_attackStrength = setValue(attStr);
	}
public:
	int getHealth() const { return m_health; }
	int getAttackStrength() const { return m_attackStrength; }
	
};

class Archer : virtual public Fighter
{
protected:
	int m_range;
	int setValue(int val) { return (val >= 0) ? val : 0; }
public:
	Archer(int hlth, int attStr, int rng)
		:Fighter(hlth, attStr)
	{
		m_range = setValue(rng);
	}
	
	int getRange() const { return m_range; }
	//Setery nie są konieczne
};

class Footman : virtual public Fighter
{
protected:
	int m_armor;
	int setValue(int val) { return (val >= 0) ? val : 0; }
public:
	Footman(int hlth, int attStr, int arm)
		:Fighter(hlth, attStr)
	{
		m_armor = setValue(arm);
	}
	int getRange() const { return m_armor; }
	//Setery nie są konieczne
};

class Ranger : public Archer, public Footman
{
public:
	Ranger(int hlth, int attStr, int rng, int arm)
		:Fighter(hlth,attStr),
		Archer(hlth, attStr, rng),
		Footman(hlth, attStr, arm)
	{}
};

int* ObliczKompania(Fighter* kompania, int rozmiar)
{
	int tab[3]; // [0] Archer [1] Footman [2] Ranger

	for (int i = 0; i < rozmiar; i++)
	{
		//Fighter *wsk = &kompania[i];
		Archer* wskAr = dynamic_cast<Archer*>(kompania[i]);

		if (wskAr == nullptr)
		{
			Footman* wskFt = dynamic_cast<Footman*>(kompania[i]);
			if (wskFt == nullptr)
			{
				tab[2]++;
			}
			else
				tab[1]++;

		}
		else
			tab[0]++;
	}

}


int main()
{
	Archer a1(150, 50, 300), a2(200, 75, 450); 
	Footman f1(400, 50, 100), f2(350, 45, 80);
	Ranger r1(250, 35, 175, 75);

	 Fighter* kompania[5] = {&a1, &a2, &f1, &f2, &r1};

	int *wsk = ObliczKompania(*kompania, 5);

	cout << "Archer: " << wsk[0] << endl;
	cout << "Footman: " << wsk[1] << endl;
	cout << "Ranger: " << wsk[2] << endl;

}

#endif




