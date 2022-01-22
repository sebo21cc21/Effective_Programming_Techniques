#pragma once
#include <iostream>
#include "CMax3SatProblem.h"
using namespace std;
class CGAIndividual
{
private:
	bool* genotype;
	int fitness;
	int crossingChance;

public:
	CGAIndividual();
	CGAIndividual(bool value);
	CGAIndividual(bool* newGeneration);
	CGAIndividual(const CGAIndividual& other);

	~CGAIndividual();

	bool** crossover( CGAIndividual& other);
	void mutation(int probab);
	int getFitness(vector<Clause*> clauses, CMax3SatProblem problem);

	bool* getGenotype();

	void showGenotype();

};