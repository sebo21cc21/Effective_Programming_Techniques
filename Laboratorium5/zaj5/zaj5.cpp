#include <iostream>
#include "CMySmartPointer.h"
#include"CTab.h"
#include "CTable.h"
#include "CVector.h"

using namespace std;
void TestCVector();

int main() {

	int iSize = 5;
	int* tab = new int[iSize];

	CMySmartPointer<int> p1(tab);
	CMySmartPointer<int> p2(p1);

	cout << "Pointer1 " << p1.getT() << endl;
	cout << "Pointer2 " << p2.getT() << endl;

	int iSize1 = 10;
	int* tab2 = new int[iSize1];

	CMySmartPointer<int> p3(tab2);
	CMySmartPointer<int> p4(p3);

	cout << "Pointer3 " << p3.getT() << endl;
	cout << "Pointer4 " << p4.getT() << endl;

	p3 = p1;

	cout << "P3 = P1" << endl;
	cout << "P3: " << p3.getT() << endl;

	cout << "CTab" << "\n";

	CTab cTab1;
	CTab cTab2(cTab1);
	cout << endl;

	CTab cTab3;

	cTab3 = cTab1;
	cout << endl;

	CTab cTab4;

	cTab4 = move(cTab1);
	cout << endl;

// zadanie 5
	CTable c_tab_0("tab1", 0);
	CTable c_tab_1("tab2", 0);

	c_tab_0.bSetNewSize(4);
	c_tab_0.vSetValueAt(0, 1);
	c_tab_0.vSetValueAt(1, 2);
	c_tab_0.vSetValueAt(2, 3);
	c_tab_0.vSetValueAt(3, 4);
	c_tab_0.print();

	c_tab_1 = move(c_tab_0);
	c_tab_1.print();
	c_tab_0.print();

	CTable c_tab_2("tab2", 3);
	CTable c_tab_3("tab3", 2);

	c_tab_2.vSetValueAt(0, 4);
	c_tab_2.vSetValueAt(1, 4);
	c_tab_2.vSetValueAt(2, 4);
	c_tab_3.vSetValueAt(0, 54);
	c_tab_3.vSetValueAt(1, 55);

	CTable c_tab_4 = c_tab_2 + c_tab_3;
	c_tab_4.print();

}

void TestCVector()
{

	CVector number;

	CVector number0;
	CVector number1(10);
	CVector number2(number1);
	CVector number3(move(number));

	number0.vPrint();
	number1.vPrint();
	number2.vPrint();
	number3.vPrint();

	number1.vSet(99);
	number1.vPrint();

	number0 = number1;

	number0.vPrint();
	number1.vPrint();
	number2.vPrint();

	number2 = move(number1);

	number0.vPrint();
	number2.vPrint();

}