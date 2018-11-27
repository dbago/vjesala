#include "rijeci.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

rijeci::rijeci()
{
}

rijeci::~rijeci()
{
}

void rijeci::getRijecIzD()
{
	ifstream rjecnik;
	rjecnik.open("rijeci.txt");
	string rijec;
	if (rjecnik.is_open())
	{
		for (int i = 0; i < brojRijeci; i++)
		{
			getline(rjecnik, rijec);
			ucitaneRijeci[i] = rijec;
		}
		rjecnik.close();
	}
	else cout << "Nije uspjelo otvaranje datoteke!" << endl;
}

string rijeci::odaberiRijec()
{
	srand(time(NULL));
	redBr = rand()%25;
	odabranaRijec = ucitaneRijeci[redBr];
	return odabranaRijec;
}

string rijeci::sakrijRijec(string r)
{
	skriveno = r;
	for (int i = 0; i < r.size(); i++) {
		skriveno[i] = (r[i] != ' ') ? '-' : ' ';
	}
	return skriveno;
}

bool rijeci::crta()
{
	bool imaCrtu = false;
	for (int i = 0; i < skriveno.size(); i++)
	{
		if (skriveno[i] == '-')
		{
			imaCrtu = true;
			break;
		}
	}
	return imaCrtu;
}

string rijeci::update(string r)
{
	skriveno = r; 
	return skriveno;
}

string rijeci::getOdabranuRijec()
{
	return odabranaRijec;
}

string rijeci::getSkriveno()
{
	return skriveno;
}