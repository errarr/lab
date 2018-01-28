#include "Data.h"
#include "Pracownik.h"
#include "Tablica_Ludzi.h"



void main()
{
	/*char i[25], n[30];
	int d, m, r;
	Data wzor;
	Pracownik pracownik;
	cout << "Czesc! Stworzmy pracownika. Podaj jego dane.\n" << endl;
	pracownik.Wpisz();
	cout << "Utworzono pracownika! \nJego dane to:\n ";
	pracownik.Wypisz();
	cout << "\n\nPodaj imie do sprawdzenia: ";
	cin >> i;
	cout << "Podaj nazwisko do sprawdzenia: ";
	cin >> n;
	cout << "Podaj date urodzenia do sprawdzenia. \nDzien: ";
	cin >> d;
	cout << "Miesiac: ";
	cin >> m;
	cout << "Rok: ";
	cin >> r;
	wzor.Ustaw(d, m, r);
	int spImie, spNazw, spData;
	spImie = pracownik.SprawdzImie(i);
	spNazw = pracownik.SprawdzNazwisko(n);
	spData = wzor.Porownaj(pracownik.ZwrocDate());
	if (spImie == 1)
	{
		if (spNazw == 1)
		{
			if (spData)
			{
				cout << "\nWszystkie dane sie zgadzaja!";
			}
			else
			{
				cout << "\nData urodzenia sie nie zgadza!";
			}
		}
		else
		{
			if (spData)
			{
				cout << "\nNazwisko sie nie zgadza!";
			}
			else
			{
				cout << "\nTylko imie sie zgadza!";
			}
		}
	}
	else
	{
		if (spNazw == 1)
		{
			if (spData == 1)
			{
				cout << "\nImie sie nie zgadza";
			}
			else
			{
				cout << "\nTylko nazwisko sie zgadza";
			}
		}
		else
		{
			if (spData == 1)
			{
				cout << "\nTylko data urodzenia sie zgadza";
			}
			else
			{
				cout << "\nWszystkie dane sa niezgodne";
			}
		}
	}
	*/
	/*int edytuj;
	char imie[25], nazwisko[30];
	
	Tablica_Ludzi tablica(10);
	cout << "Dodaj 1 pracownika\n";
	tablica.wypelnij();
	cout << "Dodaj 2 pracownika\n";
	tablica.wypelnij();
	cout << "Dodaj 3 pracownika\n";
	tablica.wypelnij();
	cout << "Ktory element chcesz edytowac?";
	cin >> edytuj;
	tablica.edytuj(edytuj);
	cout << "Podaj dane szukanego pracownika.\nImie: ";
	cin >> imie;
	cout << "Nazwisko: ";
	cin >> nazwisko;
	cout << "Pracownik nr " << tablica.szukaj(imie, nazwisko) << "(" << tablica.szukaj(imie, nazwisko)+1 << ")\n";
	tablica.wypisz_wszystko();
		
		
	cin >> edytuj;*/

	/*Data data, data2;
	data.Wpisz();
	data2.Wpisz();
	Data data3(data);
	data.Wypisz();
	data2.Wypisz();
	data3.Wypisz();
	if (data == data3) cout << "data = data3\n";
	else cout << "data != data3\n";
	data3 = data2;
	data3.Wypisz();
	if (data3 == data2) cout << "data= data2\n";
	else cout << "data != data2\n";
	if (data == data3) cout << "data = data3\n";
	else cout << "data != data3\n";*/

	Pracownik pracownik, pracownik2;
	
	pracownik.Wpisz();
	pracownik2.Wpisz();
	Pracownik pracownik3(pracownik);
	pracownik.Wypisz();
	pracownik2.Wypisz();
	pracownik3.Wypisz();
	if (pracownik == pracownik3) cout << "pracownik = pracownik3\n";
	else cout << "pracownik != pracownik3\n";
	pracownik3 = pracownik2;
	pracownik3.Wypisz();
	if (pracownik3 == pracownik2) cout << "pracownik= pracownik2\n";
	else cout << "pracownik != pracownik2\n";
	if (pracownik == pracownik3) cout << "data = pracownik3\n";
	else cout << "pracownik != pracownik3\n";


	Tablica_Ludzi tablica_ludzi = Tablica_Ludzi(10), tablica_ludzi2 = Tablica_Ludzi(10);

	tablica_ludzi.wypelnij();
	tablica_ludzi2.wypelnij();
	Tablica_Ludzi tablica_ludzi3(tablica_ludzi);
	tablica_ludzi.wypisz_wszystko();
	tablica_ludzi2.wypisz_wszystko();
	tablica_ludzi3.wypisz_wszystko();
	tablica_ludzi3 = tablica_ludzi2;
	tablica_ludzi3.wypisz_wszystko();

}