#include "put.h"

Put& Put::operator+=(Tacka& t)
{
	for (int i = 0; i < tacke.broj(); i++) {
		if (t == tacke[i]) throw GIstaTacka();
	}
	tacke += t;
	return *this;
}

double Put::duzina() const
{
	double d = 0;
	for (int i = 0; i < tacke.broj() - 1; i++) {
		d += tacke[i].udaljenost(tacke[i + 1]);
	}
	return d;
}

ostream& operator<<(ostream& it, const Put& p)
{
	for (int i = 0; i < p.tacke.broj(); i++) {
		it << p.tacke[i] << endl;
	}
	return it;
}
