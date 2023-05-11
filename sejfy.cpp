#include<iostream>

using namespace std;

class Osoba
{
	
};

class ZamekCyfrowy
{
	private:
		int n;
		Osoba* osoby[3];
	public:
		ZamekCyfrowy(){
			n = 0;
		}
		
		void dodaj(Osoba* os){
			if(n < 3){	
				osoby[n] = os;
				n++;
			} 
			else {
				cout << "mozna dodac max 3 osoby" << endl;
			}
		}
		
		void ustawOsobe(int i, Osoba* os){
			if(i < 0 || i > n){
				cout << "niepoprawny numer osoby" << endl;
			} 
			else {
				osoby[i] = os;
			}
		}
		
		bool sprawdzDostep(Osoba* os){
			if(n == 0){
				return true;
			}
			
			for(int i = 0; i < n; i++){
				//cout << "&osoba[i] = " << osoby[i] << " &os = " << os << endl;
				if(osoby[i] == os){
					return true;
				}
			}
			
			return false;
		}
		
		void wyczysc(){
			n = 0;
		}
};

class Sejf
{
	private:
		double tablica[5];
		ZamekCyfrowy zamek;
		
	public:
		Sejf(Osoba* os){
			zamek.dodaj(os);
		}
		
		void odczytaj(Osoba* os, int i){
			if(zamek.sprawdzDostep(os)){
				if(i < 0 || i >= 5){
					cout << "nieprawidlowy numer liczby" << endl;
				}
				else {	
					cout << "odczytano: " << tablica[i] << endl;
				}
			} 
			else {
				cout << "brak dostepu dla tej osoby" << endl;
			}
		}
		
		void zapisz(Osoba* os, int i, double val){
			if(zamek.sprawdzDostep(os)){
				if(i < 0 || i >= 5){
					cout << "nieprawidlowy numer liczby" << endl;
				} 
				else {
					tablica[i] = val;
					cout << "zapisano: " << tablica[i] << endl;
				}
			}
			else {
				cout << "brak dostepu dla tej osoby" << endl;
			}		
		}
		
		void wyczyscZamek(){
			zamek.wyczysc();
		}
		
		void dodajOsobe(Osoba* os){
			zamek.dodaj(os);
		}
};

int main()
{
	Osoba os1;
	Osoba os2;
	Osoba os3;
	Osoba os4;
	
	Sejf sejf(&os1);
	
	sejf.zapisz(&os1,0,1.5);
	sejf.odczytaj(&os1,0);
	
	sejf.dodajOsobe(&os2);
	sejf.dodajOsobe(&os3);
	sejf.dodajOsobe(&os4);
	
	sejf.zapisz(&os2,1,2.7);
	sejf.odczytaj(&os3,1);
	
	sejf.odczytaj(&os4,1);
	
	sejf.wyczyscZamek();
	
	sejf.odczytaj(&os4,1);
	
	
	return 0;
}
