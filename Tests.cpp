#include <stdio.h>
#include <math.h>
#include "Tests.h"
#include "Solvers.h"

const double MIN_DIFFERENT = 0.000001;  // погрешность

struct TestInfoEquation  // структура, содержащая информацию о тестах
    {
    double a, b, c;
    int count_xref;
    double x1ref, x2ref;
    };

int OneTest(TestInfoEquation test);  // функция, проводящая один тест

int TestSolveSquare() // функция со всеми тестами
    {
    int failed = 0; // количество непройденных тестов
    TestInfoEquation tests[] = {{.a = 0, .b = 0, .c = 0, .count_xref = -1, .x1ref = NAN, .x2ref = NAN},
                    {.a = 0, .b = 1, .c = 0, .count_xref = 1, .x1ref = 0, .x2ref = 0},
                    {.a = 0, .b = 0, .c = 1, .count_xref = 0, .x1ref = NAN, .x2ref = NAN},
                    {.a = 0, .b = 23, .c = 409, .count_xref = 1, .x1ref = -17.782608, .x2ref = -17.782608},
                    {.a = 0, .b = 0.0001, .c = -9, .count_xref = 1, .x1ref = 90000, .x2ref = 90000},
                    {.a = 4, .b = 0, .c = 0, .count_xref = 1, .x1ref = 0, .x2ref = 0},
                    {.a = 9, .b = 0, .c = 9, .count_xref = 0, .x1ref = NAN, .x2ref = NAN},
                    {.a = -1, .b = -2, .c = -1, .count_xref = 1, .x1ref = -1, .x2ref = -1},
                    {.a = 1, .b = -5, .c = 6, .count_xref = 2, .x1ref = 3, .x2ref = 2},
                    {.a = 0.05, .b = -0.008, .c = -0.9, .count_xref = 2, .x1ref = 4.323395, .x2ref = -4.163395},
                    {.a = 1, .b = 0, .c = 4, .count_xref = 0, .x1ref = NAN, .x2ref = NAN}};
    size_t size_m = sizeof(tests) / sizeof(tests[0]);
    for  (size_t i = 0; i < size_m; i++)
        failed += !OneTest(tests[i]);

    return failed;
    }

int OneTest(TestInfoEquation test)
    {
    double x1 = 0, x2 = 0;
    int count_x = CommonSolver(test.a, test.b, test.c, &x1, &x2);
    if (test.count_xref > 0)  //проверка тестов с количеством корней 1 или 2
        {
        if (!((fabs(x1 - test.x1ref) < MIN_DIFFERENT) && (fabs(x2 - test.x2ref) < MIN_DIFFERENT) && (count_x == test.count_xref)))
            {
            printf("\033[1;31mFAILED: Solver(%lg, %lg, %lg) = %d, x1 = %lg, x2 = %lg, \n\
(should be count_x = %d, x1 = %lg, x2 = %lg)\033[0m\n", test.a, test.b, test.c, count_x, x1, x2, test.count_xref, test.x1ref, test.x2ref);
            return 0;
            }
        }
    else  if (!(isnan(x1) && isnan(x2) && (count_x == test.count_xref)))  //проверка тестов без корней или бесконечным количеством корней
        {
        printf("\033[1;31mFAILED: Solver(%lg, %lg, %lg) = %d, x1 = %lg, x2 = %lg, \n\
(should be count_x = %d, x1 = %lg, x2 = %lg)\033[0m\n", test.a, test.b, test.c, count_x, x1, x2, test.count_xref, test.x1ref, test.x2ref);
        return 0;
        }
    return 1;
    }
