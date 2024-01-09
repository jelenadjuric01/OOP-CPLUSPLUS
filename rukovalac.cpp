#include "rukovalac.h"
#include "posiljka.h"
void Rukovalac::postaviId(Posiljka& p, int i) const
{
	p.id = i;
}

void Rukovalac::postaviArtikal(Posiljka& p, const Artikal& a) const
{
	p.a = a;
}

void Rukovalac::povecajCekanje(Posiljka& p, int c) const
{
	p.d.cekanje +=c;
}

void Rukovalac::povecajCenu(Posiljka& p, double c) const
{
	p.d.cena +=c;
}
