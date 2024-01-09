#include "posiljka.h"
#include "rukovalac.h"
int Posiljka::posl_id = 0;

void Posiljka::izracDetalje()
{
	for (int i = 0; i < r.broj(); i++) {
		r[i]->obrada(*this);
	}
	izrdetalji = true;
}

ostream& operator<<(ostream& it, const Posiljka& p)
{
	return it << "Posiljka[" << p.id << ", " << p.a.dohvNaziv() << "]";
}
