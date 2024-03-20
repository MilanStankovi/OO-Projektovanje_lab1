#pragma once
#include "Trava.h"
class JajascaPuza : public Trava
{
	int kolicina;
	static int brojac;
public:
	JajascaPuza();
	~JajascaPuza();
	void otkri();
	void print();
	int getk() { return kolicina; };
	static int vrati_broj() { return brojac; };
};

