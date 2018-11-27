#include "covjek.h"
#include <iostream>
#include <string>

using namespace std;

covjek::covjek()
{
	brojPokusaja = 6;
}


covjek::~covjek()
{
}

int covjek::getBrojPokusaja()
{
	return brojPokusaja;
}

int covjek::setBrojPokusaja()
{
	return brojPokusaja -= 1;
}

string covjek::crtaj(int pokusaji) //pokusaji - o tom broju ovisi koliko je nacrtano
{
	string izgl;
	switch (pokusaji)
	{
	case 0: { //cijeli covjek, izgubljena igra
		izgl = " +---+\n";
		izgl += " |   |\n";
		izgl += " |   o\n";
		izgl += " |  /|\\\n";
		izgl += " |  / \\\n";
		izgl += " |\n";
		izgl += "-+-\n\n";
	}
	break;
	case 1: {
		izgl = " +---+\n";
		izgl += " |   |\n";
		izgl += " |   o\n";
		izgl += " |  /|\\\n";
		izgl += " |  /\n";
		izgl += " |\n";
		izgl += "-+-\n\n";
	}
			break;
	case 2: {
		izgl = " +---+\n";
		izgl += " |   |\n";
		izgl += " |   o\n";
		izgl += " |  /|\\\n";
		izgl += " |\n";
		izgl += " |\n";
		izgl += "-+-\n\n";
	}
	break;
	case 3: {
		izgl = " +---+\n";
		izgl += " |   |\n";
		izgl += " |   o\n";
		izgl += " |  /|\n";
		izgl += " |\n";
		izgl += " |\n";
		izgl += "-+-\n\n";
	}
			break;
	case 4: {
		izgl = " +---+\n";
		izgl += " |   |\n";
		izgl += " |   o\n";
		izgl += " |   |\n";
		izgl += " |\n";
		izgl += " |\n";
		izgl += "-+-\n\n";
	}
	break;
	case 5: {
		izgl = " +---+\n";
		izgl += " |   |\n";
		izgl += " |   o\n";
		izgl += " |\n";
		izgl += " |\n";
		izgl += " |\n";
		izgl += "-+-\n\n";
	}
	break;
	case 6: {	
		izgl = " +---+\n";
		izgl += " |   |\n";
		izgl += " |\n";
		izgl += " |\n";
		izgl += " |\n";
		izgl += " |\n";
		izgl += "-+-\n\n";
	}
	break;
	}
	return izgl;
}