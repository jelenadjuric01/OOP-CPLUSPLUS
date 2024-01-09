#ifndef _posiljka_h_
#define _posiljka_h_
#include "lista.h"
#include "rukovalac.h"
class Posiljka {
	Artikal a;
	static int posl_id;
	int id = ++posl_id;
	Lista<Rukovalac*> r;
public:
	struct Detalji {
		int cekanje = 0;
		double cena = 0;
	};
private:
	Detalji d;
	bool izrdetalji = false;
public:
	friend Rukovalac;
	Posiljka(const Artikal& ar) :a(ar) {}
	Posiljka& operator+=(Rukovalac& ru) {
		if (izrdetalji) throw GRukovalac();
		r += (&ru);
		return *this;
	}
	void izracDetalje();
	Artikal dohvArtikal() const { return a; }
	int dohvId() const { return id; }
	Detalji dohvDetalje() const {
		if (!izrdetalji) throw GDetalji();
		return d;
	}
	friend ostream& operator<<(ostream& it, const Posiljka& p);
};
#endif // !_posiljka_h_
