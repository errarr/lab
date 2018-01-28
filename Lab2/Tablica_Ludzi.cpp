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
	tablica = new Pracownik[dlugosc];
}


Tablica_Ludzi::~Tablica_Ludzi()
{
	delete[] tablica;
}

Tablica_Ludzi::Tablica_Ludzi(const Tablica_Ludzi & wzorzec)
{
	
	tablica = wzorzec.tablica;
	dlugosc = wzorzec.dlugosc;
	aktualne_wypelnienie = wzorzec.aktualne_wypelnienie;
	cout << "Dziala konstruktor kopiujacy\n";
}

Tablica_Ludzi & Tablica_Ludzi::operator=(const Tablica_Ludzi & wzorzec)
{
	
	if (this == &wzorzec) return *this;
	tablica = wzorzec.tablica;
	dlugosc = wzorzec.dlugosc;
	aktualne_wypelnienie = wzorzec.aktualne_wypelnienie;
	cout << "Dziala operator przypisania\n";
	return *this;
}

void Tablica_Ludzi::wypelnij()
{
	if (aktualne_wypelnienie < dlugosc)
	{
	
	tablica[aktualne_wypelnienie] = Pracownik();
	tablica[aktualne_wypelnienie].Wpisz();
	aktualne_wypelnienie++;
}
	else
	{
		cout << "Tablica jest pelna";
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
		wy << temp.m_pszImie;
		wy << temp.m_pszNazwisko;
		wy << temp.m_DataUrodzenia;
	}
	return wy;
}

istream & operator >> (istream & we, Tablica_Ludzi & t)
{
	int i = t.aktualne_wypelnienie;
	{
		for (t.aktualne_wypelnienie; t.aktualne_wypelnienie < t.dlugosc; t.aktualne_wypelnienie++)
		{
			Pracownik temp;
			cout << "Podaj imie: ";
			we >> temp.m_pszImie;
			cout << "Podaj nazwisko: ";
			we >> temp.m_pszNazwisko;
			cout << "Podaj dzien, miesiac, rok :";
			we >> temp.m_DataUrodzenia;
			if ((bool)we == 1)
			{
				t.tablica[i] = temp;
			}
		}
	}
	
}


