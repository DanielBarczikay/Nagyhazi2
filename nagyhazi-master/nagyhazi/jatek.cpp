#include <iostream>
#include "memtrace.h"
#include "jatek.h"
#include "jatekosok.h"
#include "statisztika.h"

// Setter
void Jatek::setKov(Jatek* const kov_tmp) { kov = kov_tmp; }

// Konstruktor fájlból betöltött játékállások létrehozásához
Jatek::Jatek(Jatekosok& lista, Statisztika& stat, const std::string& nev1, const std::string& nev2, const char& mn1, const char& mn2, const char& tipp1, const char& tipp2) {
	kov = NULL;
	jatekos1 = lista.ujJatekos(nev1, mn1);
	jatekos2 = lista.ujJatekos(nev2, mn2);
	this->tipp1 = tipp1;
	this->tipp2 = tipp2;
	kiertekel(stat);
}

void Jatek::jatszik(Statisztika& stat,  Jatekos* const jatekos1,  Jatekos* const jatekos2, const char& tipp1, const char& tipp2) {
	this->jatekos1 = jatekos1;
	this->jatekos2 = jatekos2;
	this->tipp1 = tipp1;
	this->tipp2 = tipp2;
	kiertekel(stat);
	kiirat();
	std::cout << "\n";
}

// Adott játék kiértékelése a megtett tippek alapján
void Jatek::kiertekel(Statisztika& stat) {
	// Döntetlen
	if (tipp1 == tipp2) { 
		eredmeny = 0;
		jatekos1->incDontetlen();
		jatekos2->incDontetlen();
		tipp_nyertes = ' ';
	} 
	else if (tipp1 == 'k') {
		// 1.Jatekos nyert
		if (tipp2 == 'o')  
		{
			eredmeny = 1;
			tipp_nyertes = tipp1;
			jatekos1->incNyert();
			jatekos2->incVesztett();

		}
		// 2.Jatekos nyert
		else if (tipp2 == 'p') 
		{
			eredmeny = 2;
			tipp_nyertes = tipp2;
			jatekos2->incNyert();
			jatekos1->incVesztett();
		}
	}
	else if (tipp1 == 'p') {
		// 1.Jatekos nyert
		if (tipp2 == 'k') 
		{
			eredmeny = 1;
			tipp_nyertes = tipp1;
			jatekos1->incNyert();
			jatekos2->incVesztett();
		}
		// 2.Jatekos nyert
		else if (tipp2 == 'o') 
		{
			eredmeny = 2;
			tipp_nyertes = tipp2;
			jatekos2->incNyert();
			jatekos1->incVesztett();
		}
	}
	else if (tipp1 == 'o') {
		// 1.Jatekos nyert
		if (tipp2 == 'p') 
		{
			eredmeny = 1;
			tipp_nyertes = tipp1;
			jatekos1->incNyert();
			jatekos2->incVesztett();
		}
		// 2.Jatekos nyert
		else if (tipp2 == 'k')  
		{
			eredmeny = 2;
			tipp_nyertes = tipp2;
			jatekos2->incNyert();
			jatekos1->incVesztett();
		}
	}
	stat.frissit(tipp_nyertes);
}

// Kiiríja az aktuális játék ereményét
void Jatek::kiirat() const{
	if (eredmeny == 0) {
		std::cout << "Dontetlen             -  ";
	}
	else if (eredmeny == 1) {
		std::cout << "Elso jatekos nyert    -  ";
	}
	else
	{
		std::cout << "Masodik jatekos nyert -  ";
	}
	std::cout << "   ";
	std::cout << jatekos1->getNev();
	std::cout << ": ";
	std::cout << tipp1;
	std::cout << " , ";
	std::cout << jatekos2->getNev();
	std::cout << ": ";
	std::cout << tipp2;
	std::cout << "\n";
}

// Fájlba kiírja az aktuális játékos adatait
void Jatek::serialize(std::ofstream& ofs) const{
	// elsõ játékos adatainak kiírása (név, monogramm, típus, tipp)
	jatekos1->serialize(ofs);
	ofs.write(&tipp1, sizeof(tipp1));

	// második játékos adatainak kiírása (név, monogramm, típus, tipp)
	jatekos2->serialize(ofs);
	ofs.write(&tipp2, sizeof(tipp2));
}