#pragma once
#include "Pracownik.h"
class Tablica_Ludzi
{
public:
	Tablica_Ludzi();
	Tablica_Ludzi(long int dlugosc = 0);
	~Tablica_Ludzi();
	Tablica_Ludzi(const Tablica_Ludzi &wzorzec);
	Tablica_Ludzi & operator=(const Tablica_Ludzi & wzorzec);
	void wypelnij();
	void edytuj(int rekord);
	int szukaj(char imie[], char nazwisko[]);
	void wypisz_wszystko();
private:
	Pracownik *tablica;
	long int dlugosc;
	int aktualne_wypelnienie;
};

