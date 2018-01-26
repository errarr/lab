#pragma once
#pragma once
class Data
{
public:
	Data();
	~Data();
	Data(const Data &wzorzec);
	Data & operator=(const Data & wzorzec);
	bool operator==(const Data & wzorzec);
private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;
public:
	void Ustaw(int d, int m, int r);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Wypisz() const;
	void Wpisz();
	void Koryguj();
	bool Porownaj(Data &wzor) const;
};