#include "tim.h"
void Tim::kopiraj(const Tim& t1)
{
	naziv = t1.naziv;
	this->t = nullptr;
	br = t1.br;
	max = t1.max;
	this->t = new Igrac * [max];
	for (int i = 0; i < max; i++) {
		if (t1.t[i]) {
			t[i] = new Igrac(*t1.t[i]);
		}
		else t[i] = nullptr;
	}
}
void Tim::obrisi()
{
	for (int i = 0; i < max; i++) {
		if (t[i] != nullptr)
			delete this->t[i];
	}
	delete[] t;
	br = max = 0;
	t = nullptr;
	naziv = "";
}
void Tim::pisi(ostream& it) const
{
	int b = br;
	it << naziv << "[";
	for (int i = 0; i < max; i++) {
		if (t[i]) {
			it << *t[i];
			b--;
			if (b) it << " ,";

		}
	}
	it << "]";
}
Tim::Tim(string n, int m)
{
	t = new Igrac * [m];
	naziv = n;
	max = m;
	for (int i = 0; i < max; i++) {
		t[i] = nullptr;
	}
}

Tim& Tim::prikljuciIgraca(const Igrac& ig, int i)
{
	if (t[i] != nullptr) {
		*t[i] = ig;
	}
	else {
		t[i] = new Igrac(ig);
		br++;
	}
	return *this;
}

Igrac* Tim::operator[](int i)
{
	return t[i];
}

double Tim::vrednostTima() const
{
	double vred = 0;
	for (int i = 0; i < max; i++) {
		if (t[i] != nullptr) {
			vred += t[i]->dohvVr();
		}
	}
	if (vred) {
		return vred / br;
	}
	else return 0;
}
bool operator==(const Tim& t1, const Tim& t2)
{
	if (t1.naziv != t2.naziv or t1.max != t2.max) return false;
	for (int i = 0; i < t1.max; i++) {
		if (t1[i] and t2[i]) {
			if (!(*t1[i] == *t2[i])) return false;
		}
		else if ((t1[i] and !t2[i]) or (!t1[i] and t2[i])) return false;

	}
	return true;
}
ostream& operator<<(ostream& it, const Tim& t1)
{
	t1.pisi(it);
	return it;

}
