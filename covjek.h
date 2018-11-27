#pragma once

#ifndef VJESALO
#define VJESALO

#include <iostream>
#include <string>

using namespace std;

class covjek
{
private:
	int brojPokusaja;
public:
	covjek();
	~covjek();
	int getBrojPokusaja ();
	int setBrojPokusaja ();
	string crtaj (int pokusaji);
};
#endif