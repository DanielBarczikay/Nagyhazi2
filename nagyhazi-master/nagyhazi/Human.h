#ifndef HUMAN_H
#define HUMAN_H
#include <string>
#include "jatekos.h"

class Human : public Jatekos {
public:
	// Konstruktor, megkapja a játékos nevég és monogrammját
	Human(std::string nev, char mn);

	// A játékos tippjét generálja le a saját algoritmusa alapján
	char tippel(const Statisztika& stat) const override;
};
#endif

