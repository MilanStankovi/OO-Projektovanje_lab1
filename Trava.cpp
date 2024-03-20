#include "Trava.h"
Trava::Trava(){
	otkriven = false;
	getkarakter() = ' ';
}
void Trava::print() {
	if (getotkriveno()) {
		cout << ' ';
	}
	else {
		cout << 'x';
	}
	cout << ' ';
}
void Trava::otkri() {
	otkriven = true;
}
bool Trava::getotkriveno() {
	return otkriven;
}