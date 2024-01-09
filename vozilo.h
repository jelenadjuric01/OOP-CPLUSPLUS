#ifndef _vozilo_h_
#define _vozilo_h_
#include <iostream>
#include "put.h"
using namespace std;
class Vozilo {
	string model;
protected:
	virtual double dohvSCenu() const = 0;
public:
	Vozilo(string i):model(i){}
	virtual ~Vozilo() {}
	friend ostream& operator<<(ostream& it, const Vozilo& v) {
		return it << v.model;
	}
	double cenaPrevoza(const Put& p) const {
		return dohvSCenu() + 0.1 * p.duzina();
	}
};
#endif // !_vozilo_h_

