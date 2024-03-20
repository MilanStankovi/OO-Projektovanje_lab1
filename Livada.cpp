#include "Livada.h"
#include <fstream>
using namespace std;
Livada::Livada() {
	n = 0;
	mat = nullptr;
}
void Livada::ucitaj(const char* c) {
	char o;
	int k;
	ifstream ulaz(c);
	if (ulaz.good()) {
		ulaz >> n;
		mat = new Trava * *[n];
		for (int i = 0; i < n; i++) {
			mat[i] = new Trava * [n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ulaz >> o;
				switch (o) {
				case 's':
					ulaz >> k;
					mat[i][j] = new SemeRuza(k);
					break;
				case 'j':
					mat[i][j] = new JajascaPuza();
					break;
				default:
					mat[i][j] = new Trava();
					break;
				}
			}
		}
	}
	ulaz.close();
}
Livada::~Livada() {
	if (mat != nullptr) {
		for (int i = 0; i < n; i++) {
			delete[] mat[i];
		}
		delete[] mat;
		mat = nullptr;
	}
}
void Livada::mlaz() {
	int i;
	int j;
	int f = 0;
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			if (mat[a][b]->getkarakter() == 's' && mat[a][b]->getotkriveno()) {
				i = a;
				j = b;
				f = 1;
			}
		}
	}
	srand(time(0));
	if (f == 0) {
		i = rand() % (n);
		j = rand() % (n);
	}
	int x = rand() % (2) + 1;
	mat[i][j]->otkri();
	if (mat[i][j]->getkarakter() == 's') {
		int suma = x + mat[i][j]->getk();
		switch (suma) {
		case 2:
			RasteRuza(i,j);
			break;
		case 3:
			raseje(i,j);
			break;
		case 4:
			pojavaTrojanskeRuze(i, j);
			break;
		}
	}
	if (mat[i][j]->getkarakter() == 'j') {
		int suma = x + mat[i][j]->getk();
		switch (suma) {
		case 2:
			pojavaPuza(i, j);
			break;
		case 3:
			pojavaTrojanskogPuza(i, j);
			break;
		}
	}
		prikaziLivadu();
}
void Livada::RasteRuza(int i, int j) {
	delete mat[i][j];
	mat[i][j] = new Ruza();
	mat[i][j]->otkri();
}
void Livada::raseje(int i, int j) {
	int p = mat[i][j]->getk();
	delete mat[i][j];
	mat[i][j] = new Trava();
	mat[i][j]->otkri();
	int br = 0;
	for (int k = i - 1; k <= i + 1; k++) {
		for (int z = j - 1; z <= j + 1; z++) {
			if (k >= 0 && z >= 0 && k < n && z < n && mat[k][z]->getkarakter() == ' ' && br < p) {
				bool stanje;
				stanje = mat[k][z]->getotkriveno();
				delete mat[k][z];
				mat[k][z] = new SemeRuza(1);
				if (stanje) {
					mat[k][z]->otkri();
				}
			}
		}
	}
	bool stanje;
	stanje = mat[i][j]->getotkriveno();
	delete mat[i][j];
	mat[i][j] = new Trava();
	if (stanje) {
		mat[i][j]->otkri();
	}
}
void Livada::pojavaTrojanskeRuze(int i, int j) {
	delete mat[i][j];
	mat[i][j] = new TrojanskaRuza();
	mat[i][j]->otkri();
	for (int i = 0; i < 3; i++) {
		int k = rand() % (n);
		int z = rand() % (n);
		bool stanje;
		stanje = mat[k][z]->getotkriveno();
		delete  mat[k][z];
		mat[k][z] = new Ruza();
		if (stanje) {
			mat[k][z]->otkri();
		}
	}
}
void Livada::pojavaPuza(int i, int j) {
	bool stanje;
	stanje = mat[i][j]->getotkriveno();
	delete mat[i][j];
	mat[i][j] = new Puz();
	if(stanje){
	mat[i][j]->otkri();
	}
	for (int k = i - 1; k <= i + 1; k++) {
		for (int z = j - 1; z <= j + 1; z++) {
			if (k >= 0 && z >= 0 && k < n && z < n && (mat[k][z]->getkarakter() == 'r' || mat[k][z]->getkarakter() == 'R')) {
				bool stanje;
				stanje = mat[k][z]->getotkriveno();
				delete mat[k][z];
				mat[k][z] = new Trava();
				if (stanje) {
					mat[k][z]->otkri();
				}
			}
		}
	}
}
void Livada::pojavaTrojanskogPuza(int i, int j) {
	delete mat[i][j];
	mat[i][j] = new TrojanskiPuz();
	mat[i][j]->otkri();
	for (int i = 0; i < 3; i++) {
		int k = rand() % (n);
		int z = rand() % (n);
		bool stanje;
		stanje = mat[k][z]->getotkriveno();
		delete  mat[k][z];
		mat[k][z] = new Puz();
		if (stanje) {
			mat[k][z]->otkri();
		}
		pojavaPuza(k, z);
	}
}
void Livada::prikaziLivadu() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j]->print();
		}
		cout << endl;
	}
	cout << endl << endl;
}
void Livada::otvorisve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j]->otkri();
		}
	}
}
int Livada::brojbodova() {
	int br = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j]->getkarakter() == 'r' || mat[i][j]->getkarakter() == 'R') {
				br++;
			}
		}
	}
	return br;
}
bool Livada::provera() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j]->getkarakter() == 's' || mat[i][j]->getkarakter() == 'j') {
				return true;
			}
		}
	}
	return false;
}