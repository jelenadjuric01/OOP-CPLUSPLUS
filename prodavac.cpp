#include "prodavac.h"
void Prodavac::obrada(Posiljka& p)
{
	for (int i = 0; i < k.broj(); i++) {
		if (p.dohvArtikal() == k[i].a) {
			povecajCekanje(p, k[i].daninabavke);
			povecajCenu(p, k[i].a.dohvNabavnuCenu() * k[i].m);
		}
	}
}