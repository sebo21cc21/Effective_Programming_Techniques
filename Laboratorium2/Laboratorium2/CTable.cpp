#include <iostream>
#include "CTable.h"
#include "constans.h"
#include <cmath>
using namespace std;

CTable::CTable()
{
	s_name = DEFAULT_VALUE_STRING;
	cout << BEZP << s_name << endl;
	tabSize = DEFAULT_VALUE_INT;
	cout << LENGTH << tabSize << endl;
	tab = new int[tabSize];
}

CTable::CTable(string sName, int iTableLen)
{
	s_name = sName;
	cout << PAR << s_name << endl;
	tabSize = iTableLen;
	cout << LENGTH << tabSize << endl;
	tab = new int[iTableLen];
}

CTable::CTable(CTable& pcOther)
{
	tabSize = pcOther.tabSize;
	s_name = pcOther.s_name + COPY_;
	if (tabSize > UNCORRECT_DIMENSION)
	{
		tab = new int[tabSize];
		for (int i = 0; i < tabSize; i++)
			tab[i] = pcOther.tab[i];
	}
	else
		cout << ERROR;

	cout << COPY << tabSize << endl;
	cout << COPY << s_name << endl;

}

CTable::~CTable()
{
	cout << DELETE << s_name << endl;
	delete[] tab;
}

void CTable::vSetName(string sName)
{
	cout << NEW << sName << endl;
	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen)
{
	if (iTableLen < UNCORRECT_DIMENSION)
		return false;
	else {
		//CTable::tabSize = iTableLen;

		//return true;
		int* new_tab = new int[iTableLen];
		for (int i = 0; i < iTableLen; i++)
				new_tab[i] = tab[i];

		tabSize = iTableLen;
		delete[] tab;
		tab = new_tab;
		return true;
	}

}

CTable* CTable::pcClone()
{
	CTable* pc_new_tab = this;
	CTable* c_tab = new CTable(*(pc_new_tab));

	return c_tab;
}

void CTable::info()
{
	cout << NAME << s_name << endl;
	cout << A_TAB_SIZE << tabSize << endl;
}

void CTable::vPrint()
{
	for (int i = 0; i < tabSize; i++)
		cout << tab[i] << " ";

	cout << endl;
}

void CTable::vSetValueAt(int offSet, int newValue)
{
	if (offSet < tabSize)
		tab[offSet] = newValue;
}

void CTable::copyTable(int* tab1, int* tab2, int size) 
{
	for (int i = 0; i < size; i++)
	{
		tab2[i] = tab1[i];
	}
}

void CTable::operator=(const CTable& pcOther)
{
	delete[] tab;

	tabSize = pcOther.tabSize;
	tab = new int[tabSize];

	copyTable(pcOther.tab, tab, tabSize);
}


CTable CTable::operator+(CTable& obj)
{
	CTable new_table;

	new_table.bSetNewSize(tabSize + obj.tabSize);
	new_table.vSetName(NEW_NAME_MOD);
	
	for (int i = 0; i < new_table.getLength(); i++)
	{
		if (i < tabSize)
			new_table.vSetValueAt(i, tab[i]);
		else
			new_table.vSetValueAt(i, obj.tab[i - tabSize]);
	}
	return new_table;
}

CTable CTable::operator- (const CTable& obj)
{
	CTable help_tab;

	int iCounter = 0;
	bool bContains = false;

	help_tab.bSetNewSize(tabSize);
	help_tab.vSetName(NEW_NAME_MOD);


	for (int ij = 0; ij < tabSize; ij++)
	{
		for (int ii = 0; ii < obj.tabSize; ii++)
			if (obj.tab[ii] == tab[ij])
				bContains = true;

		if (!bContains)
		{
			help_tab.tab[iCounter] = tab[ij];
			iCounter++;
			bContains = false;
		}
	}

	help_tab.bSetNewSize(iCounter);

	return help_tab;
}

CTable CTable::loop(CTable ctable, int number) {

	for (int i = 0; i < ctable.tabSize; i++) {

		ctable.tab[i] = ctable.tab[i] * number;

	}

	return ctable;

}

CTable CTable::operator*(int number) {

	//for (int i = 0; i < iTableLen; i++) {

		//array[i] = array[i] * number;

	//}

	*this = loop(*this, number);

	return *this;

}
void CTable::operator/(int number)
{
	if (number > 0) {
		int new_size = int(ceil(this->tabSize - (this->tabSize / number)));

		int* newtab = new int[new_size];
		int position = 0;

		for (int i = 0; i < tabSize; i++)
		{
			if (i % number != 0) {
				newtab[position++] = this->tab[i];
			}
		}

	delete[] this->tab;
	this->tab = newtab;
	this->tabSize = new_size;
	}
	else {
		throw "Wrong divisor";
	}
}

/*
void CTable::operator=(CTable& pcOther)
{
	tab = pcOther.tab;
	tabSize = pcOther.tabSize;
}
*/
/*
CTable CTable::operator+(CTable& pcOther)
{
	CTable c_Ress;
	c_Ress.tab = pcOther.tab + c_Ress;
	return c_Ress;
}
*/