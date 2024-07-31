#include <iostream>
#include "memtrace.h"
#include "human.h"


// Konstruktor, megkapja a j�t�kos nev�g �s monogrammj�t
Human::Human(std::string nev, char mn) {
	this->nev = nev;
	this->mn = mn;
	this->kov = NULL;
}

// A j�t�kos tippj�t gener�lja le a saj�t algoritmusa alapj�n
// Ember j�t�kos eset�n bek�rj�k a tippj�t a standard inputr�l
char Human::tippel(const Statisztika& stat) const {
	char tipp = ' ';
	while (tipp != 'k' && tipp != 'p' && tipp != 'o') {
		std::cout << "Kerlek add meg " << nev << " tippjet! (k / p / o)";
		std::cin >> tipp;
	}
	std::cout << "\n";
	return tipp;
}