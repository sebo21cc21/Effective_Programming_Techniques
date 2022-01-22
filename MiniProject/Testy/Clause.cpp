#include "Clause.h"
#include <iostream>
using namespace std;

Clause::Clause() {
	first = 0;
	second = 0;
	third = 0;
}

Clause::Clause(int first, int second, int third) {
	this->first = first;
	this->second = second;
	this->third = third;
}

Clause::~Clause() {

}

void Clause::show() {
	cout << first << ", " << second << ", " << third << endl;
}

int Clause::getFirst() {
	return first;
}

int Clause::getSecond() {
	return second;
}

int Clause::getThird() {
	return third;
}

void Clause::setFirst(int first) {
	this->first = first;
}

void Clause::setSecond(int second) {
	this->second = second;
}

void Clause::setThird(int third) {
	this->third = third;
}

bool Clause::clauseValue(bool* solution) {
	if (first >= 0 && solution[first])
		return true;
	else if (first < 0 && !solution[abs(first)])
		return true;
	else if (second >= 0 && solution[second])
		return true;
	else if (second < 0 && !solution[abs(second)])
		return true;
	else if (third >= 0 && solution[third])
		return true;
	else if (third < 0 && !solution[abs(third)])
		return true;
	else
		return false;
}
