#ifndef _oznaka_h_
#define _oznaka_h_
#include <iostream>
using namespace std;

class Oznaka {
	int god, mes, dan, sat, min;
public:
	Oznaka(int g,int m,int d,int s,int mi):god(g),mes(m),dan(d),sat(s),min(mi){}
	friend ostream& operator<<(ostream& it, const Oznaka& o) {
		return it << o.dan << "." << o.mes << "." << o.god << "-" << o.sat << ":" << o.min;
	}

};
#endif // !_oznaka_h_
