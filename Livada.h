#pragma once
#include "SemeRuza.h"
#include "JajascaPuza.h"
#include "Ruza.h"
#include "Puz.h"
#include "TrojanskaRuza.h"
#include "TrojanskiPuz.h"
#include <cstdlib>
#include <ctime>
class Livada
{
	Trava*** mat;
	int n;
public:
	Livada();
	~Livada();
	void ucitaj(const char* c);
	void mlaz();
	void RasteRuza(int i, int j);
	void raseje(int i, int j);
	void pojavaTrojanskeRuze(int i, int j);
	void pojavaPuza(int i, int j);
	void pojavaTrojanskogPuza(int i, int j);
	void prikaziLivadu();
	void otvorisve();
	int brojbodova();
	bool provera();
};

