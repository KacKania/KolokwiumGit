#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct tab
{
	unsigned int n;
	double* t;

	void wyswietl() {
		for (int i = 0; i < n; i++) {
			cout << t[i] << " ";
		}
	}
};

tab alokuj(unsigned int n)
{
	tab t1;
	t1.n = n;
	t1.t = new double[n];
	return t1;
}

void dealokuj(tab t1)
{
	t1.n = 0;
	delete[] t1.t;
}

int main()
{
	tab t1 = alokuj(3);
	t1.t[0] = 11;
	t1.t[1] = 12;
	t1.t[2] = 33;
	t1.wyswietl();
	cout << endl;

	ifstream infile("dane.txt");

	string line;
	int n = 0;

	while (getline(infile, line)) {
		stringstream ss(line);
		string ns;
		while (getline(ss,ns,',')) {
			n++;
		}
	}

	infile.close();

	ifstream infile1("dane.txt");

	tab t2 = alokuj(n);
	int indeks = 0;

	while (getline(infile1, line)) {
		stringstream ss(line);
		string ns;
		while (getline(ss, ns, ',')) {
			double d = atof(ns.c_str());
			t2.t[indeks] = d;
			indeks++;
		}
	}

	infile1.close();

	cout << "z pliku: ";
	t2.wyswietl();








	return 0;
}