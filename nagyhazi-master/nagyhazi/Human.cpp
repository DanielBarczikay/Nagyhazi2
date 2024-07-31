#include <iostream>
#include "memtrace.h"
#include "human.h"


// Konstruktor, megkapja a játékos nevég és monogrammját
Human::Human(std::string nev, char mn) {
	this->nev = nev;
	this->mn = mn;
	this->kov = NULL;
}

// A játékos tippjét generálja le a saját algoritmusa alapján
// Ember játékos esetén bekérjük a tippjét a standard inputról
char Human::tippel(const Statisztika& stat) const {
	char tipp = ' ';
	while (tipp != 'k' && tipp != 'p' && tipp != 'o') {
		std::cout << "Kerlek add meg " << nev << " tippjet! (k / p / o)";
		std::cin >> tipp;
	}
	std::cout << "\n";
	return tipp;
}