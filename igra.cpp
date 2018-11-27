#include "igra.h"
#include "string.h"
#include <string>

using namespace std;

igra::igra()
{
	cout << "Nova runda:" << endl << endl << endl;
	porazi = 0; 
	pobjede = 0;
	c = new covjek;
	r = new rijeci;
}

igra::~igra()
{
	delete c;
	delete r;
}

void igra::play()
{	
	r->getRijecIzD();
	r->sakrijRijec(r->odaberiRijec());
	this->postaviSucelje();
	cout << endl;
	do {
		this->prvjeraUnosa(this->getUnos()); cout << endl << endl;
		this->postaviSucelje(); 
		cout << endl;
	} while (!this->krajIgre());
	this->ispisKonacnogRez(); 
}

void igra::postaviSucelje()
{
	cout << c->crtaj(c->getBrojPokusaja());
	cout << "RIJEC: " << r->getSkriveno() << endl << endl;
	
}

void igra::ispisKonacnogRez()
{
	if (c->getBrojPokusaja() > 0)
	{
		cout << endl << "Pobijedili ste!" << endl << endl;
		pobjede += 1;
	}
	else {
		cout << endl << "Izgubili ste!" << endl << endl;
		porazi += 1;
		cout << "Trazena rijec je: " << r->getOdabranuRijec();
		cout << endl;
	}
}

void igra::prvjeraUnosa(char unos)
{
	bool pronadjeno = false;
	string odabrana, skrivena;
	odabrana = r->getOdabranuRijec();
	skrivena = r->getSkriveno();
	for (int i = 0; i < odabrana.size(); i++)
	{
		if (tolower(odabrana[i]) == unos)
		{
			skrivena[i] = odabrana[i];
			pronadjeno = true;
		}
	}
	r->update(skrivena);
	if (!pronadjeno)
	{
		int noviBrojPokusaja = c->setBrojPokusaja();
		c->crtaj(noviBrojPokusaja);
	}
}

bool igra::ponovnoIgranje()
{
	string odgovor;
	cout << endl << endl << endl << "Zelite li novu rundu? ";
	cin >> odgovor;
		if (odgovor == "DA" || odgovor == "da" || odgovor == "Da" || odgovor == "dA")
		{
			return 1;
		}
		else {
			cout << endl;
			return 0;
		}
}

char igra::getUnos()
{
	string uSlucajuKU = "Krivi unos! Pokusajte ponovno.";
	string naredbaZaU = "Molimo unesite vase nagadjanje. \nU slucaju unosa vise slova prihvaca se prvo.   ";
	string unos;
	unos = igra::nagadjanje(naredbaZaU, uSlucajuKU);
	return unos[0];
}

string igra::nagadjanje(string pitanje, string error)
{
	string uTemp;
	bool kriviUnos;
	do {
		kriviUnos = false;
		cout << pitanje;
		cin >> uTemp;

		if (cin.fail()) //provjera jel pravi tip varijable
		{
			cout << error << endl;
			cin >> uTemp;
			kriviUnos = true;
		}
		else {
			for (int i = 0; i < uTemp.size(); i++)
			{
				if (isalpha(uTemp[i]))
				{
					uTemp[i] = tolower(uTemp[i]);
				}
				else {
					cout << error << endl;
					kriviUnos = true;
				}
			}
		}
	} while (kriviUnos);
	return uTemp;
}

bool igra::krajIgre()
{
	return c->getBrojPokusaja() == 0 || !r->crta();
}

void igra::getPobjedePorazi(int& x, int& y)
{
	x += pobjede;
	y += porazi;
}