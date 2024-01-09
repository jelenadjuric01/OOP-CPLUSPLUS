#ifndef _ovozilo_h_
#define _ovozilo_h_
#include "vozilo.h"

class OVozilo :public Vozilo {
protected:
	double dohvSCenu() const { return 120; }
public:
	OVozilo(string i):Vozilo(i){}
};

#endif // !_ovozilo_h_

