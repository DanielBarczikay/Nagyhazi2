#ifndef AVATAR2_H
#define AVATAR2_H
#include "jatekos.h"

// Ismetlo Imre(Avatar)
class Avatar2 : public Jatekos {
public:
	// Konstruktor
	Avatar2();

	// A j�t�kos tippj�t gener�lja le a saj�t algoritmusa alapj�n
	char tippel(const Statisztika& stat) const override;
};
#endif