#ifndef _lista_h_
#define _lista_h_
#include "greska.h"

template<typename T>
class Lista {
	struct Elem {
		T pod;
		Elem* sled;
		Elem(const T& t,Elem* s=nullptr):pod(t),sled(s){}
	};
	Elem* prvi, * posl;
	mutable Elem* tek;
	int br;
	void kopiraj(const Lista& l);
	void premesti(Lista& l) {
		prvi = l.prvi; posl = l.posl; tek = l.tek; br = l.br;
		l.prvi = l.posl = l.tek = nullptr;
	}
	void obrisi();
public:
	Lista() { prvi = posl = tek = nullptr; br = 0; }
	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	Lista& operator=(const Lista& l) {
		if (this != &l) {
			obrisi();
			kopiraj(l);
		}
		return *this;
	}
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			obrisi();
			premesti(l);
		}
		return *this;
	}
	~Lista() { obrisi(); }
	Lista& dodaj(const T& t) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(t);
		br++;
		return *this;
	}
	int broj() const { return br; }
	void naPrvi() const { tek = prvi; }
	void naSled() const { if (tek) tek = tek->sled; }
	bool imaTek() const { return tek != nullptr; }
	T& dohvTek() const {
		if (!tek) throw GNemaTek();
		return tek->pod;
	}
};
template<typename T>
void Lista<T>::kopiraj(const Lista& l)
{
	prvi = posl = tek = nullptr;
	br = l.br;
	for (Elem* tren = l.prvi; tren; tren = tren->sled) {
		Elem* novi = new Elem(tren->pod);
		posl = (!prvi ? prvi : posl->sled) = novi;
		if (novi == l.tek) tek = novi;
	}
}
template<typename T>
void Lista<T>::obrisi()
{
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	posl = tek = nullptr;
	br = 0;
}
#endif // !_lista_h_

