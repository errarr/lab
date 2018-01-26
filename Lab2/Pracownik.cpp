#include "Pracownik.h"
#include <string.h>
#include <cstring>
#include <iostream>
using namespace std;


Pracownik::Pracownik(const char * imie, const char * nazwisko, int d, int m, int r)
{
	m_pszImie = new char[sizeof(imie)];
	m_pszNazwisko = new char[sizeof(nazwisko)];
	Imie(imie);
	Nazwisko(nazwisko);
	DataUrodzenia(d, m, r);
}

Pracownik::Pracownik(const Pracownik & wzorzec)
{
	cout << "Dziala konstruktor kopiujacy\n";
	strcpy_s(m_pszImie, sizeof(wzorzec.m_pszImie), wzorzec.m_pszImie);
	strcpy_s(m_pszNazwisko, sizeof(wzorzec.m_pszNazwisko), wzorzec.m_pszNazwisko);
	m_DataUrodzenia = wzorzec.m_DataUrodzenia;
}

Pracownik & Pracownik::operator=(const Pracownik & wzorzec)
{
	cout << "Dziala operator przypisania\n";
	if (this == &wzorzec) return *this;
	m_pszImie = new char[strlen(wzorzec.m_pszImie) + 1]; 
	m_pszNazwisko = new char[strlen(wzorzec.m_pszNazwisko) + 1];
	strcpy_s(m_pszImie, sizeof(wzorzec.m_pszImie), wzorzec.m_pszImie);
	strcpy_s(m_pszNazwisko, sizeof(wzorzec.m_pszNazwisko), wzorzec.m_pszNazwisko);
	m_DataUrodzenia = wzorzec.m_DataUrodzenia;

}

bool Pracownik::operator==(const Pracownik & wzorzec)
{
	cout << "Dziala operator porownania\n";
	return (strcmp(m_pszImie, wzorzec.m_pszImie) && strcmp(m_pszNazwisko, wzorzec.m_pszNazwisko) && m_DataUrodzenia == wzorzec.m_DataUrodzenia);
}


Pracownik::~Pracownik()
{
	delete[] m_pszImie;
	delete[] m_pszNazwisko;
}


const char* Pracownik::Imie() const
{
	return m_pszImie;
}


const char* Pracownik::Nazwisko() const
{
	return m_pszNazwisko;
}



void Pracownik::Imie(const char* nowe_imie)
{
	delete[] m_pszImie;
	m_pszImie = new char[sizeof(nowe_imie)];
	strcpy_s(m_pszImie, sizeof(nowe_imie), nowe_imie);
}


void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
	delete[] m_pszNazwisko;
	m_pszNazwisko = new char[sizeof(nowe_nazwisko)];
	strcpy_s(m_pszNazwisko, sizeof(nowe_nazwisko), nowe_nazwisko);
}


void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}


void Pracownik::Wypisz() const
{
	cout << m_pszImie << "\t " << m_pszNazwisko << "\t";
	m_DataUrodzenia.Wypisz();

}


void Pracownik::Wpisz()
{
	char i[25], n[30];
	cout << "Podaj imie: ";
	cin >> i;
	cout << "Podaj nazwisko: ";
	cin >> n;
	Imie(i);
	Nazwisko(n);
	m_DataUrodzenia.Wpisz();
}


bool Pracownik::SprawdzImie(const char* por_imie) const
{

	if (strcmp(m_pszImie, por_imie) == 0)
		return 1;
	else
		return 0;
}


bool Pracownik::SprawdzNazwisko(const char* por_nazwisko) const
{
	if (strcmp(m_pszNazwisko, por_nazwisko) == 0)
		return 1;
	else
		return 0;
}





Data Pracownik::ZwrocDate() const
{
	return m_DataUrodzenia;
}
