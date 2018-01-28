#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <stdio.h>
using namespace std;

class Data
{
public:
	Data();
	~Data();
	Data(const Data &wzorzec);
	Data & operator=(const Data & wzorzec);
	bool operator==(const Data & wzorzec);
	void Ustaw(int d, int m, int r);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Wypisz() const;
	void Wpisz();
	void Koryguj();
	bool Porownaj(Data &wzor) const;
	friend ostream & operator << (ostream &wy, const Data &d);
	friend istream & operator >> (istream &we, Data &d);
private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;
};