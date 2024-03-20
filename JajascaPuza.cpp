#include "JajascaPuza.h"
int JajascaPuza::brojac = 0;
JajascaPuza::JajascaPuza() {
	kolicina = 1;
	getkarakter() = 'j';
	brojac++;
}
void JajascaPuza::print() {
	if (getotkriveno()) {
		cout << 'j';
	}
	else {
		cout << 'x';
	}
	cout << ' ';
}
JajascaPuza::~JajascaPuza() {
	brojac--;
}
void JajascaPuza::otkri() {
	Trava::otkri();
	brojac--;
}