#pragma once
#include "Pracownik.h"



Pracownik::Pracownik(const char * imie, const char * nazwisko, int d, int m, int r)
{
	/*delete[] m_pszImie;
	delete[] m_pszNazwisko;*/
	m_pszImie = new char[strlen(imie)+1];
	m_pszNazwisko = new char[strlen(nazwisko)+1];
	Imie(imie);
	Nazwisko(nazwisko);
	DataUrodzenia(d, m, r);
}

Pracownik::Pracownik(const Pracownik & wzorzec)
{
	delete[] m_pszImie;
	delete[] m_pszNazwisko;
	m_pszImie = new char[strlen(wzorzec.m_pszImie) + 1];
	m_pszNazwisko = new char[strlen(wzorzec.m_pszNazwisko) + 1];
	strcpy(m_pszImie, wzorzec.m_pszImie);
	strcpy(m_pszNazwisko, wzorzec.m_pszNazwisko);
	m_DataUrodzenia = wzorzec.m_DataUrodzenia;
	//cout << "Dziala konstruktor kopiujacy\n";
}

Pracownik & Pracownik::operator=(const Pracownik & wzorzec)
{
	delete[] m_pszImie;
	delete[] m_pszNazwisko;
	m_pszImie = new char[strlen(wzorzec.m_pszImie)+1];
	m_pszNazwisko = new char[strlen(wzorzec.m_pszNazwisko)+1];
	strcpy(m_pszImie, wzorzec.m_pszImie);
	strcpy(m_pszNazwisko, wzorzec.m_pszNazwisko);
	m_DataUrodzenia = wzorzec.m_DataUrodzenia;
	
	return *this;
}

bool Pracownik::operator==(const Pracownik & wzorzec)
{
	//cout << "Dziala operator porownania\n";
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
	m_pszImie = new char[strlen(nowe_imie)+1];
	strcpy_s(m_pszImie, strlen(nowe_imie)+1, nowe_imie);

}


void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
	delete[] m_pszNazwisko;
	m_pszNazwisko = new char[strlen(nowe_nazwisko)+1];
	strcpy_s(m_pszNazwisko, strlen(nowe_nazwisko)+1, nowe_nazwisko);
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

ostream & operator<<(ostream & wy, const Pracownik & o)
{
	wy <<  o.m_pszImie << " " << o.m_pszNazwisko << " " << o.m_DataUrodzenia << endl;
	return wy;
}


istream & operator >> (istream & we, Pracownik & o)
{	
	//cout << "Nazwisko\n";
	we >> o.m_pszImie >> o.m_pszNazwisko >> o.m_DataUrodzenia;
	//cout << "Imie\n";
	//we >> o.m_pszImie;
	//cout << "Dzien urodzenia\n";
	//we >> o.m_DataUrodzenia;
	return we;
}