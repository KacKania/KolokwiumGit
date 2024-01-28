#include <iostream>

using namespace std;

class Wektor;

class Punkt
{
	double m_x = 0.0, m_y = 0.0;
public:
	void setXY(double x, double y)
	{
		m_x = x;
		m_y = y;
	}
	double getX() const { return m_x; }
	double getY() const { return m_y; }
	Punkt(double x, double y)
		:m_x(x), m_y(y)
	{}

	Punkt operator+(const Wektor& w);
};

class Kolo
{
	double m_promien = 1.0;
	Punkt m_srodek;
public:
	void setPromien(double r)
	{
		m_promien = (r > 0) ? r : 0;
	}
	void setSrodek(Punkt p)
	{
		m_srodek = p;
	}
	double getPromien() const { return m_promien; }
	Punkt getSrodek() const { return m_srodek; }
	Kolo(Punkt sr, double r)
		: m_srodek(sr), m_promien(r)
	{}
};

class Kwadrat
{
	Punkt m_lewy_dolny, m_prawy_gorny;
public:
	void setRogi(Punkt ld, Punkt pg)
	{
		m_lewy_dolny = ld;
		m_prawy_gorny = pg;
	}
	Punkt getLewyDolny() const { return m_lewy_dolny; }
	Punkt getPrawyGorny() const { return m_prawy_gorny; }
	Kwadrat(Punkt ld, Punkt pg)
		:m_lewy_dolny(ld), m_prawy_gorny(pg)
	{}

	explicit operator Wektor();
};

class Wektor
{
	double m_dx = 0.0, m_dy = 0.0;
public:
	void setDXY(double dx, double dy)
	{
		m_dx = dx;
		m_dy = dy;
	}
	double getDX() const { return m_dx; }
	double getDY() const { return m_dy; }
	double dlugosc() const { return sqrt(m_dx * m_dx + m_dy * m_dy); }
	Wektor(double dx, double dy)
		:m_dx(dx), m_dy(dy)
	{}

	static Wektor from2Points(Punkt& p1, Punkt& p2);
};

class Zasob {
private:
	int* zasob;
public:
	Zasob(int w) {
		zasob = new int(w);
		cerr << "Dziala konstruktor argumentowy tworzy adres =  " << zasob << " zasob = " << *zasob << endl;
	}

	Zasob() : Zasob(0) {
		cerr << "Dziala konstruktor domyslny tworzy adres =  " << zasob << " zasob = " << *zasob << endl;
	}

	Zasob(Zasob& inny) {
		zasob = new int(*(inny.zasob));
		cerr << "Dziala konstruktor kopiujacy kopiuje adres " << inny.zasob << " => " << zasob << endl;
	}

	Zasob(Zasob&& inny) noexcept {
		zasob = new int(*(inny.zasob));
		cerr << "Dziala konstruktor przenoszacy przenosi adres " << inny.zasob << " => " << zasob << endl;
		inny.zasob = nullptr;
	}

	void wyswietl() {
		cout << "adres =  " << zasob << " zasob = " << *zasob << endl;
	}

	void ustaw(int x) {
		*zasob = x;
	}

	Zasob& operator=(const Zasob& inny) {
		if (this != &inny) {
			delete zasob;
			zasob = new int(*(inny.zasob));
			cerr << "Dziala operator = kopiujacy kopiuje adres " << inny.zasob << " => " << zasob << endl;
		}

		return *this;
	}

	Zasob& operator=(Zasob&& inny) {
		if (this != &inny) {
			delete zasob;
			zasob = inny.zasob;
			cerr << "Dziala operator = przenoszacy kopiuje adres " << inny.zasob << " => " << zasob << endl;
			inny.zasob = nullptr;

		}

		return *this;
	}

};

template<typename T>
class Sortowanie
{
public:
	static int compare(const void* a, const void* b) {
		return *(reinterpret_cast<const T*>(a)) - *(reinterpret_cast<const T*>(b));
	}

	template<size_t N>
	void operator()(T(&tab)[N]) const {
		qsort(tab, N, sizeof(T), compare);
	}

};



int main()
{
	Zasob z1(1);
	z1.wyswietl();
	Zasob z2;
	z2.wyswietl();
	Zasob z3(z1);
	z3.wyswietl();
	Zasob z4(z1);
	z4.wyswietl();

	Zasob z5(3);
	Zasob z6;
	z6 = z5;
	z6.wyswietl();
	Zasob z7;
	z7 = move(z6);
	z7.wyswietl();

	Zasob z11(11);
	Zasob z22(22);
	Zasob z33(33);

	cout << "Tablica zasobow" << endl;

	Zasob tabZasoby[] = { z11, z22, z33 };

	for (int i = 0; i < 3; i++) {
		tabZasoby[i].wyswietl();
	}

	cout << "Kopia tablicy zasobow 1" << endl;

	Zasob tabZasobyKopia1[3];

	for (int i = 0; i < 3; i++) {
		tabZasobyKopia1[i] = tabZasoby[i];
	}

	for (int i = 0; i < 3; i++) {
		tabZasobyKopia1[i].wyswietl();
	}


	cout << "Kopia tablicy zasobow 2" << endl;

	Zasob tabZasobyKopia2[3];

	memcpy(tabZasobyKopia2,tabZasoby, sizeof(tabZasoby));

	for (int i = 0; i < 3; i++) {
		tabZasobyKopia2[i].wyswietl();
	}

	cout << "Wartosci 3 tablic po zmianie" << endl;

	tabZasobyKopia2[1].ustaw(99);

	cout << "Zasoby" << endl;
	for (int i = 0; i < 3; i++) {
		tabZasoby[i].wyswietl();
	}
	cout << "Kopia 1" << endl;
	for (int i = 0; i < 3; i++) {
		tabZasobyKopia1[i].wyswietl();
	}
	cout << "Kopia 2" << endl;
	for (int i = 0; i < 3; i++) {
		tabZasobyKopia2[i].wyswietl();
	}


	cout << "Zadanie 2" << endl;

	int tab1[] = { 2,5,33,667,12,7 };

	Sortowanie<int>()(tab1);

	for (int el : tab1) {
		cout << el << " ";
	}
	cout << endl;

	
	/*string tab2[] = { "xyz","abc","zzz","hgf", "123" };

	Sortowanie<string>()(tab2);

	for (string el : tab2) {
		cout << el << " ";
	}
	cout << endl;*/

	return 0;
}
