#include <iostream>
#include "igra.h"

using namespace std;

int main()
{
	int poraziBrojac = 0;
	int pobjedeBrojac = 0;
	bool novo;
	igra *novaIgra;
	do {
		novaIgra = new igra;
		novaIgra->play();
		novaIgra->getPobjedePorazi(pobjedeBrojac, poraziBrojac); //vraca je li pobjeda ili poraz i sprema u brojace
		novo = novaIgra->ponovnoIgranje();
		delete novaIgra;
	} while (novo);
	cout << endl << "		Pobjede: " << pobjedeBrojac << endl << "		Porazi: " << poraziBrojac << endl << endl << endl;

	system("pause");

	return 0;
}