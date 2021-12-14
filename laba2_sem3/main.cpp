#include "Vector.h"
#include "matrix.h"
#include <iostream>
int main()
{
    TMatrix<int> a(5), b(5), c(5);
    int i, j;
    TMatrix<int> mat1(5);

    for (int i = 0; i < 5; i++)
        for (int j = i; j < 5; j++)
            mat1[i][j] = i * 5 + j;

    setlocale(LC_ALL, "Russian");
    cout << "Тестирование программ поддержки треугольных матриц" << endl;
    for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++)
        {
            a[i][j] = i * 10 + j;
            b[i][j] = (i * 10 + j) * 100;
        }
    c = a + b;
    cout << "Matrix a = " << endl << a << endl;
    cout << "Matrix b = " << endl << b << endl;
    cout << "Matrix F =." << endl << mat1 << endl;
    cout << "Matrix c = a + b" << endl << c << endl;
    cout << "Matrix c = F - F" << endl << mat1 - mat1 << endl;
    cout << "Matrix c = F * F" << endl << mat1 * mat1 << endl;



    cout << endl;
    system("pause");
    return 0;
}