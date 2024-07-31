#include <time.h>
#include "memtrace.h"
#include "avatar4.h"

// Konstruktor
Avatar4::Avatar4() {
	nev = "Statisztikus Sandor";
	mn = 's';
}

// A j�t�kos tippj�t gener�lja le a saj�t algoritmusa alapj�n
// A statisztika szerint legt�bbet nyert tippre fogad
char Avatar4::tippel(const Statisztika& stat) const {
	return stat.legtobb_nyert();
}

