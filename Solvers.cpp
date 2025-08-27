#include <stdio.h>
#include <math.h>

const int SS_INF_ROOTS = -1; // значение, используемое для обозначения бесконечного количества корней
int LineSolver(const double b, const double c, double* const x1, double* const x2);  // решает линейное уравнение
int SquareSolver(const double a, const double b, const double c, double* const x1, double* const x2); //решает квадратное уравнение

//----------------------------------------------
//! @param [in] a    a - coefficient
//! @param [in] b    b - coefficient
//! @param [in] c    c - coefficient
//! @param [out] x1  Pointer to the 1st root
//! @param [out] x2  Pointer to the 2st root
//!
//! @return Number of roots
//!
//! @note   In case of infinite number of roots,
//!         returns SS_INF_ROOTS.
//----------------------------------------------

int CommonSolver(const double a, const double b, const double c, double* const x1, double* const x2)
    {
    assert(x1 != NULL);
    assert(x2 != NULL);

    int count_x = 0;

    if (fabs(a - 0) < MIN_DIFFERENT)
        count_x = LineSolver(b, c, x1, x2);
    else
        count_x = SquareSolver(a, b, c, x1, x2);
    return count_x;
    }


int LineSolver(const double b, const double c, double* const x1, double* const x2)
    {
    assert(isfinite(b));
    assert(isfinite(c));

    assert (x1 != NULL);
    assert (x2 != NULL);

    int count_x = 0;
    if (fabs(b - 0) < MIN_DIFFERENT)
        {
        count_x = (fabs(c - 0) < MIN_DIFFERENT) ? SS_INF_ROOTS : 0;
        *x1 = NAN;
        *x2 = NAN;
        return count_x;
        }
    else
        {
        *x1 = *x2 = -1 * c / b;
        if (fabs(*x1 - 0) < MIN_DIFFERENT)
            *x1 = *x2 = 0;
        return 1;
        }
    }


int SquareSolver(const double a, const double b, const double c, double* const x1, double* const x2)
    {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert (x1 != NULL);
    assert (x2 != NULL);

    const double d = b * b - 4 * a * c;

    if (fabs(d - 0) < MIN_DIFFERENT)
        {
        *x1 = *x2 = -b / (2 * a);
        if (fabs(*x1 - 0) < MIN_DIFFERENT)
            *x1 = *x2 = 0;
        return 1;
        }

    if (d < 0)
        {
        *x1 = NAN;
        *x2 = NAN;
        return 0;
        }

    if (d > 0)
        {
        const double sqrt_d = sqrt(d);
        *x1 = (-b + sqrt_d) / (2 * a);
        *x2 = (-b - sqrt_d) / (2 * a);
        if (fabs(*x1 - 0) < MIN_DIFFERENT)
            *x1 = 0;
        if (fabs(*x2 - 0) < MIN_DIFFERENT)
            *x2 = 0;
        return 2;
        }
    return 0;
    }
