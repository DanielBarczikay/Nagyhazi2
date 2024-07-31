#include <iostream>
#include <fstream>
#include "memtrace.h"
#include "naplo.h"
#include "statisztika.h"
#include "jatekosok.h"
#include "jatekos.h"


// Uj jatek felv�tele
void Naplo::ujJatek(Jatek* const uj_jatek_tmp ) {
	uj_jatek_tmp->setKov(NULL);
	if (jatek_eleje == NULL) jatek_eleje = uj_jatek_tmp;
	// Ha nem �res v�gig kell menni a l�ncolt list�n
	else {
		Jatek* mozgo = jatek_eleje;
		while (mozgo->getKov() != NULL) {
			mozgo = mozgo->getKov();
		}
		mozgo->setKov(uj_jatek_tmp);
	}
}

// J�t�k napl� ment�se f�jlba
void Naplo::serialize() const {
	Jatek* temp = jatek_eleje;
	std::ofstream ofs("objects.dat", std::ios::binary);
	if (ofs.is_open()) {
		while (temp != NULL) {
			temp->serialize(ofs);
			temp = temp->getKov();
		}
		ofs.close();
	}
}

// J�t�k napl� visszaolvas�sa f�jlb�l
void Naplo::deserialize(Jatekosok& lista, Statisztika& stat) {
	std::string nev1;
	std::string nev2;
	int nameLength;
	char tipp1;
	char tipp2;
	char mn1;
	char mn2;
	Jatek* jatek_tmp;

	std::ifstream ifs("objects.dat", std::ios::binary);
	if (ifs.fail()) throw std::invalid_argument("Az input fajl nem talalhato!");
	while (!ifs.eof()) {
		if (ifs.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength))) {
			// Els� j�t�kos beolvas�sa
			// N�v beolvas�sa
			char* buffer = new char[nameLength + 1];
			ifs.read(buffer, nameLength);
			buffer[nameLength] = '\0';
			nev1 = buffer;
			delete[] buffer;
			// monogramm, tipus �s tipp beolvas�sa
			ifs.read(&mn1, sizeof(mn1));
			ifs.read(&tipp1, sizeof(tipp1));

			// M�sodik j�t�kos beolvas�sa
			// N�v beolvas�sa
			ifs.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
			char* buffer2 = new char[nameLength + 1];
			ifs.read(buffer2, nameLength);
			buffer2[nameLength] = '\0';
			nev2 = buffer2;
			delete[] buffer2;
			// monogramm, tipus �s tipp beolvas�sa
			ifs.read(&mn2, sizeof(mn2));
			ifs.read(&tipp2, sizeof(tipp2));

			// J�t�k l�trehoz�sa, felf�z�se			
			jatek_tmp = new Jatek(lista, stat, nev1, nev2, mn1, mn2, tipp1, tipp2);
			ujJatek(jatek_tmp);
		}
	}
	ifs.close();
}


// Destruktor
// Foglalt j�t�kter�letek t�rl�se
Naplo::~Naplo() {
	if (jatek_eleje != NULL) {
		Jatek* mozgo = jatek_eleje;
		Jatek* tmp = mozgo;
		while (mozgo->getKov() != NULL) {
			tmp = mozgo;
			mozgo = mozgo->getKov();
			delete tmp;
		}
		delete mozgo;
	}
}


// J�t�knapl� kiirat�sa
std::ostream& operator<<(std::ostream& os, Naplo& elem){
	Jatek* temp = elem.getJatek_eleje();

	os << "Jatek naplo\n";
	os << "-----------\n";
	while (temp != nullptr) {
		temp->kiirat();
		temp = temp->getKov();
	}
	os << "\n";
	return os;
}