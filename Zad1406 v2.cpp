// Zad1406.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Unit
{
protected:
    int m_health;
    int m_speed;
    int setValue(int val) { return (val >= 0) ? val : 0; }
public:
    Unit(){ }
    Unit(int hlth, int spd)
    {
        m_health = setValue(hlth);
        m_speed = setValue(spd);
    }
    int getHealth() const { return m_health; }
    void decreaseHealth(int d) {
        m_health = setValue(m_health - d);
    }
    int getSpeed() const { return m_speed; }
    virtual void attackUnit(Unit* u) = 0;
};

class Marine : public Unit
{
protected:
    int m_attack;
    int m_morale;
public:
    Marine() : Unit(200, 5), m_attack(20), m_morale(100) {}
    int getAttack() const { return m_attack; }
    int getMorale() const { return m_morale; }
    void attackUnit(Unit* u) override {
        int a = m_attack * (int)round(m_morale / 100.0);
        cout << "atak o sile: " << a << endl;
        u->decreaseHealth(a);
    }
};

class Tank : public Unit
{
protected:
    int m_attack;
    int m_cover;
    Marine m_marine;
public:
    Tank() : Unit(200, 5), m_attack(80), m_cover(15) { }
    Tank(int a, int c, Marine m) : Unit(200, 5), m_attack(a), m_cover(c), m_marine(m) { }
    int getAttack() const { return m_attack; }
    int getCover() const { return m_cover; }
    void attackUnit(Unit* u) override {
        int a = m_marine.getAttack() * (int)round(m_marine.getMorale() / 100.0) + m_attack;
        cout << "atak o sile: " << a << endl;
        u->decreaseHealth(m_attack);
        
    }
};


enum class Material
{
    Drewno,
    Plastik,
    Szmaciana
};

class Zabawka
{
private:
    char* nazwa;
    double cena;
    int min_wiek;
    Material material;

public:
    static int zniszczone;

    char* getNazwa() {
        return nazwa;
    }

    void setNazwa(char* n) {
        nazwa = n;
    }

    double getCena() {
        return cena;
    }

    void setCena(double c) {
        if (c >= 0) {
            cena = c;
        }
    }

    int getMinWiek() {
        return min_wiek;
    }

    void setMinWiek(int m) {
        if (m >= 0) {
            min_wiek = m;
        }
    }

    Material getMaterial() {
        return material;
    }

    void setMaterial(Material m) {
        material = m;
    }

    string getMaterialStr() {
        string m = "";

        switch (material)
        {
        case Material::Drewno:
            m = "drewno";
            break;
        case Material::Plastik:
            m = "plastik";
            break;
        case Material::Szmaciana:
            m = "szmaciana";
            break;
        default:
            break;
        }

        return m;
    }

    Zabawka() {
        char n[] = "Samochod";
        nazwa = n;
        cena = 29.99;
        min_wiek = 3;
        material = Material::Plastik;
    }

    Zabawka(char* n, double c, int mw, Material m) {
        nazwa = n;
        cena = c;
        min_wiek = mw;
        material = m;
    }

    void wyswietl() {
        

        cout << nazwa << " " << cena << "zl " << " wiek min: " << min_wiek << " wykonano z: " << getMaterialStr() << endl;
    }

    ~Zabawka() {
        zniszczone++;
    }

};

int Zabawka::zniszczone = 0;

class GrupaBojowa
{
private:
    vector<Unit*> units;
public:
    GrupaBojowa(vector<Unit*> us)
    {
        units = us;
    }

    void attackUnit(Unit* e)
    {
        for (int i = 0; i < 10; i++) {
            units[i]->attackUnit(e);
        }
    }
};

char* alokuj(int r) 
{
    int rozmiar = r + 2;

    char* tablica = new char[rozmiar];

    tablica[0] = (rozmiar >> 8) & 0xFF;
    tablica[1] = rozmiar & 0xFF;

    return tablica;
}

void zwolnij(char* tablica) {
    delete[] tablica;
    tablica = nullptr;
}

void wyswietl(char* linia, int n)
{
    for (int i = 2; i < n; i++) {
        cout << linia[i];
    }
    cout << endl;
}

void odczytajPlik(string plik, int znakow)
{
    ifstream odczyt(plik);

    if (odczyt.is_open()) 
    {
        char z;

        char* linia = alokuj(znakow);
        int i = 2;

        while (odczyt.get(z))
        {    
            if (z != '\n') {
                linia[i] = z;
                i++;
            }

            if (i == znakow + 2) {
                wyswietl(linia,i);
                i = 2;
            }
        }
        wyswietl(linia,i);
        
    }
}

int main()
{
    Zabawka z1;
    z1.wyswietl();

    char n[] = "Mis";
    Zabawka z2(n, 19.99, 3, Material::Szmaciana);

    z2.setCena(-2);
    z2.setMinWiek(-2);

    z2.wyswietl();

    char n1[] = "Mis duzy";
    z2.setNazwa(n1);
    z2.setCena(38.99);
    z2.setMinWiek(4);
    z2.setMaterial(Material::Plastik);

    cout << "gettery:" << endl;

    cout << z2.getNazwa() << endl;
    cout << z2.getCena() << endl;
    cout << z2.getMinWiek() << endl;
    cout << z2.getMaterialStr() << endl;

    cout << "zniszczone: " << Zabawka::zniszczone << endl;

    z1.~Zabawka();
    cout << "zniszczone: " << Zabawka::zniszczone << endl;

    z2.~Zabawka();
    cout << "zniszczone: " << Zabawka::zniszczone << endl;

    cout << "Unit" << endl;

    Marine m1;
    Marine m2;
    Marine m3;
    Marine m4;
    Marine m5;
    Marine m6;
    Marine m7;
    Marine m8;
    Marine m9;
    Tank t1(30,20,m1);
    Tank t2(30, 20, m2);

    Marine w;

    cout << "atak" << endl;
    cout << "health: " << m5.getHealth() << endl;
    m4.attackUnit(&m5);
    cout << "health: " << m5.getHealth() << endl;
    t1.attackUnit(&m5);
    cout << "health: " << m5.getHealth() << endl;

    vector<Unit*> us;
    us.push_back(&m1);
    us.push_back(&m2);
    us.push_back(&m3);
    us.push_back(&m4);
    us.push_back(&m5);
    us.push_back(&m6);
    us.push_back(&m7);
    us.push_back(&m8);
    us.push_back(&t1);
    us.push_back(&t2);

    GrupaBojowa g(us);

    g.attackUnit(&w);

    cout << "w health: " << w.getHealth() << endl;

    cout << "Zadanie 27.06 ========== " << endl;

    char* t = alokuj(3);
    t[2] = 'a';
    t[3] = 'b';
    t[4] = 'c';

    short rozmiar = (t[0] << 8) | t[1];

    for (int i = 2; i < rozmiar; i++) {
        cout << t[i];
    }
    cout << endl;

    zwolnij(t);

    cout << "po zwolnieniu t[2] = " << t[2] << endl;

    cout << "odczyt pliku:" << endl;

    odczytajPlik("plik.txt", 20);



    return 0;
}