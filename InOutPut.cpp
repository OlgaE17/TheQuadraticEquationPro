#include <stdio.h>
#include "InOutPut.h"

void KotikFunc(int number_of_cats)
    {
    int i = 0, g = 0;
    for (g = 0; g < number_of_cats; g++)
        {
        printf("\n");
        for (i = 0; i < 3; i ++)
             printf("    ^,,,^        __  (\\___/)        ");
        printf("\n");
        for (i = 0; i < 3; i ++)
            printf("  -(* . *)-      || ~(0 3 0)~       ");
        printf("\n");
        for (i = 0; i < 3; i ++)
            printf("   /     \\       ||  /     \\        ");
        printf("\n");
        for (i = 0; i < 3; i ++)
            printf("  /  | |  \\       \\\\/  | |  \\       ");
        printf("\n");
        for (i = 0; i < 3; i ++)
            printf("  \\_\\|_|/_/        \\__\\|_|/_/       ");
        printf("\n");
        for (i = 0; i < 3; i ++)
           printf("          \\\\    >0<          >0<    ");
        printf("\n");
        for (i = 0; i < 3; i ++)
            printf("      ><> //_      >0<      >0<     ");
        printf("\n");
        for (i = 0; i < 3; i ++)
            printf("  <><     \\_/           >0<         ");
        printf("\n");
        }
    }


void OutPutRoots(const int count_x, const double x1, const double x2) //печать корней
    {
    int cats = 0;
    switch(count_x)
        {
        case -1:
            printf("The equation has infinitely many roots.\n");
            break;
        case 0:
            printf("The equation has no roots.\n");
            break;
        case 1:
            printf("\033[1;34mThe equation has one root: %lg.\033[0m\n", x1);
            break;
        case 2:
            printf("\033[1;34mThe equation has two roots: %lg и %lg.\033[0m\n", x1, x2);
            break;
        default:
            printf("That's impossible.\n");
        }
    KotikFunc(1);
    printf("\033[1;35mNeed more cats? YES - 1.5. NO - 0.\033[0m\n");
    scanf("%d", &cats);
    while ((cats != 0) && (cats != 1))
        {
        printf("\033[1;31mYou entered an incorrect value, try again!\033[0m\n");
        while (fgetc(stdin) != '\n');
        scanf("%d", &cats);
        }
    if (cats == 1)
       KotikFunc(100);
    }


void NeedTest()  // проверяет, нужно ли проводить тесты
    {
    int need_test = 2;

    printf("\033[1;36mDo you want to test functions? YES - 1. NO - 0.\033[0m\n");
    scanf("%d", &need_test);
    while ((need_test != 0) && (need_test != 1))
        {
        printf("\033[1;31mYou entered an incorrect value, try again!\033[0m\n");
        while (fgetc(stdin) != '\n');
        scanf("%d", &need_test);
        }
    while(fgetc(stdin) != '\n');
    if (need_test == 1)
        {
        if (!(TestSolveSquare()))
            printf("\033[1;32mThe tests are successfull!\033[0m\n");
        }
    }

Coeffs EnterCoeffs()  // считывает коэффициенты уравнения
    {
    double a = NAN;
    double b = NAN;
    double c = NAN;

    printf("\033[1;33mEnter 3 numbers (a, b, c), that will be used as \033[0m\n");
    printf("\033[1;33mcoefficients in a quadratic equation (a * x^2 + b * x + c = 0).\033[0m\n");
    while (scanf("%lg %lg %lg", &a, &b, &c) != 3)
        {
        printf("\033[1;31mYou entered incorrect values, try again!\033[0m\n");
        while(fgetc(stdin) != '\n');
        }
    printf("\033[1;33mYour equation: %lgx^2 + %lgx + %lg = 0\033[0m\n", a, b, c);
    Coeffs group_abc = {a, b, c};
    return group_abc;
    }
