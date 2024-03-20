#include "Ruza.h"
void Ruza::print() {
	if (getotkriveno()) {
		cout << 'r';
	}
	else {
		cout << 'x';
	}
	cout << ' ';
}
Ruza::Ruza() {
	getkarakter() = 'r';
}