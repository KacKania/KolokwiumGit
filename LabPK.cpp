﻿#include <iostream>
using namespace std;

#define ZadanieD

enum class Studia { stacjonarne, niestacjonarne };
enum class Stopien { inzynierski, magisterski, doktorancki };
enum class StopienNaukowy { mgr, dr, dr_hab, prof };

class Katedra
{
protected:
	char m_nazwa[100] = "";
public:
	Katedra(const char* nazwa) { setNazwa(nazwa); }
	void setNazwa(const char* nazwa) { strncpy(m_nazwa, nazwa, 100); }
	const char* getNazwa() const { return m_nazwa; }
};

class Kierunek
{
protected:
	char m_nazwa[100] = "";
public:
	Kierunek(const char* nazwa) { setNazwa(nazwa); }
	void setNazwa(const char* nazwa) { strncpy(m_nazwa, nazwa, 100); }
	const char* getNazwa() const { return m_nazwa; }
};


class Osoba
{
protected:
	char m_imie[30] = "";
	char m_nazwisko[40] = "";
	int m_wiek = 18;
public:
	Osoba(const char* imie, const char* nazwisko, int wiek)
	{
		setImie(imie);
		setNazwisko(nazwisko);
		setWiek(wiek);
	}

	void setImie(const char* imie) { strncpy(m_imie, imie, 30); }
	void setNazwisko(const char* nazwisko) { strncpy(m_nazwisko, nazwisko, 40); }
	void setWiek(int wiek) { m_wiek = (wiek > 0) ? wiek : 0; }

	const char* getImie() const { return m_imie; }
	const char* getNazwisko() const { return m_nazwisko; }
	int getWiek() const { return m_wiek; }
};



class Student :public Osoba
{
protected:
	Kierunek* m_kierunek = nullptr;
	int m_semestr = 1;
	Studia m_rodzajStudiow = Studia::stacjonarne;
	Stopien m_stopien = Stopien::inzynierski;
public:
	Student(Osoba& kandydat, Kierunek* kierunek, int semestr, Studia rodzaj, Stopien stopien)
		: Osoba(kandydat), m_kierunek(kierunek), m_rodzajStudiow(rodzaj), m_stopien(stopien)
	{
		setSemestr(semestr);
	}
	void setKierunek(Kierunek* kierunek) { m_kierunek = kierunek; }
	void setSemestr(int semestr) { m_semestr = (semestr > 0 && semestr < 8) ? semestr : 1; }
	void setRodzajStudiow(Studia rodzaj) { m_rodzajStudiow = rodzaj; }
	void setStopien(Stopien stopien) { m_stopien = stopien; }

	Kierunek* getKierunek() const { return m_kierunek; }
	int getSemestr() const { return m_semestr; }
	Studia getRodzajStudiow() const { return m_rodzajStudiow; }
	Stopien getStopien() const { return m_stopien; }
};

class Pracownik : public Osoba
{
protected:
	int m_stazPracy = 0;
	Katedra* m_katedra = nullptr;
	StopienNaukowy m_stopien = StopienNaukowy::mgr;
public:
	Pracownik(Osoba& osoba, Katedra* katedra, StopienNaukowy stopien)
		:Osoba(osoba), m_katedra(katedra), m_stopien(stopien)
	{}

	void zwiekszStaz() { m_stazPracy++; }
	void setKatedra(Katedra* katedra) { m_katedra = katedra; }
	void setStopienNaukowy(StopienNaukowy stopien)
	{
		m_stopien = stopien;
	}

	int getStaz() const { return m_stazPracy; }
	Katedra* getKatedra() const { return m_katedra; }
	StopienNaukowy getStopienNaukowy() const { return m_stopien; }

	//##############
	virtual double getPensja() {
		double pensja = 100 * m_stazPracy;
		if (m_stopien == StopienNaukowy::mgr) {
			pensja += 2000;
		}
		if (m_stopien == StopienNaukowy::dr) {
			pensja += 3000;
		}
		if (m_stopien == StopienNaukowy::dr_hab) {
			pensja += 4000;
		}
		if (m_stopien == StopienNaukowy::prof) {
			pensja += 5000;
		}
		return pensja;
	}
	//##############
};

class PracownikNaukowy : public Pracownik
{
protected:
	int m_liczbaPublikacji = 0;
public:
	PracownikNaukowy(Pracownik& pracownik)
		:Pracownik(pracownik)
	{}
	void zwiekszLiczbePublikacji() { m_liczbaPublikacji++; }
	int getLiczbaPublikacji() const { return m_liczbaPublikacji; }

	//##############
	   double getPensja() {
	double pensja = Pracownik::getPensja();
	return pensja + 50* m_liczbaPublikacji;
}
	//##############

};

class PracownikDydaktyczny : public Pracownik
{
protected:
	int m_liczbaPrzedmiotow = 0;
public:
	PracownikDydaktyczny(Pracownik& pracownik, int lp)
		: Pracownik(pracownik)
	{
		setLiczbaPrzedmiotow(lp);
	}
	void setLiczbaPrzedmiotow(int lp) { m_liczbaPrzedmiotow = (lp > 0) ? lp : 0; }
	int getLiczbePrzedmiotow() const { return m_liczbaPrzedmiotow; }

	//##############
	double getPensja() {
		double pensja = Pracownik::getPensja();
		return pensja + 100 * m_liczbaPrzedmiotow;
	}
	//##############
};

//##############
class Doktorant : public Pracownik, public Student
{
public:
	Doktorant(Osoba&o, Kierunek*kierunek, int semestr, Studia rodzaj, Katedra*katedra)
		:Student(o, kierunek, semestr, rodzaj, Stopien::doktorancki),
		Pracownik(o, katedra, StopienNaukowy::mgr) {
	}

	double getPensja() {
		return 1500 + 200 * (m_semestr / 2 - 1);
	}
};
//##############

int main()
{
	Katedra k1("Informatyka");
	Katedra k2("Matematyka");

	Kierunek ki1("Informatyka");
	Kierunek ki2("Matematyka");

	Osoba o1("Jan", "Kowalski", 45);
	Pracownik p1(o1, &k1, StopienNaukowy::mgr);
	PracownikDydaktyczny pd1(p1, 4);

	Osoba o2("Janina", "Kowalska", 35);
	Pracownik p2(o2, &k1, StopienNaukowy::prof);
	PracownikNaukowy pn2(p2);

	Osoba o3("Janusz", "Iksinski", 29);
	Doktorant d1(o3, &ki1, 4, Studia::stacjonarne, &k1);

	Osoba o4("Michal", "Kos", 40);
	Pracownik p4(o4, &k1, StopienNaukowy::dr_hab);
	PracownikDydaktyczny pd4(p4, 2);

	Osoba o5("Jerzy", "Kiler", 51);
	Pracownik p5(o5, &k2, StopienNaukowy::dr);
	PracownikDydaktyczny pd5(p5, 2);

	Osoba o6("Monika", "Michałowska", 32);
	Pracownik p6(o6, &k2, StopienNaukowy::dr);
	PracownikNaukowy pn6(p6);

	Osoba o7("Antoni", "Jędrzejewski", 40);
	Pracownik p7(o7, &k1, StopienNaukowy::dr);
	PracownikNaukowy pn7(p7);

	Osoba o8("Adam", "Kowalewski", 20);
	Student s8(o8, &ki1, 1, Studia::stacjonarne, Stopien::inzynierski);

	Osoba o9("Wiktoria", "Bąk", 23);
	Student s9(o9, &ki1, 5, Studia::niestacjonarne, Stopien::inzynierski);

	Osoba o10("Robert", "Warszawski", 24);
	Student s10(o10, &ki2, 1, Studia::stacjonarne, Stopien::magisterski);

	Osoba o11("Wiesław", "Balon", 21);
	Student s11(o11, &ki2, 2, Studia::niestacjonarne, Stopien::inzynierski);







}
 

#ifdef ZadanieD



#endif

#ifdef ZadanieW



#endif

#ifdef ZadanieP



#endif

#ifdef ZadanieA



#endif




