#pragma once
#include "Tablica_Ludzi.h"



Tablica_Ludzi::Tablica_Ludzi()
	: tablica(NULL)
	, dlugosc(0)
	, aktualne_wypelnienie(0)
{
}

Tablica_Ludzi::Tablica_Ludzi(long int dlugosc)
{
	this->dlugosc = dlugosc;
	aktualne_wypelnienie = 0;
	tablica = new Pracownik[dlugosc];
}


Tablica_Ludzi::~Tablica_Ludzi()
{
	delete[] tablica;
}

Tablica_Ludzi::Tablica_Ludzi(const Tablica_Ludzi & wzorzec)
{
	
	aktualne_wypelnienie = wzorzec.aktualne_wypelnienie;
	dlugosc = wzorzec.dlugosc;
	for (int i = 0; i <= wzorzec.dlugosc; i++)
	{
		tablica[i] = wzorzec.tablica[i];
	}
}

Tablica_Ludzi & Tablica_Ludzi::operator=(const Tablica_Ludzi & wzorzec)
{
	
	if (dlugosc < wzorzec.aktualne_wypelnienie)
	{
		
		cout << "Zbyt dluga tablica";
	}
	else
	{
		aktualne_wypelnienie = wzorzec.aktualne_wypelnienie;
		for (int i = 0; i <= aktualne_wypelnienie; i++)
		{
			tablica[i] = wzorzec.tablica[i];
		}
	}
	return *this;
}

void Tablica_Ludzi::wypelnij()
{
	if (aktualne_wypelnienie < dlugosc)
	{
		tablica[aktualne_wypelnienie] = Pracownik();
		tablica[aktualne_wypelnienie].Wpisz();
		aktualne_wypelnienie++;
		return;
	}
	else
	{
		cout << "Tablica jest pelna";
		return;
	}
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

ostream & operator << (ostream & wy, const Tablica_Ludzi & t)
{
	for (int i = 0; i < t.aktualne_wypelnienie; i++)
	{
		Pracownik temp = t.tablica[i];
		wy << temp;
	}
	return wy;
}

istream & operator >> (istream & we, Tablica_Ludzi & t)
{
	Pracownik temp;
	t.aktualne_wypelnienie = 0;
	while (t.aktualne_wypelnienie < t.dlugosc && we >> temp)
	{
		t.tablica[t.aktualne_wypelnienie++] = temp;
	}
	return we;
}


