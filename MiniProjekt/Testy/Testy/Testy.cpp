#include <iostream>
#include <vector>
#include "CMax3SatProblem.h"
#include "CGAOptimizer.h"
#include "CGAIndividual.h"
using namespace std;

void runTest(CGAOptimizer* opt) {
    opt->showPopulation();
    opt->showBestInPopulation();
    cout << endl;
}
int main()
{
    // creating problem
    CMax3SatProblem problem = CMax3SatProblem();

    // creating optimizer
    CGAOptimizer* opt = new CGAOptimizer(problem);

    // wczytujemy dane w metodzie initialize, jeśli się nie da to wychodzimy
    if (opt->initialize("50/m3s_50_6.txt")) {

        cout << "Population before iteration: " << endl;
        runTest(opt);

        opt->runIteration();
        cout << "Population after 1st iteration:  " << endl;
        runTest(opt);

        opt->runIteration();
        cout << "Population after 2nd iteration: " << endl;
        runTest(opt);

        opt->runIteration();
        cout << "Population after 3rd iteration: " << endl;
        runTest(opt);

    }
    else {
        cout << "Unable to create data file, check if name is correct!" << endl;
    }

    delete opt;
}