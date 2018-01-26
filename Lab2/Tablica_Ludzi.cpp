#include "Tablica_Ludzi.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


Tablica_Ludzi::Tablica_Ludzi()
	: tablica(NULL)
	, dlugosc(0)
	, aktualne_wypelnienie(0)
{
}

Tablica_Ludzi::Tablica_Ludzi(long int dlugosc)
{
	tablica = new Pracownik[dlugosc];
}


Tablica_Ludzi::~Tablica_Ludzi()
{
	delete[] tablica;
}

Tablica_Ludzi::Tablica_Ludzi(const Tablica_Ludzi & wzorzec)
{
	cout << "Dziala konstruktor kopiujacy\n";
	tablica = wzorzec.tablica;
	dlugosc = wzorzec.dlugosc;
	aktualne_wypelnienie = wzorzec.aktualne_wypelnienie;
}

Tablica_Ludzi & Tablica_Ludzi::operator=(const Tablica_Ludzi & wzorzec)
{
	cout << "Dziala operator przypisania\n";
	if (this == &wzorzec) return *this;
	tablica = wzorzec.tablica;
	dlugosc = wzorzec.dlugosc;
	aktualne_wypelnienie = wzorzec.aktualne_wypelnienie;
	return *this;
}

void Tablica_Ludzi::wypelnij()
{
	tablica[aktualne_wypelnienie] = Pracownik();
	tablica[aktualne_wypelnienie].Wpisz();
	aktualne_wypelnienie++;
}

void Tablica_Ludzi::edytuj(int rekord)
{
	if (rekord > aktualne_wypelnienie)
	{
		cout << "Nie znaleziono elementu";
	}
	else
	{
		tablica[rekord] = Pracownik();
		tablica[rekord].Wpisz();
	}
}

int Tablica_Ludzi::szukaj(char imie[], char nazwisko[])
{
	for (int i = 0; i < aktualne_wypelnienie; i++)
	{
		if (tablica[i].SprawdzNazwisko(nazwisko)==1)
		{
			if (tablica[i].SprawdzImie(imie)==1)
				return i;
		}
		else return -1;
	}
}

void Tablica_Ludzi::wypisz_wszystko()
{
	for (int i = 0; i < aktualne_wypelnienie; i++)
	{
		tablica[i].Wypisz();
	}

}
