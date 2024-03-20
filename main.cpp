#include "Livada.h"

int main() {
	Livada* l = new Livada();
	l->ucitaj("livada.txt");
	while (l->provera()) {
		l->mlaz();
	}
	l->otvorisve();
	l->prikaziLivadu();
	cout << l->brojbodova();
	return 0;
}