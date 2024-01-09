#ifndef _poruka_h_
#define _poruka_h_
#include "korisnik.h"
class Poruka {
public:
	enum Stanje{U_PRIMREMI,POSLATA,PRIMLJENA};
private:
	Korisnik* pos, * prim;
	string naslov;
protected:
	Stanje s;
	virtual void pisi(ostream& it) const {
		it << naslov << endl;
		it << *pos << endl;
		it << *prim << endl;
	}
public:
	Poruka(Korisnik* po, Korisnik* pr, string n) {
		naslov = n;
		s = Stanje::U_PRIMREMI;
		pos = po; prim = pr;
	}
	Stanje dohvStanje() const { return s; }
	string dohvNaslon() const { return naslov; }
	const Korisnik* dohvPos() const { return pos; }
	const Korisnik* dohPrim() const { return prim; }
	friend ostream& operator<<(ostream& it, const Poruka& p) {
		p.pisi(it);
		return it;
	}
	virtual ~Poruka(){}
	virtual void posaljiPoruku() = 0;
	virtual Poruka* kopiraj() const = 0;
};
#endif // !_poruka_h_

