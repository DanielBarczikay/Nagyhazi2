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

// Kiir�ja az aktu�lis j�t�kos adatai
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

// F�jlba ki�rja az aktu�lis j�t�kos adatait
void Jatekos::serialize(std::ofstream &ofs) {
	int nameLength1 = nev.length();
	ofs.write(reinterpret_cast<char*>(&nameLength1), sizeof(nameLength1));
	ofs.write(nev.c_str(), nameLength1);
	ofs.write(&mn, sizeof(mn));
}

// N�veli a nyertes j�tszm�k darabsz�m�t
void Jatekos::incNyert() {
	nyert_db++;
}

// N�veli a d�ntetlen j�tszm�k darabsz�m�t
void Jatekos::incDontetlen() {
	dontetlen_db++;
}

// N�veli a vesztes j�tszm�k darabsz�m�t
void Jatekos::incVesztett() {
	vesztett_db++;
}

// Destruktor
Jatekos::~Jatekos() {};