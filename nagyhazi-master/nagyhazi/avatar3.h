#ifndef AVATAR3_H
#define AVATAR3_H
#include "jatekos.h"

// Azertse Aladar (Avatar)
class Avatar3 : public Jatekos {
public:
	// Konstruktor
	Avatar3();

	// A j�t�kos tippj�t gener�lja le a saj�t algoritmusa alapj�n
	char tippel(const Statisztika& stat) const override;
};
#endif
