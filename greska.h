#ifndef _greska_h_
#define _greska_h_
#include <exception>
using namespace std;

class GNemaTek :public exception {
public:
	GNemaTek():exception("Ne postoji tekuci element."){}
};
class GPoslata :public exception {
public:
	GPoslata():exception("Poruka je vec poslata."){}
};
#endif // !_greska_h_

