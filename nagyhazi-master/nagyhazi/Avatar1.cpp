#include <iostream>
#include <time.h>
#include "memtrace.h"
#include "avatar1.h"

// Konstruktor
Avatar1::Avatar1() {
	nev="Random Robert";
	mn = 'r';
}

// A j�t�kos tippj�t gener�lja le a saj�t algoritmusa alapj�n
// A j�t�kos algoritmusa a v�letlen tipp gener�l�s
char Avatar1::tippel(const Statisztika& stat) const{
	int tmp_tipp = rand() % 3;
	if (tmp_tipp == 0) return 'k';
	else if (tmp_tipp == 1) return 'p';
	else return 'o';
}
