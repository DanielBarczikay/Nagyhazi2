#include <time.h>
#include "memtrace.h"
#include "avatar4.h"

// Konstruktor
Avatar4::Avatar4() {
	nev = "Statisztikus Sandor";
	mn = 's';
}

// A játékos tippjét generálja le a saját algoritmusa alapján
// A statisztika szerint legtöbbet nyert tippre fogad
char Avatar4::tippel(const Statisztika& stat) const {
	return stat.legtobb_nyert();
}

