#include <time.h>
#include "memtrace.h"
#include "avatar2.h"

// Konstruktor
Avatar2::Avatar2() {
	nev = "Ismetlo Imre";
	mn = 'i';
}

// A j�t�kos tippj�t gener�lja le a saj�t algoritmusa alapj�n
// Az utols� k�rben nyer� tippet ism�tli
// ha az el�z� j�tszma d�ntetlen, akkor v�letlen tippet gener�l
char Avatar2::tippel(const Statisztika& stat) const{
	if (stat.getUtolso() == ' ') {
		int tmp_tipp = rand() % 3;
		if (tmp_tipp == 0) return 'k';
		else if (tmp_tipp == 1) return 'p';
		else return 'o';
	}
	return stat.getUtolso();
}
