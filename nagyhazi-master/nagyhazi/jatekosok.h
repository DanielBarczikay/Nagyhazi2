#ifndef JATEKOSOK_H
#define JATEKOSOK_H
#include "jatekos.h"

class Jatekosok {
private:
	// J�t�kosokat l�ncolt list�ban t�roljuk
	Jatekos* jatekos_eleje;

public:
	// Konstruktor
	Jatekosok();

	Jatekos* getJatekos_eleje() const { return jatekos_eleje; }

	// Uj j�t�kos felvietele a list�ba
	Jatekos* ujJatekos(const std::string& nev, const char& mn);

	// J�t�kos keres�s a monogrammja alapj�n
	Jatekos* keres(const char& mn) const;

	// J�t�kos bek�r�se monogramm alapj�n 
	Jatekos* beker() const;

	// Destruktor
	~Jatekosok();
};

std::ostream& operator<<(std::ostream& os, const Jatekosok& jatekosok);

#endif
