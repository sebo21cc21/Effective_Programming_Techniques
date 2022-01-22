#pragma once
#include "Clause.h"
#include <iostream>
#include <vector>
using namespace std;

class CMax3SatProblem
{
public:
	vector<Clause*> load(int clausesNum, string file);
	int compute(bool* solution, int clausesNum, vector<Clause*>& clauses);
};