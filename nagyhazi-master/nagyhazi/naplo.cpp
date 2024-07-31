#include <iostream>
#include <fstream>
#include "memtrace.h"
#include "naplo.h"
#include "statisztika.h"
#include "jatekosok.h"
#include "jatekos.h"


// Uj jatek felvétele
void Naplo::ujJatek(Jatek* const uj_jatek_tmp ) {
	uj_jatek_tmp->setKov(NULL);
	if (jatek_eleje == NULL) jatek_eleje = uj_jatek_tmp;
	// Ha nem üres végig kell menni a láncolt listán
	else {
		Jatek* mozgo = jatek_eleje;
		while (mozgo->getKov() != NULL) {
			mozgo = mozgo->getKov();
		}
		mozgo->setKov(uj_jatek_tmp);
	}
}

// Játék napló mentése fájlba
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

// Játék napló visszaolvasása fájlból
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
			// Elsõ játékos beolvasása
			// Név beolvasása
			char* buffer = new char[nameLength + 1];
			ifs.read(buffer, nameLength);
			buffer[nameLength] = '\0';
			nev1 = buffer;
			delete[] buffer;
			// monogramm, tipus és tipp beolvasása
			ifs.read(&mn1, sizeof(mn1));
			ifs.read(&tipp1, sizeof(tipp1));

			// Második játékos beolvasása
			// Név beolvasása
			ifs.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
			char* buffer2 = new char[nameLength + 1];
			ifs.read(buffer2, nameLength);
			buffer2[nameLength] = '\0';
			nev2 = buffer2;
			delete[] buffer2;
			// monogramm, tipus és tipp beolvasása
			ifs.read(&mn2, sizeof(mn2));
			ifs.read(&tipp2, sizeof(tipp2));

			// Játék létrehozása, felfûzése			
			jatek_tmp = new Jatek(lista, stat, nev1, nev2, mn1, mn2, tipp1, tipp2);
			ujJatek(jatek_tmp);
		}
	}
	ifs.close();
}


// Destruktor
// Foglalt játékterületek törlése
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


// Játéknapló kiiratása
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