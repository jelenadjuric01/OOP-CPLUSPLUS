#ifndef _mec_h_
#define _mec_h_
#include "tim.h"
#include "privilegovanitim.h"
#include "par.h"
#include "greska.h"
class Mec {
public:
	enum Ishod { POBEDA_DOMACIN, NERESENO, POBEDA_GOST};
private:
	Par<Tim> timovi;
	Ishod ishod;
	bool odigran = false;
public:
	Mec(Tim& t1, Tim& t2) :timovi(&t1, &t2) {}
	Par<Tim> dohvTimove() const { return timovi; }
	void odigraj();
	bool odigranMec() const {
		return odigran;
	}
	Par<int> poeni() const;
	friend ostream& operator<<(ostream& it, const Mec& m);
};
#endif // !_mec_h_

