// Zad1406.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>

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
    string nazwa;
    double cena;
    int min_wiek;
    Material material;

public:
    string getNazwa() {
        return nazwa;
    }

    void setNazwa(string n) {
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
        nazwa = "Samochod";
        cena = 29.99;
        min_wiek = 3;
        material = Material::Plastik;
    }

    Zabawka(string n, double c, int mw, Material m) {
        nazwa = n;
        cena = c;
        min_wiek = mw;
        material = m;
    }

    void wyswietl() {
        

        cout << nazwa << " " << cena << "zl " << " wiek min: " << min_wiek << " wykonano z: " << getMaterialStr() << endl;
    }

};

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

int main()
{
    Zabawka z1;
    z1.wyswietl();

    Zabawka z2("Mis", 19.99, 3, Material::Szmaciana);

    z2.setCena(-2);
    z2.setMinWiek(-2);

    z2.wyswietl();

    z2.setNazwa("Mis duzy");
    z2.setCena(38.99);
    z2.setMinWiek(4);
    z2.setMaterial(Material::Plastik);

    cout << "gettery:" << endl;

    cout << z2.getNazwa() << endl;
    cout << z2.getCena() << endl;
    cout << z2.getMinWiek() << endl;
    cout << z2.getMaterialStr() << endl;

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




    return 0;
}

###############################################################################################################
Aby dodać możliwość zliczania liczby instancji klasy Zabawka w programie, możemy użyć statycznego pola klasy, które będzie inkrementowane za każdym razem, gdy tworzona jest nowa instancja. Poniżej znajduje się zaktualizowany kod:

cpp
Copy code
#include <iostream>
#include <string>
using namespace std;

enum class Material
{
    Drewno,
    Plastik,
    Szmaciana
};

class Zabawka
{
private:
    string nazwa;
    double cena;
    int min_wiek;
    Material material;
    static int liczbaInstancji; // Statyczne pole przechowujące liczbę instancji

public:
    string getNazwa() {
        return nazwa;
    }

    void setNazwa(string n) {
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
        nazwa = "Samochod";
        cena = 29.99;
        min_wiek = 3;
        material = Material::Plastik;
        liczbaInstancji++; // Inkrementacja liczby instancji przy tworzeniu nowej instancji
    }

    Zabawka(string n, double c, int mw, Material m) {
        nazwa = n;
        cena = c;
        min_wiek = mw;
        material = m;
        liczbaInstancji++; // Inkrementacja liczby instancji przy tworzeniu nowej instancji
    }

    void wyswietl() {
        cout << nazwa << " " << cena << "zl " << " wiek min: " << min_wiek << " wykonano z: " << getMaterialStr() << endl;
    }

    static int getLiczbaInstancji() {
        return liczbaInstancji;
    }
};

// Inicjalizacja statycznego pola liczbaInstancji
int Zabawka::liczbaInstancji = 0;

int main()
{
    Zabawka z1;
    z1.wyswietl();

    Zabawka z2("Mis", 19.99, 3, Material::Szmaciana);

    z2.setCena(-2);
    z2.setMinWiek(-2);

    z2.wyswietl();

    z2.setNazwa("Mis duzy");
    z2.setCena(38.99);
    z2.setMinWiek(4);
    z2.setMaterial(Material::Plastik