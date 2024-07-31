#ifndef JATEKOS_H
#define JATEKOS_H
#include <fstream>
#include <string>
#include "statisztika.h"


// Játékos õsosztály
// Ebbõl fognak leszármazni a különbözõ algoritmusokkal játszó gépi játékosok és az emberi játékosok
class Jatekos {
protected:
	std::string nev;			// Játékos neve
	char mn;			// Játékos monogrammja
	Jatekos* kov;		// Mutató a láncolt listába fûzött játékosokról
	int nyert_db;		// Játékos által nyert játékok száma
	int dontetlen_db;	// Játékos által döntetlen játékainak száma
	int vesztett_db;	// Játékos vesztett játékainak száma

public:
	// Konstruktor
	Jatekos(): mn(' '), kov(NULL), nyert_db(0), dontetlen_db(0), vesztett_db(0) {}

	// Getter
	Jatekos* getKov() const { return kov; }
	std::string getNev() const { return nev; }
	char getMn() const { return mn; }

	// Setter
	void setKov(Jatekos* const kov);

	// Kiiríja az aktuális játékos adatai
	void kiirat() const;

	// Fájlba kiírja az aktuális játékos adatait
	void serialize(std::ofstream& ofs);			

	// Növeli a nyertes játszmák darabszámát
	void incNyert();							

	// Növeli a döntetlen játszmák darabszámát
	void incDontetlen();						

	// Növeli a vesztes játszmák darabszámát
	void incVesztett();							

	// A játékos tippjét generálja le 
	virtual char tippel(const Statisztika& stat) const = 0 ;

	// Destruktor
	virtual ~Jatekos();
};
#endif
