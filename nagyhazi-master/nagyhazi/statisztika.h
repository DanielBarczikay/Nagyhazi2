#ifndef STATISZIKA_H
#define STATISZIKA_H

class Statisztika{
	int ko_db;
	int papir_db;
	int ollo_db;

	// Eltároljuk, hogy ki nyert az utolsó körben
	char utolso_nyert;			

public:
	// Konstruktor
	Statisztika() :ko_db(0), papir_db(0), ollo_db(0), utolso_nyert(' ') {}

	//Getterek
	int getKo() const { return ko_db; }
	int getPapir() const { return papir_db; }
	int getOllo() const { return ollo_db; }
	char getUtolso() const { return utolso_nyert; }

	// Megadja melyik tipp nyert a legtöbbször
	char legtobb_nyert() const;

	// Statisztikai adatok frissítése aktuális nyert tipp alapján
	void frissit(const char &tipp);
};

// Kiíró operátor
std::ostream& operator<<(std::ostream& os, Statisztika& stat);

#endif 
