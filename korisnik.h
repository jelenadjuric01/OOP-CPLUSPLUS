#ifndef _korisnik_h_
#define _korisnik_h_
#include <iostream>
using namespace std;
class Korisnik {
	string ime, adresa;
public:
	Korisnik(string i,string a):ime(i),adresa(a){}
	Korisnik(const Korisnik&) = delete;
	Korisnik& operator=(const Korisnik&) = delete;
	friend ostream& operator<<(ostream& it, const Korisnik& k) {
		return it << "(" << k.ime << ")" << k.adresa;
	}
};
#endif // !_korisnik_h_

