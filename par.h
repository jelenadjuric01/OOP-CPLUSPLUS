#ifndef _par_h_
#define _par_h_
#include <iostream>
using namespace std;
template<typename T>
class Par {
	T* prvi, * drugi;
public:
	Par(T* t1, T* t2) :prvi(t1), drugi(t2) {}
	T* dohvPrvi() { return prvi; }
	const T* dohvPrvi() const { return prvi; }
	T* dohvDrugi() { return drugi; }
	const T* dohvDrugi() const { return drugi; }
	Par& postaviPrvi(T* t) {
		prvi = t;
		return *this;
	}
	Par& postaviDrugi(T* t) {
		drugi = t;
		return *this;
	}
	friend bool operator==(const Par& p1, const Par& p2) {
		return *p1.dohvPrvi() == *p2.dohvPrvi() and *p1.dohvDrugi() == *p2.dohvDrugi();
	}
	friend ostream& operator<<(ostream& it, const Par& p) {
		return it << "[" << *p.dohvPrvi() << "-" << *p.dohvDrugi()<<"]";
	}
};

#endif // !_par_h_

