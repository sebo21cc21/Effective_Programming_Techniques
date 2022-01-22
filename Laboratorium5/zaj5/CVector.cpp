#include "CVector.h"
#include <iostream>
#include "const.h"

using namespace std;

CVector::CVector()
{
	for (int i = 0; i < v_number.size(); i++)
	{
		v_number[i] = new int;
		*v_number[i] = DEFAULT_VALUE_VECTOR;
	}

	if(DEBUG) cout << CONSTRUCTOR << endl;
}

CVector::CVector(int v_val)
{
	for (int i = 0; i < v_number.size(); i++)
	{
		v_number[i] = new int;
		*v_number[i] = v_val;
	}


	if (DEBUG) cout << CONSTRUCTOR << endl;
}

CVector::CVector(const CVector& obj)
{
	for (int i = 0; i < v_number.size(); i++)
	{
		v_number[i] = new int;
		*v_number[i] = *obj.v_number[i];
	}

	if (DEBUG) cout << sCOPY << endl;
}

CVector::CVector(CVector&& obj)
{
	for (int i = 0; i < v_number.size(); i++)
	{
		v_number[i] = obj.v_number[i];
		obj.v_number[i] = NULL;
	}

	if (DEBUG) cout << sMOVE << endl;
}


CVector :: ~CVector()
{
	for (int i = 0; i < v_number.size(); i++)
	{
		if (v_number[i] != NULL)
			delete v_number[i];
	}


	if (DEBUG) cout << DESTRUCTOR << endl;
}


void CVector::vPrint()
{
	for (int i = 0; i < v_number.size(); i++)
	{
		cout << (*v_number[i]) << endl;
	}
}

void CVector :: operator=(CVector&& obj)
{

	if (this != &obj)
	{

		for (int i = 0; i < v_number.size(); i++)
		{
			if (v_number[i] != NULL) 
			{
				delete v_number[i];

				v_number[i] = obj.v_number[i];
				obj.v_number[i] = nullptr;
			}

		}
			
	}

	if (DEBUG) cout << OPERATOR_EQUAL_MOVE << endl;
}

void CVector :: operator= (const CVector& obj)
{
	for (int i = 0; i < v_number.size(); i++)
	{
		*(v_number[i]) = *(obj.v_number[i]);
	}


	if (DEBUG) cout << OPERATOR_EQUAL << endl;
}

void CVector::vSet(int v_val)
{
	for (int i = 0; i < v_number.size(); i++)
	{
		*v_number[i] = v_val;
		if (DEBUG) cout << NEW_VAL << (*v_number[i]) << endl;
	}

}

