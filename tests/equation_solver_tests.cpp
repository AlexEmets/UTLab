#include <gtest/gtest.h>
#include "/home/oleksandryemets/Documents/University/UnitTestsLab1/equationSolver.h"
#include "/home/oleksandryemets/Documents/University/UnitTestsLab1/mocks/equationSolverMock.h"

char kWrongArgumentError[] = "Wrong argument at dichotomy method: The function at the ends of\n"
                                                "the segment must take values of different signs";

const double EPS = 1e-6;
const double PI = 3.14159265359;

bool isNear(double x, double y) {
    return std::abs(x - y) <= 1e-6;
}

constexpr double EPS_FOR_ROOT = 1e-11;

TEST(SimpleTests, BasicLinearEquations) {

  EquationSolver solver;
  auto function1 = [](double x){return x+1;};
  ASSERT_TRUE(isNear(-1.0, solver.solveEquationDichotomyMethod(function1, -2, 2, EPS_FOR_ROOT)));

  auto function2 = [](double x){return x+18;};
  ASSERT_TRUE(isNear(-18, solver.solveEquationDichotomyMethod(function2, -20.0, 0.0, EPS_FOR_ROOT)));

  auto function3 = [](double x){return x;};
  ASSERT_TRUE(isNear(0.0, solver.solveEquationDichotomyMethod(function3, -1.0, 1.0, EPS_FOR_ROOT)));

  auto function4 = [](double x){return 3*x-75;};
  ASSERT_TRUE(isNear(25.0, solver.solveEquationDichotomyMethod(function4, -10.0, 30.0, EPS_FOR_ROOT)));

  auto function5 = [](double x){return 100*x-1540;};
  ASSERT_TRUE(isNear(15.4, solver.solveEquationDichotomyMethod(function5, 10, 30, EPS_FOR_ROOT)));

 }

TEST(SimpleTests, BasicPowerEquations) {

  EquationSolver solver;

  auto function1 = [](double x){return x*x*x-x*x;};
  ASSERT_TRUE(isNear(0, solver.solveEquationDichotomyMethod(function1, -1, 1, EPS_FOR_ROOT)));

  auto function2 = [](double x){return x*x-2*x+1;};
  ASSERT_TRUE(isNear(1, solver.solveEquationDichotomyMethod(function2, 1, 2, EPS_FOR_ROOT)));
  

  auto function3 = [](double x){return pow(x,6)-64;};
  ASSERT_TRUE(isNear(2.0, solver.solveEquationDichotomyMethod(function3, -1, 4, EPS_FOR_ROOT)));
  

  auto function4 = [](double x){return pow(x,3) -1;};
  ASSERT_TRUE(isNear(1.0, solver.solveEquationDichotomyMethod(function4, -1, 2.0, EPS_FOR_ROOT)));
  
}

TEST(HardTests, Trigonometry) {

  EquationSolver solver;

  auto function1 = [](double x){return sin(x);};
  ASSERT_TRUE(isNear(0.0, solver.solveEquationDichotomyMethod(function1, -1, 1, EPS_FOR_ROOT)));

  auto function2 = [](double x){return cos(x);};
  ASSERT_TRUE(isNear(3*PI/2, solver.solveEquationDichotomyMethod(function2, 3, 5, EPS_FOR_ROOT)));

}

TEST(HardTests, NonLinearEquation) {

  EquationSolver solver;

  // Equation: e^(-x-1) + x^2 + 2x - 1 = 0.
  auto function = [](double x){return exp(-x-1) + pow(x,2) + 2*x - 1;};
  ASSERT_TRUE(isNear(0.315974, solver.solveEquationDichotomyMethod(function, 0, 1)));

}

TEST(HardTests, Exceptions) {

  EquationSolver solver;

  // Equation: e^(-x-1) + x^2 + 2x - 1 = 0.
  auto function = [](double x){return x+1;};

  EXPECT_THROW({
        try
        {
            solver.solveEquationDichotomyMethod(function, 0, 1);
        }
        catch( const std::logic_error& e )
        {
            // and this tests that it has the correct message
            EXPECT_STREQ( kWrongArgumentError, e.what() );
            throw;
        }
    }, std::logic_error );

}

TEST(TestsWithMocks, BasicMockTest) {
  equationSolverMock equationSolverMock;
}

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}