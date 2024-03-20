#include "Puz.h"
void Puz::print() {
	if (getotkriveno()) {
		cout << 'p';
	}
	else {
		cout << 'x';
	}
	cout << ' ';
}
Puz::Puz() {
	getkarakter() = 'p';
}