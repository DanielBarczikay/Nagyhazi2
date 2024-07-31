#ifndef JATEKOSOK_H
#define JATEKOSOK_H
#include "jatekos.h"

class Jatekosok {
private:
	// Játékosokat láncolt listában tároljuk
	Jatekos* jatekos_eleje;

public:
	// Konstruktor
	Jatekosok();

	Jatekos* getJatekos_eleje() const { return jatekos_eleje; }

	// Uj játékos felvietele a listába
	Jatekos* ujJatekos(const std::string& nev, const char& mn);

	// Játékos keresés a monogrammja alapján
	Jatekos* keres(const char& mn) const;

	// Játékos bekérése monogramm alapján 
	Jatekos* beker() const;

	// Destruktor
	~Jatekosok();
};

std::ostream& operator<<(std::ostream& os, const Jatekosok& jatekosok);

#endif
