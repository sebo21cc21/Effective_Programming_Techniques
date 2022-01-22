#include "CGAIndividual.h"
#include <ctime>
#include <random>
#include <sstream>
#include "Variables.h"
using namespace std;

CGAIndividual::CGAIndividual() {
	genotype = NULL;
	crossingChance = CROSSINGCHANCE;
	fitness = 0;
	crossingChance = 0;
}

CGAIndividual::CGAIndividual(bool value) {
	fitness = 0;
	crossingChance = 0;
	genotype = new bool[PROBLEMSIZE];


	for (int i = 0; i < PROBLEMSIZE; i++)
		genotype[i] = value;
}


CGAIndividual::CGAIndividual(bool* newGeneration) {
	fitness = 0;
	crossingChance = 0;
	if (genotype != NULL)
		delete[] genotype;
	genotype = newGeneration;
}

CGAIndividual::CGAIndividual(const CGAIndividual& other) {
	fitness = 0;
	crossingChance = 0;
	if (genotype != NULL)
		delete[] genotype;

	bool* newGenotype = new bool[PROBLEMSIZE];

	for (int i = 0; i < PROBLEMSIZE; i++)
		newGenotype[i] = other.genotype[i];

	genotype = newGenotype;
}

CGAIndividual::~CGAIndividual() {
	delete[] genotype;
}

bool** CGAIndividual::crossover(CGAIndividual& other) {
	srand(time(NULL));

	int randomIndex;
	bool** result = new bool* [2];

	for (int i = 0; i < 2; i++)
		result[i] = new bool[PROBLEMSIZE];

	for (int i = 0; i < PROBLEMSIZE; i++) {
		randomIndex = std::rand() % 2;

		if (randomIndex == 0) {
			result[0][i] = genotype[i];
			result[1][i] = other.genotype[i];
		}
		else {
			result[0][i] = other.genotype[i];
			result[1][i] = genotype[i];
		}
	}

	return result;
}

void CGAIndividual::mutation(int propab) {
	int randomVariable;

	for (int i = 0; i < PROBLEMSIZE;i++){
		if (rand() % 100 < propab) genotype[i] = !genotype[i];
}
}

bool* CGAIndividual::getGenotype() {
	return genotype;
}

int CGAIndividual::getFitness(vector<Clause*> vectorOfClauses, CMax3SatProblem problem) {
	return problem.compute(genotype, AMOUNTOFCLAUSES, vectorOfClauses);
}

void CGAIndividual::showGenotype() {
	for (int i = 0; i < PROBLEMSIZE; i++) {
		int a = genotype[i] == true ? 1 : 0;
		cout << a;
	}
	cout << endl;
}
