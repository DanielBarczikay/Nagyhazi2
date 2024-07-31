#ifndef JATEKOS_H
#define JATEKOS_H
#include <fstream>
#include <string>
#include "statisztika.h"


// J�t�kos �soszt�ly
// Ebb�l fognak lesz�rmazni a k�l�nb�z� algoritmusokkal j�tsz� g�pi j�t�kosok �s az emberi j�t�kosok
class Jatekos {
protected:
	std::string nev;			// J�t�kos neve
	char mn;			// J�t�kos monogrammja
	Jatekos* kov;		// Mutat� a l�ncolt list�ba f�z�tt j�t�kosokr�l
	int nyert_db;		// J�t�kos �ltal nyert j�t�kok sz�ma
	int dontetlen_db;	// J�t�kos �ltal d�ntetlen j�t�kainak sz�ma
	int vesztett_db;	// J�t�kos vesztett j�t�kainak sz�ma

public:
	// Konstruktor
	Jatekos(): mn(' '), kov(NULL), nyert_db(0), dontetlen_db(0), vesztett_db(0) {}

	// Getter
	Jatekos* getKov() const { return kov; }
	std::string getNev() const { return nev; }
	char getMn() const { return mn; }

	// Setter
	void setKov(Jatekos* const kov);

	// Kiir�ja az aktu�lis j�t�kos adatai
	void kiirat() const;

	// F�jlba ki�rja az aktu�lis j�t�kos adatait
	void serialize(std::ofstream& ofs);			

	// N�veli a nyertes j�tszm�k darabsz�m�t
	void incNyert();							

	// N�veli a d�ntetlen j�tszm�k darabsz�m�t
	void incDontetlen();						

	// N�veli a vesztes j�tszm�k darabsz�m�t
	void incVesztett();							

	// A j�t�kos tippj�t gener�lja le 
	virtual char tippel(const Statisztika& stat) const = 0 ;

	// Destruktor
	virtual ~Jatekos();
};
#endif
