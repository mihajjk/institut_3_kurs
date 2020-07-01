/*
    Array84. Дан массив размера N. Осуществить циклический сдвиг элементов
    массива влево на одну позицию (при этом AN перейдет в AN−1, AN−1 —
    в AN−2, . . ., A1 — в AN ).
*/

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите длину массива\n";
    cin >> n;

    int *mas = new int[n]; //обьявление массива

    //заполнение массива
    for (int i(0); i < n; i++)
    {
        cout << "Введите" << i + 1 << "элемент массива : ";
        cin >> mas[i];
        //cout << endl;
    }

    for (int j(0); j < n - 1; j++)
    {
        if (j != n - 1)
        {
            mas[j] = mas[j] + mas[j + 1];    //a = a + b;
            mas[j + 1] = mas[j] - mas[j + 1];    //b = a — b;
            mas[j] = mas[j] - mas[j + 1];    //a = a — b;
        }
        else { break; }
    }

    //вывод массива
    for (int i(0); i < n; i++)
    {
        cout << mas[i];
        cout << "_" << endl;
    }

    return 0;
}
