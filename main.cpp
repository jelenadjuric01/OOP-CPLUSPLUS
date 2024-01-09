#include "oznaka.h"
#include "korisnik.h"
#include "porukaSaTekstom.h"
#include "lista.h"
int main() {
	try {
		Oznaka o(2022, 1, 1, 13, 56);
		Oznaka o2 = o;
		//cout << o << endl << o2 << endl;
		Korisnik k1("Jelena", "mejl"), k2("Milica", "m");
		PorukaSaTekstom p(&k1, &k2, "poruka");
		//p.postaviTekst("bla");
		//p.posaljiPoruku();
		//Poruka* p1 = p.kopiraj();
		//p.postaviTekst("bla1");
		cout << p;
		//delete p1;
	}
	catch (exception e) {
		cout << e.what();
	}
	return 0;
}