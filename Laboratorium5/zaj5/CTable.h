#pragma once
#include <iostream>
#include "const.h"
using namespace std;

// skraca tablice o jeden i zwraca usunieta wartosc

class CTable
{
public:
	CTable();
	CTable(string sName, int iTableLen);
	CTable(const CTable& pcOther);
	CTable(CTable&& cOther);
	~CTable();
	void operator= (const CTable& obj);
	void operator= (CTable&& cOther);
	CTable operator+ (const CTable& obj);
	CTable operator- (const CTable& obj);
	CTable operator* (const CTable& obj);
	void vSetName(string sName);
	bool bSetNewSize(int iTableLen);
	void printArray();
	void vSetValueAt(int iOffset, int iNewVal);
	int pop();
	void fill();
	void print();
	bool contains(int iELem);
	CTable* pcClone();
	void remove(int iIndex);
	int* getArray() { return array; }
	int getLength() { return arrayLength; }
	int getElem(int elem);
	string getName() { return s_name; }


private:
	string s_name;
	int* array;
	int arrayLength;


};

