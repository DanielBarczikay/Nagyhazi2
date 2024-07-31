#ifndef HUMAN_H
#define HUMAN_H
#include <string>
#include "jatekos.h"

class Human : public Jatekos {
public:
	// Konstruktor, megkapja a j�t�kos nev�g �s monogrammj�t
	Human(std::string nev, char mn);

	// A j�t�kos tippj�t gener�lja le a saj�t algoritmusa alapj�n
	char tippel(const Statisztika& stat) const override;
};
#endif

