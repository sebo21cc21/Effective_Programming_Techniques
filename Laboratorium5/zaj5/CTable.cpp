#include "CTable.h"
#include "const.h"
#include <iostream>
using namespace std;


CTable::CTable()
{
	s_name = DEFAULT_VALUE_STRING;
	cout << BEZP << s_name << endl;
	arrayLength = DEFAULT_VALUE_INT;
	cout << LENGTH << arrayLength << endl;
	array = new int[arrayLength];

	fill();

}

CTable::CTable(string sName, int iTableLen)
{
	s_name = sName;
	cout << PAR << s_name << endl;
	arrayLength = iTableLen;
	cout << LENGTH << arrayLength << endl;
	array = new int[iTableLen];

	fill();

}

CTable::CTable(const CTable& pcOther)
{
	arrayLength = pcOther.arrayLength;
	if (arrayLength > UNCORRECT_DIMENSION)
	{
		array = new int[arrayLength];
		for (int i = 0; i < arrayLength; i++)
			array[i] = pcOther.array[i];
	}
	else
		cout << UNCORRECT_DATA << endl;

	cout << COPY << endl;
	s_name = pcOther.s_name + COPY;

	cout << COPY_PRINT << arrayLength << endl;
	cout << COPY_PRINT << s_name << endl;

}

CTable::~CTable()
{
	cout << DELETE << arrayLength << endl;
	delete array;
	cout << DELETE << s_name << endl;
}


void CTable::operator= (const CTable& obj)
{

	bSetNewSize(obj.arrayLength);

	for (int i = 0; i < obj.arrayLength; i++)
		vSetValueAt(i, obj.array[i]);

}

CTable CTable::operator- (const CTable& obj)
{
	CTable help_tab;

	int iCounter = 0;
	bool bContains = false;

	help_tab.bSetNewSize(arrayLength);
	help_tab.vSetName(NEW_NAME_MOD);


	for (int ij = 0; ij < arrayLength; ij++)
	{
		for (int ii = 0; ii < obj.arrayLength; ii++)
			if (obj.array[ii] == array[ij])
				bContains = true;

		if (!bContains)
		{
			help_tab.array[iCounter] = array[ij];
			iCounter++;
			bContains = false;
		}
	}

	help_tab.bSetNewSize(iCounter);
	help_tab.printArray();

	return help_tab;
}

CTable CTable::operator* (const CTable& obj)
{
	CTable help_tab;

	int iCounter = 0;
	bool bContains = false;

	help_tab.bSetNewSize(arrayLength);
	help_tab.vSetName(NEW_NAME_MOD);


	for (int ij = 0; ij < arrayLength; ij++)
	{
		for (int ii = 0; ii < obj.arrayLength; ii++)
			if (obj.array[ii] == array[ij])
				bContains = true;

		if (bContains)
		{
			help_tab.array[iCounter] = array[ij];
			iCounter++;
			bContains = false;
		}
	}

	help_tab.bSetNewSize(iCounter);
	help_tab.printArray();

	return move(help_tab);
}


CTable CTable::operator+(const CTable& obj)
{
	CTable new_tab;

	(new_tab).bSetNewSize(arrayLength + obj.arrayLength);
	new_tab.vSetName(NEW_NAME);

	for (int i = 0; i < (new_tab).getLength(); i++)
		if (i < arrayLength)
			(new_tab).vSetValueAt(i, array[i]);
		else
			(new_tab).vSetValueAt(i, obj.array[i - arrayLength]);


	(new_tab).printArray();

	return move(new_tab);
}


void CTable::remove(int iIndex)
{
	if (iIndex < arrayLength && iIndex > LESS_ZERO_ARRAY)
	{
		arrayLength--;

		for (int ii = iIndex--; ii < arrayLength--; ii++)
			array[ii] = array[ii + 1];
	}
	else
		cout << UNCORRECT_DATA << endl;
}

bool CTable::contains(int iElem)
{
	for (int ii = 0; ii < arrayLength; ii++)
		if (array[ii] == iElem)
			return true;

	return false;
}


void CTable::vSetValueAt(int offSet, int newValue)
{
	if (offSet < arrayLength)
		array[offSet] = newValue;
}

int CTable::getElem(int elem)
{
	if (elem < arrayLength && elem >= LESS_ZERO_ARRAY)
		return array[elem];
}

void CTable::fill()
{
	cout << FILLING << endl;

	for (int i = 0; i < arrayLength; i++)
		array[i] = i + DEFAULT_VALUE_INT;;
}

int CTable::pop()
{
	printArray();

	int var = array[arrayLength - DECREASE_VALUE_POP];

	int* new_arr = new int[arrayLength - DECREASE_VALUE_POP];

	for (int i = 0; i < (arrayLength - DECREASE_VALUE_POP); i++)
	{
		new_arr[i] = array[i];

	}

	delete[] array;
	array = new_arr;
	arrayLength -= DECREASE_VALUE_POP;

	printArray();

	return var;
}

void CTable::printArray()
{
	for (int i = 0; i < arrayLength; i++)
		cout << array[i] << " ";

	cout << endl;
}

void CTable::vSetName(string sName)
{
	cout << NEW_DATA << sName << endl;
	s_name = sName;
}


bool CTable::bSetNewSize(int iTableLen)
{
	if (iTableLen < UNCORRECT_DIMENSION)
		return false;

	cout << NEW_DATA << iTableLen << endl;

	int* new_arr = new int[iTableLen];
	for (int i = 0; i < iTableLen; i++)
	{
		if (i < arrayLength)
			new_arr[i] = array[i];

		if (i >= arrayLength)
			new_arr[i] = (UNBOUND_VALUE);

	}

	arrayLength = iTableLen;
	delete[] array;
	array = new_arr;

	return true;
}

CTable* CTable::pcClone()
{
	CTable* pc_new_tab = this;
	CTable* c_tab = new CTable(*(pc_new_tab));

	return c_tab;
}


void CTable::print()
{
	cout << NAME << s_name << LENGTH << arrayLength << endl;
}



CTable::CTable(CTable&& cOther)
{
	s_name = cOther.s_name + MOVE;
	array = cOther.array;
	arrayLength = cOther.arrayLength;
	cOther.array = NULL;
	cout << MOVE;
}//CTab::CTab(CTab &&cOther)


void CTable ::  operator=(CTable&& cOther)
{
	if (this != &cOther)
	{
		if (array != NULL) delete[] array;

		s_name = cOther.s_name + MOVE;
		array = cOther.array;
		arrayLength = cOther.arrayLength;

		cOther.array = nullptr;
		cOther.arrayLength = 0;
	}
}
