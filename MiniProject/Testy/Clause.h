#pragma once
#include <iostream>
class Clause
{
private:
	int first; 
	int second;
	int third;

public:
	Clause();
	Clause(int first, int second, int third);

	~Clause();

	void show();

	int getFirst();
	int getSecond();
	int getThird();

	void setFirst(int first);
	void setSecond(int second);
	void setThird(int third);

	bool clauseValue(bool* solution);
};