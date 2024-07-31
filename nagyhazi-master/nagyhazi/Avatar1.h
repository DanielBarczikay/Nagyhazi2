#ifndef AVATAR1_H
#define AVATAR1_H
#include "jatekos.h"

// Random Robert (Avatar)
class Avatar1 : public Jatekos {
public:
	// Konstruktor
	Avatar1();

	// A játékos tippjét generálja le a saját algoritmusa alapján
	char tippel(const Statisztika& stat) const override;
};
#endif