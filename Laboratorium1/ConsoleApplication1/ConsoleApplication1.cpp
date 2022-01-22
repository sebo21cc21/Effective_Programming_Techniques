#include <iostream>
using namespace std;

void v_alloc_table_add_5(int iSize);
void print_tab(int* tab, int iSize);
void full_tab(int* tab, int iSize);

int main()
{
	bool flaga;
	flaga = 1;
	int iSize = 5;

	if (iSize < 0)
		flaga = 0;

	if (flaga == 1)
		v_alloc_table_add_5(iSize);
}

void print_tab(int* tab, int iSize)
{
	for (int i = 0; i < iSize; i++)
	{
		cout << "Tablica nr" << i << "  " << tab[i] << endl;
	}
}

void full_tab(int* tab, int iSize)
{
	for (int i = 0; i < iSize; i++)
	{
		tab[i] = i + 5;
	}
}
void v_alloc_table_add_5(int iSize)
{
    int* tab = new int[iSize];
	full_tab(tab, iSize);
	print_tab(tab, iSize);
	delete [] tab;
}

