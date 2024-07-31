#include <iostream>
#include "memtrace.h"
#include "statisztika.h"


// Statisztikai adatok friss�t�se aktu�lis nyert tipp alapj�n
void Statisztika::frissit(const char& tipp) {
	utolso_nyert = tipp;
	if (tipp == 'p') {
		papir_db++;
	}
	else if (tipp == 'o') {
		ollo_db++;
	}
	else if (tipp == 'k') {
		ko_db++;
	}
}

// Megadja melyik tipp nyert a legt�bbsz�r
char Statisztika::legtobb_nyert() const {
	char tipp;
	if ((ko_db >= papir_db) && (ko_db >= ollo_db)) tipp = 'k';
	else if ((papir_db >= ko_db) && (papir_db >= ollo_db)) tipp = 'p';
	else tipp = 'o';
	return tipp;
}

// Ki�r� oper�tor
std::ostream& operator<<(std::ostream& os, Statisztika& stat) {
	os << "Statisztika\n";
	os << "-----------\n";
	os << "Papir:" << stat.getPapir() << " Ko:" << stat.getKo() << " Ollo:" << stat.getOllo() << " Utolo nyertes tipp: " << stat.getUtolso() << "\n\n";
	return os;
}
