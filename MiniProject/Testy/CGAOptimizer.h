#pragma once
#include <vector>
#include <ctime>
#include <random>
#include "CGAIndividual.h"
#include "CMax3SatProblem.h"
using namespace std;

class CGAOptimizer
{
private:
	int populationSize;
	int crossingChance;
	int mutationChance;

	vector<CGAIndividual*> population;
	vector<Clause*> clauses;

	CMax3SatProblem problem;

public:
	CGAOptimizer(CMax3SatProblem problem);
	~CGAOptimizer();

	bool initialize(string fileName);
	CGAIndividual* tournament(vector<CGAIndividual*> population);
	void runIteration();

	void showPopulation();
	void showBestInPopulation();

	void optimizeOneClause(CGAIndividual* pcIndividual);
};