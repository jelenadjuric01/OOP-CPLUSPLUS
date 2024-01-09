#ifndef _tim_h_
#define _tim_h_
#include "igrac.h"
class Tim {
	void kopiraj(const Tim& t1);
	void premesti(Tim& t1) {
		t = t1.t;
		max = t1.max;
		br = t1.br;
		naziv = t1.naziv;
		t1.t = nullptr;
	}
	void obrisi();
protected:
	string naziv;
	int max;
	Igrac** t;
	int br;
	virtual void pisi(ostream& it) const;
public:
	Tim(string n, int m);
	Tim(const Tim& t1) { kopiraj(t1); }
	Tim(Tim&& t1) { premesti(t1); }
	virtual ~Tim() { obrisi(); }
	Tim& operator=(const Tim& t1) {
		if (this != &t1) {
			obrisi();
			kopiraj(t1);
		}
		return *this;
	}
	Tim& operator=(Tim&& t1) {
		if (this != &t1) {
			obrisi();
			premesti(t1);
		}
		return *this;
	}
	int dohvMax() const { return max; }
	virtual Tim& prikljuciIgraca(const Igrac& ig, int i);
	Igrac* operator[](int i);
	const Igrac* operator[](int i) const {
		return const_cast<Tim&>(*this)[i];
	}
	int brojIgraca()const { return br; }
	double vrednostTima() const;
	friend bool operator==(const Tim& t1, const Tim& t2);
	friend ostream& operator<<(ostream& it, const Tim& t1);

};
#endif // !_tim_h_

