#ifndef JATEK_H
#define JATEK_H
#include "statisztika.h"
#include "jatekosok.h"
#include "jatekos.h"



class Jatek {
private:
	// R�sztvev� k�t j�t�kos
	Jatekos* jatekos1;
	Jatekos* jatekos2;

	// J�t�kosok megtett tippjei: k - K�, p - pap�r, o - oll�
	char tipp1;
	char tipp2;

	// J�t�kon bel�l melyik j�t�kos nyert 0 - d�ntetlen, 1 - els� j�t�kos nyert, 2 - m�sodik j�t�kos nyert 
	int eredmeny;

	// Nyertes tipp
	char tipp_nyertes;

	// L�ncolt list�ban a k�vetkez� j�t�k
	Jatek* kov;


public:
	// Konstruktor
	Jatek() {}

	// Konstruktor f�jlb�l bet�lt�tt j�t�k�ll�sok l�trehoz�s�hoz
	Jatek(Jatekosok& lista, Statisztika& stat, const std::string& nev1, const std::string& nev2, const char& mn1, const char &mn2, const char& tipp1, const char& tipp2);

	// Getter
	Jatek* getKov() const { return kov; };

	// Setter
	void setKov(Jatek* const kov);

	// J�t�k futtat�sa
	void jatszik(Statisztika& stat, Jatekos* const jatekos1, Jatekos* const jatekos2, const char& tipp1, const char& tipp2);

	// Megadja hogy melyik j�t�kos nyert
	void kiertekel(Statisztika& stat);

	// Kiir�ja az aktu�lis j�t�k erem�ny�t
	void kiirat() const;						

	// F�jlba ki�rja az aktu�lis j�t�kos adatait
	void serialize(std::ofstream& ofs) const;	
};
#endif