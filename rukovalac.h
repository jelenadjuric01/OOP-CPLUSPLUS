#ifndef _rukovalac_h_
#define _rukovalac_h_
#include "artikal.h"
class Posiljka;
class Rukovalac {
protected:
	virtual void obrada(Posiljka& p) = 0;
	void postaviId(Posiljka& p, int i)const;
	void postaviArtikal(Posiljka& p, const Artikal& a)const;
	void povecajCekanje(Posiljka& p, int c)const;
	void povecajCenu(Posiljka& p, double c) const;
public:
	friend Posiljka;
	virtual ~Rukovalac() {}
};
#endif // !_rukovalac_h_

