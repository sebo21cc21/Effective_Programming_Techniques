#include "CGAOptimizer.h"
#include "Variables.h"
using namespace std;

CGAOptimizer::CGAOptimizer(CMax3SatProblem problem)
{
	this->populationSize = POPULATIONSIZE;
	this->crossingChance = CROSSINGCHANCE;
	this->mutationChance = MUTATIONCHANCE;
	this->problem = problem;
}

CGAOptimizer::~CGAOptimizer() {
	for (int i = 0; i < population.size(); i++)
		delete population[i];

	if (!clauses.empty()) {
		for (int i = 0; i < AMOUNTOFCLAUSES; i++)
			delete clauses[i];
	}

	population.clear();
	clauses.clear();
}

bool CGAOptimizer::initialize(string fileName) {
	srand(time(NULL));

	// opening file
	clauses = problem.load(AMOUNTOFCLAUSES, fileName);

	// creating random population
	for (int i = 0; i < populationSize; i++) {
		bool* gens = new bool[PROBLEMSIZE];

		for (int j = 0; j < PROBLEMSIZE; j++) {
			int random = rand() % 2;
			gens[j] = random;
		}

		population.push_back(new CGAIndividual(gens));
	}

	// checking if opening file was succesfull
	return clauses.empty() ? false : true;
}

void CGAOptimizer::showPopulation() {
	for (int i = 0; i < populationSize; i++)
		population.at(i)->showGenotype();
}

CGAIndividual* CGAOptimizer::tournament(vector<CGAIndividual*> somePopulation) {
	// drawing objects for tournament
	bool* isInTournament = new bool[populationSize];
	for (int j = 0; j < populationSize; j++)
		isInTournament[j] = false;

	vector<CGAIndividual*> areInTournament;
	int i = 0;
	CGAIndividual* actual = nullptr;

	while (i < TOURNAMENTSIZE) {
		// drawing object
		int index = std::rand() % populationSize;

		// checking if in tournament, if not enrolling it to contenstants' list 
		if (!isInTournament[index]) {
			actual = somePopulation.at(index);
			isInTournament[index] = true;
			areInTournament.push_back(actual);
			i++;
		}
	}

	// searching for a winenr
	CGAIndividual* winner = areInTournament[0];
	int actualResult = winner->getFitness(clauses, problem);

	for (int j = 1; j < TOURNAMENTSIZE; j++) {
		int act = areInTournament.at(j)->getFitness(clauses, problem);

		if (act > actualResult) {
			actualResult = act;
			winner = areInTournament.at(j);
		}
	}

	// destructing
	delete[] isInTournament;
	areInTournament.clear();
	actual = NULL;

	return winner;
}

void CGAOptimizer::runIteration() {
	srand(time(NULL));

	vector<CGAIndividual*> newPopulation;

	CGAIndividual* child1;
	CGAIndividual* child2;

	while (newPopulation.size() < population.size()) {

		CGAIndividual* father = tournament(population);
		CGAIndividual* mother = tournament(population);

		// checking if they are not the same
		while (mother == father)
			mother = tournament(population);

		// checking if we're going to cross
		int probability = (std::rand() % 100) + 1;

		// crossing gens if propability smaller than 
		if (probability < crossingChance) {
			bool** children = father->crossover(*mother);
			CGAIndividual* child1 = new CGAIndividual(children[0]);
			CGAIndividual* child2 = new CGAIndividual(children[1]);

			// setting double pointer to NULL after getting data from table
			children[0] = NULL;
			children[1] = NULL;
			delete[] children;
			children = NULL;

			// mutation
			child1->mutation(mutationChance);
			child2->mutation(mutationChance);

			//mod
			optimizeOneClause(child1);
			optimizeOneClause(child2);

			// adding children to population
			newPopulation.push_back(child1);
			newPopulation.push_back(child2);
		}

		// if smaller then adding copy
		else {
			child1 = new CGAIndividual(*father);
			child2 = new CGAIndividual(*mother);

			//mod
			optimizeOneClause(child1);
			optimizeOneClause(child2);

			newPopulation.push_back(child1);
			newPopulation.push_back(child2);
		}

	}

	// deleting former population
	for (int i = 0; i < populationSize; i++)
		delete population[i];

	population = newPopulation;
}

void CGAOptimizer::showBestInPopulation() {

	int m = population[0]->getFitness(clauses, problem);
	int actual = m;
	bool* best = population[0]->getGenotype();

	for (int i = 1; i < populationSize; i++) {
		actual = population[i]->getFitness(clauses, problem);
		if (actual > m) {
			best = population[i]->getGenotype();
			m = actual;
		}
	}

	cout << "Best solution in population is:  " << actual << " for object: ";
	for (int i = 0; i < PROBLEMSIZE; i++)
		std::cout << best[i] ? 1 : 0;

	std::cout << std::endl;
	best = NULL;
}

//mod
void CGAOptimizer::optimizeOneClause(CGAIndividual* pcIndividual)
{
	int index = std::rand() % clauses.size();
	Clause* currentClause = clauses[index];

	int iFirst = abs(currentClause->getFirst());
	int iSecond = abs(currentClause->getSecond());
	int iThird = abs(currentClause->getThird());

	if (!(currentClause->clauseValue(pcIndividual->getGenotype())))
	{
		pcIndividual->getGenotype()[iFirst] = !(pcIndividual->getGenotype()[iFirst]);
		pcIndividual->getGenotype()[iSecond] = !(pcIndividual->getGenotype()[iSecond]);
		pcIndividual->getGenotype()[iThird] = !(pcIndividual->getGenotype()[iThird]);
	}
}