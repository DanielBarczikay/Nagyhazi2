#ifndef AVATAR3_H
#define AVATAR3_H
#include "jatekos.h"

// Azertse Aladar (Avatar)
class Avatar3 : public Jatekos {
public:
	// Konstruktor
	Avatar3();

	// A játékos tippjét generálja le a saját algoritmusa alapján
	char tippel(const Statisztika& stat) const override;
};
#endif
