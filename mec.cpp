#include "mec.h"
int POBEDA = 3, GUBITAK = 0, NER = 1;
void Mec::odigraj() {
	if (timovi.dohvPrvi()->vrednostTima() > timovi.dohvDrugi()->vrednostTima()) {
		ishod = Ishod::POBEDA_DOMACIN;
	}
	else if (timovi.dohvPrvi()->vrednostTima() < timovi.dohvDrugi()->vrednostTima()) {
		ishod = Ishod::POBEDA_GOST;
	}
	else ishod = Ishod::NERESENO;
	if (ishod == Ishod::POBEDA_DOMACIN) {
		for (int i = 0; i < timovi.dohvPrvi()->dohvMax(); i++) {
			if ((*timovi.dohvPrvi())[i]) {
				(*timovi.dohvPrvi())[i]->povecaj(10);
			}
		}
		for (int i = 0; i < timovi.dohvDrugi()->dohvMax(); i++) {
			if ((*timovi.dohvDrugi())[i]) {
				(*timovi.dohvDrugi())[i]->smanji(10);
			}
		}
	}
	else if (ishod == Ishod::POBEDA_GOST) {
		for (int i =0; i < timovi.dohvDrugi()->dohvMax(); i++) {
			if ((*timovi.dohvDrugi())[i]) {
				(*timovi.dohvDrugi())[i]->povecaj(10);
			}
		}
		for (int i = 0; i < timovi.dohvPrvi()->dohvMax(); i++) {
			if ((*timovi.dohvPrvi())[i]) {
				(*timovi.dohvPrvi())[i]->smanji(10);
			}
		}
	}
	odigran = true;
}
Par<int> Mec::poeni() const {
	if (!odigran) throw GNijeOdigran();
	Par<int> p(&NER, &NER);
	if (ishod == Ishod::POBEDA_DOMACIN) {
		p.postaviPrvi(&POBEDA);
		p.postaviDrugi(&GUBITAK);
	}
	else if (ishod == Ishod::POBEDA_GOST) {
		p.postaviDrugi(&POBEDA);
		p.postaviPrvi(&GUBITAK);
	}
	return p;
}

ostream& operator<<(ostream& it, const Mec& m)
{
	it << m.timovi;
	if (m.odigran) {
		string s[3] = { "POBEDA_DOMACIN", "NERESENO", "POBEDA_GOST"};
		it << " " <<s[m.ishod];
	}
	return it;
}