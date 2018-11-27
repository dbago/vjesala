#pragma once

#ifndef RIJECI
#define RIJECI

#include <iostream>
#include <string>

using namespace std;
const int brojRijeci = 25; //toliko rijeci u datoteci postoji

class rijeci
{
private:
	string ucitaneRijeci[brojRijeci];
	int redBr;
	string odabranaRijec;
	string skriveno;

public:
	rijeci();
	~rijeci();
	void getRijecIzD(); //iz datoteke cita rijeci i stavlja u niz stringova
	string odaberiRijec(); //vraca rijec koja se pogadja
	string sakrijRijec(string r); //slova zamjeni crtama
	string update(string r); //u slucaju pogotka zamjeni crtu odgovarajucim slovom
	bool crta(); //provjerava je li slovo skriveno
	string getOdabranuRijec();
	string getSkriveno();
};
#endif