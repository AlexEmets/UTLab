#include <iostream>
#include <cmath>
#include <iomanip>
#include "equationSolver.h"


// Equation: e^(-x-1) + x^2 + 2x - 1 = 0.
constexpr double default_func(double x) {
    // return exp(-x-1) + pow(x,2) + 2*x - 1;
    //return x-1;
    // return pow(x,2)+2*x+1;
    // return 2 * pow(x, 3) - 4 * pow(x, 2) + 2 * x;
    //return 5 * pow(x, 2) + 10 * x - 15;
    return sin(x);
    return cos(x);
}

int main() {
    EquationSolver solver;

    try {
        std::cout << std::setprecision(20) << solver.solveEquationDichotomyMethod(default_func, 0.5, 1.0) << std::endl;
    }catch(std::exception& e) {
        std::cout << e.what() << '\n';
    }

}
