#include "privilegovanitim.h"

void PrivilegovaniTim::pisi(ostream& it) const
{
	int b = br;
	it << naziv << "(" << min << ")" << "[";
	for (int i = 0; i < max; i++) {
		if (t[i]) {
			it << *t[i];
			b--;
			if (b) it << " ,";

		}
	}
	it << "]";
}
