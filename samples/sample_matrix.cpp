// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include <ctime>
#include "tmatrix.h"
#include <time.h>
//---------------------------------------------------------------------------
using namespace std;
void main()
{
    int i, j, f, k, v, s, m1;
    clock_t start, end;
    clock_t start1, end1;

    setlocale(LC_ALL, "Russian");
    cout << "Тестирование" << endl;
    srand(time(NULL));
    cout << "Вектор" << endl;
    cout << "Введите размер вектора" << endl;
    cin >> v;
    TDynamicVector<int> a1(v), b1(v), c1(v), d1(v);
    cout << "1. Рандомное заполнение вектора" << endl;
    cout << "2. Готовое заполнение вектора" << endl;
    cout << "3. Заполнение вектора вручную" << endl;
    cout << "Выберите номер: ";
    cin >> s;
    switch (s) {
    case 1:
        for (j = 0; j < v; j++)
        {
            a1[j] = rand() % 10;
            b1[j] = rand() % 100;
        }
        break;
    case 2:
        for (i = 0; i < v; i++) {
            a1[i] = i * 10;
            b1[i] = i * 100;
        }
        break;
    case 3:
        cin >> a1;
        cin >> b1;
        break;
    default:
        break;
    }
    c1 = a1 + b1;
    d1 = a1 - b1;
    m1 = a1 * b1;
    cout << "Vector a1 = " << a1 << endl;
    cout << "Vector b1 = " << b1 << endl;
    cout << "Vector c1 = a1 + b1" << endl << c1 << endl;
    cout << "Vector d1 = a1 - b1" << endl << d1 << endl;
    cout << "m1 = a1 * b1" << endl << m1 << endl;


    cout << "Матрица" << endl;
    cout << "Введите размер матрицы" << endl;
    cin >> k;
    TDynamicMatrix<int> a(k), b(k), c(k), d(k), m(k);

    cout << "1. Рандомное заполнение матриц" << endl;
    cout << "2. Готовое заполнение матриц" << endl;
    cout << "3. Заполнение матриц вручную" << endl;
    cout << "Выберите номер: ";
    cin >> f;
    switch (f) {
    case 1:

        for (i = 0; i < k; i++)
            for (j = i; j < k; j++)
            {
                a[i][j] = rand() % 10;
                b[i][j] = rand() % 100;
            }
        break;
    case 2:

        for (i = 0; i < k; i++)
            for (j = i; j < k; j++)
            {
                a[i][j] = i * 10 + j;
                b[i][j] = (i * 10 + j) * 100;
            }
        break;
    case 3:
        for (i = 0; i < k; i++)
            for (j = i; j < k; j++)
            {
                cin >> a[i][j];
            }
        for (i = 0; i < k; i++)
            for (j = i; j < k; j++)
            {
                cin >> b[i][j];
            }
        break;

    default:
        break;
    }
    c = a + b;
    d = a - b;
    m = a * b;


    cout << "Matrix a = " << endl << a << endl;
    cout << "Matrix b = " << endl << b << endl;
    cout << "Matrix c = a + b" << endl << c << endl;
    cout << "Matrix d = a - b" << endl << d << endl;
    cout << "Matrix m = a * b" << endl << m << endl;

}
//---------------------------------------------------------------------------