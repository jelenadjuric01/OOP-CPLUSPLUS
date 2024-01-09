#ifndef _igrac_h_
#define _igrac_h_
#include <iostream>
using namespace std;
class Igrac {
	string ime;
	int vr;
public:
	Igrac(string i, int v = 1000) :ime(i), vr(v) {}
	int dohvVr() const { return vr; }
	Igrac& povecaj(int p) {
		vr = vr + vr * p / 100;
		return *this;
	}
	Igrac& smanji(int p) {
		vr = vr - vr * p / 100;
		return *this;
	}
	friend bool operator==(const Igrac& i1, const Igrac& i2) {
		return i1.ime == i2.ime and i1.vr == i2.vr;
	}
	friend ostream& operator<<(ostream& it, const Igrac& i) {
		return it << i.ime << "#" << i.vr;
	}

};
#endif // !_igrac_h_

