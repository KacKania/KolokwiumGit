#include<iostream>
#include<string.h>

using namespace std;

enum TypTowaru { ciekly, sypki, paczkowany };

class SamochodCiezarowy
{
private:
	double m_predkosc;
	char m_numerRej[9];
	double m_pojemnosc;
	TypTowaru m_typ;

	void setPojemnosc(double i_poj) { m_pojemnosc = (i_poj > 1000) ? i_poj : 1000; }
	void setPredkosc(double i_pred) { m_predkosc = (i_pred > 160) ? i_pred : 160; }

public:
	void setTyp(TypTowaru i_typ) { m_typ = i_typ; }
	void setNumerRej(const char* i_num) { strncpy(m_numerRej, i_num, 8); }

	TypTowaru getTyp() { return m_typ; }
	const char* getNumerRej() { return m_numerRej; }
	double getPredkosc() { return m_predkosc; }
	double getPojemnosc() { return m_pojemnosc; }

	SamochodCiezarowy(double i_pred, double i_poj, TypTowaru i_typ, const char* i_num)
	{
		setPredkosc(i_pred);
		setPojemnosc(i_poj);
		setNumerRej(i_num);
		setNumerRej(i_num);
		m_typ = i_typ;
	}
};

class Flota
{

	private:
		SamochodCiezarowy* samochody[20];
		int n;
		
	public:
		Flota(){
			n = 0;
			for(int i = 0; i < 20; i++){
				samochody[i] = NULL;
			}
		}
		
		void dodaj(SamochodCiezarowy* s){		
			if(n >= 20){
				cout << "osiagnieto maksymalna liczbe samochodow 20" << endl;
				return;
			}
			
			for(int i = 0; i < n; i++){
				if(samochody[i] == s){
					cout << "ten samochod zostal juz przypisany" << endl;
					return;
				}
			}
			
			samochody[n] = s;
			n++;
		}
		
		void usun(SamochodCiezarowy* s){
			int indeks = -1;
			for(int i = 0; i < n; i++){
				if(samochody[i] == s){
					indeks = i;
				}
			}
			
			if(indeks == -1){
				cout << "brak wskazanego samochodu we flocie" << endl;
				return;
			}
			
			for(int i = indeks; i < n; i++){
				samochody[i] = samochody[i+1];
			}
			
			samochody[n] = NULL;
			n--;
		}
		
		double sumarycznaPojemnosc(){
			double wynik = 0;
			
			for(int i = 0; i < n; i++){
				wynik += samochody[i]->getPojemnosc();
			}
			
			return wynik;
		}
		
		friend ostream& operator << (ostream& stream, const Flota& flota){
			for(int i = 0; i < flota.n; i++){
				SamochodCiezarowy* samochod = flota.samochody[i];
				
				string typStr;
				
				TypTowaru typ = samochod->getTyp();
				
				switch(typ)
				{
					case ciekly:
						typStr = "ciekly";
						break;
					case sypki:
						typStr = "sypki";
						break;
					case paczkowany:
						typStr = "paczkowany";
						break;
					default:
						typStr = "brak";
						break;				
				}
				
				stream << "typ: " << typStr << " rej: " << samochod->getNumerRej() 
				<< " predkosc: " << samochod->getPredkosc() << " poj: " << samochod->getPojemnosc() << endl;
			}
			
			return stream;
		}	
};


int main()
{
	SamochodCiezarowy sc1(170,2000,ciekly,"ABC1234");
	SamochodCiezarowy sc2(176,3400,sypki,"ABC1235");
	SamochodCiezarowy sc3(181,2800,paczkowany,"ABC1236");
	
	Flota flota;
	
	flota.dodaj(&sc1);
	flota.dodaj(&sc2);
	flota.dodaj(&sc3);
	
	cout << flota << endl;
	
	cout << "calkowita pojemnosc: " << flota.sumarycznaPojemnosc() << endl;
	
	cout << "usuwanie " << endl;
	
	flota.usun(&sc2);
	
	cout << flota << endl;
	
	cout << "calkowita pojemnosc: " << flota.sumarycznaPojemnosc() << endl;
	
	return 0;
}
