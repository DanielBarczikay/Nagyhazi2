#ifndef AVATAR4_H
#define AVATAR4_H
#include "jatekos.h"

// Statisztikus Sandor (Avatar)
class Avatar4 : public Jatekos {
public:
	// Konstruktor
	Avatar4();

	// A j�t�kos tippj�t gener�lja le a saj�t algoritmusa alapj�n
	char tippel(const Statisztika& stat) const override;
};
#endif
