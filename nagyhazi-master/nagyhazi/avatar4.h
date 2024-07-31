#ifndef AVATAR4_H
#define AVATAR4_H
#include "jatekos.h"

// Statisztikus Sandor (Avatar)
class Avatar4 : public Jatekos {
public:
	// Konstruktor
	Avatar4();

	// A játékos tippjét generálja le a saját algoritmusa alapján
	char tippel(const Statisztika& stat) const override;
};
#endif
