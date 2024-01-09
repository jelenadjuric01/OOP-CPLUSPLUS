#pragma once
#include "igrac.h"
#include "greska.h"
#include "tim.h"
class PrivilegovaniTim :public Tim {
	int min;
protected:
	virtual void pisi(ostream& it) const override;
public:
	PrivilegovaniTim(string s, int m, int mi) :Tim(s, m), min(mi) {

	}
	virtual PrivilegovaniTim& prikljuciIgraca(const Igrac& ig, int i) override {
		if (ig.dohvVr() < min) throw GMin();
		Tim::prikljuciIgraca(ig, i);

		return *this;
	}
};

