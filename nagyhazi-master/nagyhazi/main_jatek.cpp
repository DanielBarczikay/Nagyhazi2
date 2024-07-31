#include <time.h>
#include <string>
#include <iostream>
#include "memtrace.h"
#include "gtest_lite.h"
#include "jatek.h"
#include "naplo.h"
#include "jatekosok.h"
#include "human.h"
#include "statisztika.h"

//#define CPORTA


int main() {

	// random sz�m gener�l�s ind�t�sa
	srand(time(0));

	// Alap objektumok inicializ�l�sa
	Jatekosok jatekos_lista;
	Naplo jatek_lista;
	Statisztika stat;

	std::cout << "Ko, papir, ollo jatek v2\n" << "=====================\n\n";

	//napl� beolvas�sa
	try {
		jatek_lista.deserialize(jatekos_lista, stat);
	}
	catch (const std::invalid_argument& e) {
		std::cout << "Sikertelen a naplo fajl beolvasasa!!!\n\n";
	}


#ifndef CPORTA
	// Konzole j�t�k �g

	std::cout << jatek_lista << stat;
	// F�men�
	char menu = ' ';
	while (menu != '4') {
		std::cout << jatekos_lista << "Fomenu\n" << "---------\n";
		std::cout << "1. Uj jatekos felvitele\n" << "2. Jatek inditasa\n";
		std::cout << "3. Statisztikak\n" << "4. Kilepes\n";
		std::cin >> menu;

		if (menu == '1') {
			std::string nev;
			char mn='k';
			std::cout << "Monogramm: \n";
			std::cin >> mn;
			std::cout << "Uj jatekos neve: \n";
			std::getline(std::cin >> std::ws, nev);
			jatekos_lista.ujJatekos(nev, mn);
		}
		else if (menu == '2') {
			Jatekos* jatekos1;
			Jatekos* jatekos2;
			Jatek* jatekom = new Jatek();
			jatek_lista.ujJatek(jatekom);
			jatekos1 = jatekos_lista.beker();
			jatekos2 = jatekos_lista.beker();
			jatekom->jatszik(stat, jatekos1, jatekos2, jatekos1->tippel(stat), jatekos2->tippel(stat));
		}
		else if (menu == '3') {
			std::cout << jatek_lista;
			std::cout << stat;
		}
	}

#else
	// Automata tesztel�si �g
	Jatekos* jatekos1;
	Jatekos* jatekos2;

	// �j j�t�kos felvitele
	TEST(Jatekos, Jatekos felvitele) {
		jatekos_lista.ujJatekos("Toth Tamas", 't');
		EXPECT_STREQ("Toth Tamas", jatekos_lista.keres('t')->getNev().c_str());       
	} END

	// Els� j�t�kmenet
	// Elv�rt inputok : t , k
	TEST(Jatek 1, Input tesztek) {
		Jatek* jatekom = new Jatek();
		jatek_lista.ujJatek(jatekom);
		jatekos1 = jatekos_lista.beker();
		EXPECT_STREQ("Toth Tamas", jatekos1->getNev().c_str());
		jatekos2 = jatekos_lista.keres('r');
		EXPECT_STREQ("Random Robert", jatekos2->getNev().c_str());
		jatekom->jatszik(stat, jatekos1, jatekos2, jatekos1->tippel(stat), jatekos2->tippel(stat));
	} END

	// M�sodik j�t�kmenet
	TEST(Jatek 2, Beepitett jatekosok tesztje) {
		//String a; createString(a);
		int okTipp = 0;
		Jatek* jatekom2 = new Jatek();
		jatek_lista.ujJatek(jatekom2);
		jatekos1 = jatekos_lista.keres('a');
		jatekos2 = jatekos_lista.keres('i');
		char tipp1 = jatekos1->tippel(stat);
		if (tipp1 == 'p' || tipp1 == 'k' || tipp1 == 'o') okTipp = 1;
		EXPECT_EQ(okTipp, 1);
		jatekom2->jatszik(stat, jatekos1, jatekos2, tipp1, jatekos2->tippel(stat));
	} END

	// Harmadik j�t�kmenet
	TEST(Jatek 3, Beepitett jatekosok tesztje) {
		//String a; createString(a);
		Jatek* jatekom3 = new Jatek();
		jatek_lista.ujJatek(jatekom3);
		jatekos1 = jatekos_lista.keres('i');
		jatekos2 = jatekos_lista.keres('a');
		jatekom3->jatszik(stat, jatekos1, jatekos2, jatekos1->tippel(stat), jatekos2->tippel(stat));
	} END

	// Negyedik j�t�kmenet
	TEST(Jatek 4, Beepitett jatekosok tesztje statisztik�k kiirat�sa) {
		//String a; createString(a);
		Jatek* jatekom4 = new Jatek();
		jatek_lista.ujJatek(jatekom4);
		jatekos1 = jatekos_lista.keres('a');
		jatekos2 = jatekos_lista.keres('s');
		jatekom4->jatszik(stat, jatekos1, jatekos2, jatekos1->tippel(stat), jatekos2->tippel(stat));
		std::cout << jatek_lista;
		std::cout << jatekos_lista;
		std::cout << stat;
	} END



#endif

	// J�t�knapl� ment�se f�jlba
	jatek_lista.serialize();

	return 0;
}