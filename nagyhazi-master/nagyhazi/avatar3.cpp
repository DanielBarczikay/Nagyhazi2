#include <time.h>
#include "memtrace.h"
#include "avatar3.h"

// Konstruktor
Avatar3::Avatar3() {
	nev = "Azertse Aladar";
	mn = 'a';
}
// A j�t�kos tippj�t gener�lja le a saj�t algoritmusa alapj�n
// Az utols� k�rben nyer� tipp ellen fogad
char Avatar3::tippel(const Statisztika& stat) const{
	if (stat.getUtolso() == 'p') return 'o';
	else if (stat.getUtolso() == 'k') return 'p';
	else return 'k';
}

