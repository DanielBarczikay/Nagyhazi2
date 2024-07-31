#include <iostream>
#include <fstream>
#include <string>
#include "memtrace.h"
#include "jatekos.h"
#include "statisztika.h"


// Setter
void Jatekos::setKov(Jatekos* const kov) {
	this->kov = kov;
}

// Kiiríja az aktuális játékos adatai
void Jatekos::kiirat() const{
	std::cout << mn;
	std::cout << " - ";
	std::cout << nev;
	std::cout << " (nyert: ";
	std::cout << nyert_db;
	std::cout << ", dontetlen: ";
	std::cout << dontetlen_db;
	std::cout << ", vesztett: ";
	std::cout << vesztett_db;
	std::cout << ") ";
	std::cout << "\n";
}

// Fájlba kiírja az aktuális játékos adatait
void Jatekos::serialize(std::ofstream &ofs) {
	int nameLength1 = nev.length();
	ofs.write(reinterpret_cast<char*>(&nameLength1), sizeof(nameLength1));
	ofs.write(nev.c_str(), nameLength1);
	ofs.write(&mn, sizeof(mn));
}

// Növeli a nyertes játszmák darabszámát
void Jatekos::incNyert() {
	nyert_db++;
}

// Növeli a döntetlen játszmák darabszámát
void Jatekos::incDontetlen() {
	dontetlen_db++;
}

// Növeli a vesztes játszmák darabszámát
void Jatekos::incVesztett() {
	vesztett_db++;
}

// Destruktor
Jatekos::~Jatekos() {};