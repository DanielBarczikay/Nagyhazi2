#ifndef NAPLO_H
#define NAPLO_H
#include "jatek.h"
#include "statisztika.h"

class Naplo {
	// A j�t�kok a napl�ban l�ncolt list�ban vannak felf�zve
	Jatek* jatek_eleje = nullptr;

public:
	Jatek* getJatek_eleje() const { return jatek_eleje; }

	// �j j�t�k felvitele a napl�ban
	void ujJatek(Jatek* const uj_jatek_tmp);


	// J�t�k napl� ment�se f�jlba
	void serialize() const;

	// J�t�k napl� visszaolvas�sa f�jlb�l
	void deserialize(Jatekosok& lista, Statisztika& stat);

	// Destruktor
	~Naplo();
};

std::ostream& operator<<(std::ostream& os, Naplo& elem);

#endif 