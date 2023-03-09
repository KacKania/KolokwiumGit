#pragma once
#include <cmath>
#include <iomanip>
#include <time.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
constexpr size_t kolumny = 10;

void Sortuj(int(*tab)[kolumny],const int wiersze);

void Sortuj(int(*tab)[kolumny]);

void SortIter(int tab[], int wiersze);

int *SortRek(int tab[], int left, int right);

void wypisz(int(*tab)[kolumny], const int wiersze);