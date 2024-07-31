#ifndef AVATAR2_H
#define AVATAR2_H
#include "jatekos.h"

// Ismetlo Imre(Avatar)
class Avatar2 : public Jatekos {
public:
	// Konstruktor
	Avatar2();

	// A játékos tippjét generálja le a saját algoritmusa alapján
	char tippel(const Statisztika& stat) const override;
};
#endif