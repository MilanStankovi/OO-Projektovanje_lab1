#include "TrojanskiPuz.h"
void TrojanskiPuz::print() {
	if (getotkriveno()) {
		cout << 'P';
	}
	else {
		cout << 'x';
	}
	cout << ' ';
}
TrojanskiPuz::TrojanskiPuz() {
	getkarakter() = 'P';
}