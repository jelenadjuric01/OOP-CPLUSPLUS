#ifndef _put_h_
#define _put_h_
#include "tacka.h"
#include "lista.h"
#include "greska.h"
class Put {
	Lista<Tacka> tacke;
public:
	Put(){}
	Put& operator+=(Tacka& t);
	double duzina() const;
	friend ostream& operator<<(ostream& it, const Put& p);
};
#endif // !_put_h_

