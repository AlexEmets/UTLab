//
// Created by oleksandr.yemets on 5/1/2022.
//
#ifndef NONLINEAREQUATIONS_EQUATIONSOLVER_H
#define NONLINEAREQUATIONS_EQUATIONSOLVER_H
#include <cmath>
#include <stdexcept>



template<typename T>
using IsFloatingPoint = std::enable_if_t<std::is_floating_point_v<T>, bool>;

class EquationSolver {
private:

    static char kWrongArgumentError[];


public:
    template<typename Function>
    constexpr double solveEquationDichotomyMethod(Function func,
                                         double leftEnd = std::numeric_limits<double>::min(),
                                         double rightEnd = std::numeric_limits<double>::max(),
                                         double eps = std::numeric_limits<double>::epsilon());


};



template<typename Function>
constexpr double EquationSolver::solveEquationDichotomyMethod(Function func,
                                     double leftEnd,
                                     double rightEnd,
                                     double eps) {

    if (func(leftEnd) * func(rightEnd) > 0.0 || eps < 0) {

        throw std::logic_error(kWrongArgumentError);

    }

    double root;

    while(abs(rightEnd - leftEnd) /2 > eps){
        root = (leftEnd + rightEnd) / 2;
        if((func(leftEnd) * func(root)) > 0) leftEnd = root;
        else rightEnd = root;
    } 

    return root;
}


char EquationSolver::kWrongArgumentError[] = "Wrong argument at dichotomy method: The function at the ends of\n"
                                                "the segment must take values of different signs";

#endif //NONLINEAREQUATIONS_EQUATIONSOLVER_H
