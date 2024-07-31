#include <iostream>
#include "memtrace.h"
#include "jatekosok.h"
#include "avatar1.h"
#include "avatar2.h"
#include "avatar3.h"
#include "avatar4.h"
#include "human.h"


// Konstruktor
// Be�p�tett Avatar j�t�kosok automatikus felv�tele
Jatekosok::Jatekosok() {
	jatekos_eleje = NULL;
	Avatar1* tmp_jatekos_1 = new Avatar1();
	Avatar2* tmp_jatekos_2 = new Avatar2();
	Avatar3* tmp_jatekos_3 = new Avatar3();
	Avatar4* tmp_jatekos_4 = new Avatar4();
	jatekos_eleje = tmp_jatekos_1;
	tmp_jatekos_1->setKov(tmp_jatekos_2);
	tmp_jatekos_2->setKov(tmp_jatekos_3);
	tmp_jatekos_3->setKov(tmp_jatekos_4);
}

// J�t�kos keres�s a monogrammja alapj�n
Jatekos* Jatekosok::keres(const char& mn) const {
	Jatekos* mozgo = jatekos_eleje;
	while (mozgo != NULL) {
		if (mozgo->getMn() == mn) return mozgo;
		mozgo = mozgo->getKov();
	}
	return NULL;
}

// J�t�kos bek�r�se monogramm alapj�n 
Jatekos* Jatekosok::beker() const {
	char mn;
	mn = ' ';
	std::cout << "Jatekos\n";
	std::cout << "-------\n";
	while (keres(mn) == NULL) {
		std::cout << "Valaszd ki a jatekost, add meg a monogrammjat!\n";
		std::cin >> mn;
	}
	return keres(mn);
}

// Uj jatekosok felv�tele
Jatekos* Jatekosok::ujJatekos(const std::string& nev, const char& mn) {
	Jatekos* mozgo = jatekos_eleje;
	while (mozgo->getKov() != NULL && mozgo->getMn() != mn) {
		mozgo = mozgo->getKov();
	}

	// N�vegyez�s, van m�r ilye j�t�kos
	if (mozgo->getMn() == mn) {
		return (Jatekos*)mozgo;
	}
	// �j Human j�t�kos felv�tele
	else {
		Human* uj_jatekos = new Human(nev, mn);
		// L�ncolt lista v�g�re f�zz�k a j�t�kost
		mozgo->setKov(uj_jatekos);
		return uj_jatekos;
	}
}

// Destruktor
// A j�t�kosok felszabad�t�sa
Jatekosok::~Jatekosok() {
	Jatekos* mozgo = jatekos_eleje;
	Jatekos* tmp = mozgo;
	while (mozgo->getKov() != NULL) {
		tmp = mozgo;
		mozgo = mozgo->getKov();
		delete tmp;
	}
	delete mozgo;
}

std::ostream& operator<<(std::ostream& os, const Jatekosok& jatekosok) {
	Jatekos* temp = jatekosok.getJatekos_eleje();
	os << "Jatekosok\n" << "---------\n";
	while (temp != NULL) {
		temp->kiirat();
		temp = temp->getKov();
	}
	os << "\n";
	return os;
}
