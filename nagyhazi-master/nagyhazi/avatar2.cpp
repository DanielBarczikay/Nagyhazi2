#include <time.h>
#include "memtrace.h"
#include "avatar2.h"

// Konstruktor
Avatar2::Avatar2() {
	nev = "Ismetlo Imre";
	mn = 'i';
}

// A játékos tippjét generálja le a saját algoritmusa alapján
// Az utolsó körben nyerõ tippet ismétli
// ha az elõzõ játszma döntetlen, akkor véletlen tippet generál
char Avatar2::tippel(const Statisztika& stat) const{
	if (stat.getUtolso() == ' ') {
		int tmp_tipp = rand() % 3;
		if (tmp_tipp == 0) return 'k';
		else if (tmp_tipp == 1) return 'p';
		else return 'o';
	}
	return stat.getUtolso();
}
