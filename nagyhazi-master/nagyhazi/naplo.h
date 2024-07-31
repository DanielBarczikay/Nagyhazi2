#ifndef NAPLO_H
#define NAPLO_H
#include "jatek.h"
#include "statisztika.h"

class Naplo {
	// A játékok a naplóban láncolt listában vannak felfûzve
	Jatek* jatek_eleje = nullptr;

public:
	Jatek* getJatek_eleje() const { return jatek_eleje; }

	// Új játék felvitele a naplóban
	void ujJatek(Jatek* const uj_jatek_tmp);


	// Játék napló mentése fájlba
	void serialize() const;

	// Játék napló visszaolvasása fájlból
	void deserialize(Jatekosok& lista, Statisztika& stat);

	// Destruktor
	~Naplo();
};

std::ostream& operator<<(std::ostream& os, Naplo& elem);

#endif 