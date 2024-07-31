#include <time.h>
#include "memtrace.h"
#include "avatar3.h"

// Konstruktor
Avatar3::Avatar3() {
	nev = "Azertse Aladar";
	mn = 'a';
}
// A játékos tippjét generálja le a saját algoritmusa alapján
// Az utolsó körben nyerõ tipp ellen fogad
char Avatar3::tippel(const Statisztika& stat) const{
	if (stat.getUtolso() == 'p') return 'o';
	else if (stat.getUtolso() == 'k') return 'p';
	else return 'k';
}

