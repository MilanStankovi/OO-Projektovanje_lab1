#include "SemeRuza.h"
int SemeRuza::brojac = 0;
SemeRuza::SemeRuza(int x) {
	kolicina = x;
	getkarakter() = 's';
	brojac++;
}
void SemeRuza::print() {
	if (getotkriveno()) {
		cout << 's';
	}
	else {
		cout << 'x';
	}
	cout << ' ';
}
void SemeRuza::otkri() {
	Trava::otkri();
	brojac--;
}