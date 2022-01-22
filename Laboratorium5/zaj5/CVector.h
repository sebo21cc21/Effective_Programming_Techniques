#pragma once
#include <iostream>
#include "const.h"
#include <vector>
using namespace std;

class CVector
{
public:
	CVector();
	CVector(int d_val);
	~CVector();
	CVector(const CVector& cNumber);
	CVector(CVector&& cNumber);
	void operator=(CVector&& cNumber);
	void operator=(const CVector& cNumber);
	void vPrint();
	void vSet(int v_val);
private:
	vector<int*> v_number;

};

