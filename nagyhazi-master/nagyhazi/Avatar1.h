#ifndef AVATAR1_H
#define AVATAR1_H
#include "jatekos.h"

// Random Robert (Avatar)
class Avatar1 : public Jatekos {
public:
	// Konstruktor
	Avatar1();

	// A j�t�kos tippj�t gener�lja le a saj�t algoritmusa alapj�n
	char tippel(const Statisztika& stat) const override;
};
#endif