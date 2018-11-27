#pragma once

#ifndef IGRA
#define IGRA

#include <iostream>
#include <string>
#include "covjek.h"
#include "rijeci.h"

using namespace std;

class igra
{
public:
	covjek * c;
	rijeci * r;
	int porazi;
	int pobjede;
public:
	igra();
	~igra();
	void play();
	void postaviSucelje();
	void ispisKonacnogRez();
	void prvjeraUnosa(char unos);
	bool ponovnoIgranje();
	char getUnos();
	string nagadjanje(string, string);
	bool krajIgre();
	void getPobjedePorazi(int& x, int& y);
};
#endif
