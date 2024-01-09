#ifndef _tacka_h_
#define _tacka_h_
#include <iostream>
#include <cmath>
using namespace std;
class Tacka {
	int x, y;
public:
	Tacka(int i,int k):x(i),y(k){}
	double udaljenost(const Tacka& t) const {
		return sqrt(pow(x-t.x,2)+pow(y-t.y,2));
	}
	friend bool operator==(const Tacka& t1, const Tacka& t2) {
		return t1.x == t2.x and t1.y == t2.y;
	}
	friend ostream& operator<<(ostream& it, const Tacka& t) {
		return it << "(" << t.x << "," << t.y << ")";
	}
};
#endif // !_tacka_h_

