#ifndef _prodavac_h_
#define _prodavac_h_
#include "posiljka.h"

class Prodavac:public Rukovalac {
	string ime;
	struct Katalog {
		Artikal a;
		double m;
		int daninabavke;
		Katalog(const Artikal& ar, double ma,int d):a(ar),m(ma),daninabavke(d){}
	};
	Lista<Katalog> k; 
protected:
	void obrada(Posiljka& p) override;
public:
	Prodavac(string i):ime(i){}
	Prodavac& dodajKatalog(const Artikal& ar, double ma, int d) {
		Katalog k1(ar, ma, d);
		k += k1;
		return *this;
	}
	string dohvNaziv()const { return ime; }
};
#endif // !_prodavac_h_

