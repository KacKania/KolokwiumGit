#include <iostream>

using namespace std;

struct wektor
{
    double x;
    double y;

    wektor(double x1, double y1) {
        x = x1;
        y = y1;
    }

    bool operator ==(wektor& w2)
    {
        return this->x == w2.x && this->y == w2.y;
    }
};


template<typename T> int znajdzPierwsze(T* tab, int n, T* x)
{
    for (int i = 0; i < n; i++) {
        if (tab[i] == *x) {
            return i;
        }
    }

    throw exception("element not found");
}

template<typename T> int znajdzOstatnie(T* tab, int n, T* x)
{
    for (int i = n-1; i >= 0; i--) {
        if (tab[i] == *x) {
            return i;
        }
    }

    throw exception("element not found");
}



/*
int main()
{
    wektor w1(2, 3);
    wektor w2(3, 4);
    wektor w3(3, 4);
    wektor w4(5, 6);

    wektor tab[4] = { w1, w2, w3, w4 };

    wektor szukany(3, 4);


    try {
        int i = znajdzPierwsze(tab, 4, &szukany);
        cout << i << endl;
        i = znajdzOstatnie(tab, 4, &szukany);
        cout << i << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
*/

