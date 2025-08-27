#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Tests.cpp"
#include "Solvers.cpp"
#include "InOutPut.cpp"


int main() //������� �������
    {
    double x1 = 0.0;
    double x2 = 0.0;
    int count_x = 0;

    NeedTest();//����� �������, ������� ���������� ������������, ����� �� ��������� �����
    Coeffs group_abc = EnterCoeffs();//����� �������, ������� ����������� � ������������ ������������ ���������

    count_x = CommonSolver(group_abc.a, group_abc.b, group_abc.c, &x1, &x2);  //����� �������, ������� ���������� ���-�� ������ ���������
    OutPutRoots(count_x, x1, x2); //����� �������, ������� �������� ����� ���������
    return 0;
    }




