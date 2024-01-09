#ifndef _porukaSaTekstom_h_
#define _porukaSaTekstom_h_
#include "poruka.h"
#include "greska.h"
class PorukaSaTekstom:public Poruka {
	string tekst;
	virtual void pisi(ostream& it) const override {
		Poruka::pisi(it);
		it << tekst;
	}
public:
	PorukaSaTekstom(Korisnik* po, Korisnik* pr, string n):Poruka(po,pr,n){}
	PorukaSaTekstom& postaviTekst(string s) {
		if (dohvStanje() == Poruka::Stanje::POSLATA) throw GPoslata();
		tekst = s;
		return *this;
	}
	virtual void posaljiPoruku() override {
		s = Poruka::Stanje::POSLATA;
	}
	virtual PorukaSaTekstom* kopiraj() const override {
		return new PorukaSaTekstom(*this);
	}
};
#endif // !_porukaSaTekstom_h_

