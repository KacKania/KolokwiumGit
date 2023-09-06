#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

enum Plec
{
    M = 0,
    K = 1
};

enum Stopien
{
    I = 1,
    II = 2,
    III = 3
};



struct Student
{
    string imie;
    string nazwisko;
    Plec plec;
    Stopien stopien;
    int semestr;


    Student(string i, string n, Plec p, Stopien s, int se)
    {
        imie = i;
        nazwisko = n;
        plec = p;
        stopien = s;
        semestr = se;
    }

    Student()
    {

    }

    void wyswietl()
    {
        string plecString = plec == M ? "M" : "K";
        string stopienString = stopien == I ? "I" : stopien == II ? "II" : "III";

        cout << imie << " " << nazwisko << " plec: " << plecString << " st: "
            << stopienString << " sem: " << semestr << endl;
    }

    string zapis()
    {
        int semestrliczba = semestr; //101
        int stopienLiczba = stopien << 3; //11 => 11000
        int plecLiczba = plec << 5; //1 => 100000

        int liczba = semestrliczba + stopienLiczba + plecLiczba;
        //111101 = 1 + 4 + 8 + 16 + 32 += 61

        return imie + ";" + nazwisko + ";" + to_string(liczba);
    }
};

void zapis(Student student)
{
    ofstream plik("student.txt");

    if (plik.is_open())
    {
        plik << student.zapis();

        plik.close();
    }
    else
    {
        cout << "blad zapisu do pliku..." << endl;
    }
}

Student odczyt()
{
    ifstream plik("student.txt");

    if (plik.is_open())
    {
        string linia;
        plik >> linia;
        stringstream ss(linia);
        string part;

        int i = 0;
        string im;
        string n;
        int p;
        int s;
        int se;


        while(ss.good()) {
            getline(ss, part, ';');

            if (i == 0)
            {
                im = part;
            }
            else if (i == 1)
            {
                n = part;
            }
            else
            {
                int liczba = stoi(part);

                //111101
                //&
                //000111
                //000101

                se = liczba & 0b00000111;
                s = (liczba & 0b11000) >> 3;
                p = (liczba & 0b100000) >> 5;     
            }

            i++;
        }

        Student student;
        student.imie = im;
        student.nazwisko = n;
        student.plec = (Plec)p;
        student.semestr = se;
        student.stopien = (Stopien)s;

        plik.close();

        return student;
    }
    else
    {
        cout << "blad odczytu z pliku..." << endl;
        Student student;
        return student;
    }
}

int main()
{
    Student s1("Jan", "Kowalski", M, II, 1);
    s1.wyswietl();

    zapis(s1);

    Student s2 = odczyt();
    s2.wyswietl();

    Student s3("Anna", "Nowak", K, III, 5);
    s3.wyswietl();

    zapis(s3);

    Student s4 = odczyt();
    s4.wyswietl();



    return 0;
}

