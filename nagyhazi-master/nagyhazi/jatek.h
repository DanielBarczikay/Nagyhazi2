#ifndef JATEK_H
#define JATEK_H
#include "statisztika.h"
#include "jatekosok.h"
#include "jatekos.h"



class Jatek {
private:
	// Résztvevõ két játékos
	Jatekos* jatekos1;
	Jatekos* jatekos2;

	// Játékosok megtett tippjei: k - Kõ, p - papír, o - olló
	char tipp1;
	char tipp2;

	// Játékon belül melyik játékos nyert 0 - döntetlen, 1 - elsõ játékos nyert, 2 - második játékos nyert 
	int eredmeny;

	// Nyertes tipp
	char tipp_nyertes;

	// Láncolt listában a következõ játék
	Jatek* kov;


public:
	// Konstruktor
	Jatek() {}

	// Konstruktor fájlból betöltött játékállások létrehozásához
	Jatek(Jatekosok& lista, Statisztika& stat, const std::string& nev1, const std::string& nev2, const char& mn1, const char &mn2, const char& tipp1, const char& tipp2);

	// Getter
	Jatek* getKov() const { return kov; };

	// Setter
	void setKov(Jatek* const kov);

	// Játék futtatása
	void jatszik(Statisztika& stat, Jatekos* const jatekos1, Jatekos* const jatekos2, const char& tipp1, const char& tipp2);

	// Megadja hogy melyik játékos nyert
	void kiertekel(Statisztika& stat);

	// Kiiríja az aktuális játék ereményét
	void kiirat() const;						

	// Fájlba kiírja az aktuális játékos adatait
	void serialize(std::ofstream& ofs) const;	
};
#endif