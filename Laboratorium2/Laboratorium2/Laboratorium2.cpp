#include <iostream>
#include "CTable.h"
#include "constans.h"

using namespace std;

void v_mod_tab(CTable* pcTab, int iNewSize);
void v_mod_tab(CTable cTab, int iNewSize);

int main()
{
	CTable c_tab_0, c_tab_1, c_tab_2;
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);
	c_tab_0.vSetValueAt(0, 1);
	c_tab_0.vSetValueAt(1, 2);
	c_tab_0.vSetValueAt(2, 3);
	c_tab_0.vSetValueAt(3, 4);
	c_tab_0.vSetValueAt(4, 5);
	c_tab_0.vSetValueAt(5, 6);

	c_tab_1.vSetValueAt(0, 7);
	c_tab_1.vSetValueAt(1, 8);
	c_tab_1.vSetValueAt(2, 123);
	c_tab_1.vSetValueAt(3, 10);

	c_tab_1.vSetValueAt(2, 9);

	c_tab_0.vPrint();
	c_tab_1.vPrint();

	c_tab_2 = c_tab_0 + c_tab_1;
	c_tab_2.vPrint();

	c_tab_2 / 2;
	c_tab_2.vPrint();

	CTable c_tab_3;
	c_tab_3 = c_tab_2 * 2;
	c_tab_3.vPrint();

	/*
	CTable c_tab_3;
	c_tab_3 = c_tab_0 - c_tab_1;
	c_tab_3.vPrint();
	*/
	/*
	CTable bezparametr;
	CTable c_tab("tab1", 10);
	CTable* pc_new_tab;
	pc_new_tab = c_tab.pcClone();
	c_tab.vSetName("tab2");
	c_tab.bSetNewSize(25);
	v_mod_tab(c_tab, 10);
	c_tab.info();
	v_mod_tab(&c_tab, 12);
	c_tab.info();
	*/
}

void v_mod_tab(CTable* pcTab, int iNewSize)
{
	if (iNewSize < UNCORRECT_DIMENSION)
		cout << ERROR << endl;
	else
		pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize)
{
	if (iNewSize < UNCORRECT_DIMENSION)
		cout << ERROR << endl;
	else
		cTab.bSetNewSize(iNewSize);
}

/*
zad1:
Program wywoluje error, poniewaz pamiec zarezerowana dla obiektu c_tab_0 zostaje wspoldzielona z pamiecia obiektu c_tab_1(przez 4 linijke
polecenia, czyli przypisanie c_tab_0=c_tab_1 , program dziala do momentu wywolania desturktora (pierwszy obiekt usuwa sie prawidlowo,
jednak gry destruktor chce usunac drugi obiekt to widzi pusty
obszar zarezerwowanej pamieci
*/

/*
zad2:
po usunieciu destruktora program konczy sie bez wywolania bledu, poniewaz ta sama pamiec nie jest dwukrotnie czyszczona (wlasciwie to w ogole
nie jest czyszczona)
*/

/*
zad 3:
pokazala sie 2 razy ta sama tablica, poniewaz w momencie przypisania c_tab_0 = c_tab_1 pamiec zostaje wspoldzielona i dwa obiekty (c_tab_0
i c_tab_1) mówią o tym samym obszarze pamięci
*/