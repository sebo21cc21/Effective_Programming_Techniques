#include "CMax3SatProblem.h"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Variables.h"
using namespace std;


vector<Clause*> CMax3SatProblem::load(int amountOfClauses, string filename) {

	// opening file
	ifstream file;
	file.open(filename);
	if (!file.good())
		return vector<Clause*>();

	// vector of clauses
	vector<Clause*> clauses;

	string line;
	const char separator = ' ';
	vector<string> outputArray;
	string val;

	// reading data
	for (int i = 0; i < amountOfClauses; i++) {
		getline(file, line);

		// spliting after space
		stringstream streamData(line);
		while (getline(streamData, val, separator))
			outputArray.push_back(val);

		// new clause added to vector
		Clause* read = new Clause(
			stoi(outputArray[1]),
			stoi(outputArray[3]),
			stoi(outputArray[5])
		);

		clauses.push_back(read);
		outputArray.clear();
	}

	// closing file and clearing
	file.close();

	return clauses;
}


int CMax3SatProblem::compute(bool* solution, int amountOfClauses, vector<Clause*>& clauses) {
	int counter = 0;
	for (int i = 0; i < amountOfClauses; i++) {
		if (clauses[i]->clauseValue(solution))
			counter++;
	}
	return counter;
}
/*
int CMax3SatProblem::compute(bool* solution, int amountOfClauses, vector<Clause*>& clauses) {
	int counter = 0;
	for (int i = 0; i < amountOfClauses; i++) {

		int nr = clauses.at(i)->getFirst();
		if (bClauseValue(nr, solution, amountOfClauses))
			counter++;

		int nr2 = clauses.at(i)->getSecond();
		if (bClauseValue(nr2, solution, amountOfClauses))
			counter++;


		int nr3 = clauses.at(i)->getThird();
		if (bClauseValue(nr3, solution, amountOfClauses))
			counter++;

	}
	return counter;
}

bool CMax3SatProblem::bClauseValue(int index, bool* solution, int amountOfClauses)
{
	for (int i = 0; i < amountOfClauses; i++) {


		if (index >= 0 && solution[index])
			return true;
		else {
			if (index < 0 && !solution[abs(index)])
				return true;
		}
		return false;
	}
}
*/