#include <iostream>
#include "memtrace.h"
#include "jatek.h"
#include "jatekosok.h"
#include "statisztika.h"

// Setter
void Jatek::setKov(Jatek* const kov_tmp) { kov = kov_tmp; }

// Konstruktor f�jlb�l bet�lt�tt j�t�k�ll�sok l�trehoz�s�hoz
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

// Adott j�t�k ki�rt�kel�se a megtett tippek alapj�n
void Jatek::kiertekel(Statisztika& stat) {
	// D�ntetlen
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

// Kiir�ja az aktu�lis j�t�k erem�ny�t
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

// F�jlba ki�rja az aktu�lis j�t�kos adatait
void Jatek::serialize(std::ofstream& ofs) const{
	// els� j�t�kos adatainak ki�r�sa (n�v, monogramm, t�pus, tipp)
	jatekos1->serialize(ofs);
	ofs.write(&tipp1, sizeof(tipp1));

	// m�sodik j�t�kos adatainak ki�r�sa (n�v, monogramm, t�pus, tipp)
	jatekos2->serialize(ofs);
	ofs.write(&tipp2, sizeof(tipp2));
}