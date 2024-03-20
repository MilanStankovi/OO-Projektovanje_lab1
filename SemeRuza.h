#pragma once
#include "Trava.h"
class SemeRuza : public Trava
{
	int kolicina;
	static int brojac;
public:
	SemeRuza(int x);
	~SemeRuza() { brojac--; };
	void otkri();
	void print();
	int getk() { return kolicina; };
	static int vrati_broj() { return brojac; };
};

