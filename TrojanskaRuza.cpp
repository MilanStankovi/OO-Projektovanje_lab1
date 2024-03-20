#include "TrojanskaRuza.h"
void TrojanskaRuza::print() {
	if (getotkriveno()) {
		cout << 'R';
	}
	else {
		cout << 'x';
	}
	cout << ' ';
}
TrojanskaRuza::TrojanskaRuza() {
	getkarakter() = 'R';
}