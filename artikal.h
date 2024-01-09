#ifndef _artikal_h_
#define _artikal_h_
#include <iostream>
using namespace std;
class Artikal {
	string naziv;
	int barkod;
	double ncena;
public:
	Artikal(string s,int i,double d):naziv(s),barkod(i),ncena(d){}
	string dohvNaziv() const { return naziv; }
	int dohvBarkod() const { return barkod; }
	double dohvNabavnuCenu() const { return ncena; }
	friend bool operator==(const Artikal& a1, const Artikal& a2) {
		return a1.barkod == a2.barkod;
	}
};
#endif // !_artikal_h_