#pragma once
#include "Data.h"



Data::Data()
	: m_nDzien(0)
	, m_nMiesiac(0)
	, m_nRok(0)
{
}

Data::Data(const Data & wzorzec)
{
	
	m_nDzien = wzorzec.m_nDzien;
	m_nMiesiac = wzorzec.m_nMiesiac;
	m_nRok = wzorzec.m_nRok;
	cout << "Dziala konstruktor kopiujacy\n";
}


Data::~Data()
{
}

Data & Data::operator= (const Data & wzorzec)
{
	
	if (this == &wzorzec) return *this;
	m_nDzien = wzorzec.m_nDzien;
	m_nMiesiac = wzorzec.m_nMiesiac;
	m_nRok = wzorzec.m_nRok;
	cout << "Dziala operator przypisania\n";
	return *this;
}

bool Data::operator== (const Data & wzorzec)
{
	cout << "Dziala operator porownania\n";
	return (m_nDzien == wzorzec.m_nDzien && m_nMiesiac == wzorzec.m_nMiesiac && m_nRok == wzorzec.m_nRok);
}

void Data::Ustaw(int d, int m, int r)
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
	Koryguj();
}


int Data::Dzien() const
{
	return m_nDzien;
}


int Data::Miesiac() const
{
	return m_nMiesiac;
}


int Data::Rok() const
{
	return m_nRok;
}


void Data::Wypisz() const
{
	cout << m_nDzien << "-" << m_nMiesiac << "-" << m_nRok << "\n";
}


void Data::Wpisz()
{
	int d, m, r;
	cout << "Podaj dzien: ";
	cin >> d;
	cout << "Podaj miesiac: ";
	cin >> m;
	cout << "Podaj rok: ";
	cin >> r;
	Ustaw(d, m, r);
}


void Data::Koryguj()
{
	if (m_nDzien < 1)
		m_nDzien = 1;
	if (m_nMiesiac < 1)
		m_nMiesiac = 1;
	if (m_nMiesiac > 12)
		m_nMiesiac = 12;
	if (m_nRok < 1)
		m_nRok = 1;
	if (m_nMiesiac == 2)
	{
		if (((m_nRok % 4) == 0) && (((m_nRok % 100) != 0) || ((m_nRok % 400) == 0)))
		{
			if (m_nDzien > 29)
				m_nDzien = 29;
		}
		else

		{
			if (m_nDzien > 28)
				m_nDzien = 28;
		}
	}
	else if (m_nMiesiac == 1 || m_nMiesiac == 3 || m_nMiesiac == 5 || m_nMiesiac == 7 || m_nMiesiac == 8 || m_nMiesiac == 10 || m_nMiesiac == 12)
	{
		if (m_nDzien > 31)
			m_nDzien = 31;
	}
	else
	{
		if (m_nDzien > 30)
			m_nDzien = 30;
	}
}


bool Data::Porownaj(Data &wzor) const
{
	if (this == &wzor) return true;
	if (m_nDzien == wzor.Dzien() && m_nMiesiac == wzor.Miesiac() && m_nRok == wzor.Rok())
		return true;
	else
		return false;
}

ostream & operator << (ostream &wy, const Data &d) 
{
	return wy << d.m_nDzien << "-" << d.m_nMiesiac << "-" << d.m_nRok << endl;
}
istream & operator >> (istream &we, Data &d) 
{
	cout << "Podaj dzien\n";
	we >> d.m_nDzien;
	cout << "Podaj miesiac\n";
	we >> d.m_nMiesiac;
	cout << "Podaj rok\n";
	we >> d.m_nRok;
	d.Koryguj();
	return we;
}