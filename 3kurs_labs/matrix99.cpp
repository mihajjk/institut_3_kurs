/*
    Matrtix99
    Якомазов М.С. 17ВИ1

        Matrix99. Дана квадратная матрица A порядка M. Повернуть ее на угол 90◦
    в положительном направлении, то есть против часовой стрелки (при этом
    элемент A1,1 перейдет в AM,1, элемент AM,1 — в AM,M и т. д.).
    Вспомогательную матрицу не использовать.
*/

#include "pch.h"
#include <iostream>
#include <set>
#include <iomanip>

using namespace std;

//функция заполнения рандомными числами
void fullArray(int side, int **arr) {
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
}

void printArray(int side ,int **arr) {
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void turt(int side, int **arr) {
    for (int i = 0; i < side/2; i++)
    {
        for (int j = 1; j < side - i - 1; j++)
        {
            int tmp = arr[i][j];
            arr[i][j] = arr[j][side - i - 1];
            arr[j][side - i - 1] = arr[side - i - 1][side - j - 1];
            arr[side - i - 1][side - j - 1] = arr[side - j - 1][i];
            arr[side - j - 1][i] = tmp;
        }
    }
}

int main(void)
{
    setlocale(LC_ALL, "");

    int side(0);
    cout << "Введите длину стороны > "; cin >> side;

    //выделяем память под матрицу
    int **arr = new int *[side];
    for (int i = 0; i < side; i++)
    {
        arr[i] = new int[side];
    }

    fullArray(side, arr);
    printArray(side, arr);
    turt(side, arr);
    printArray(side, arr);

    //освобождаем память
    for (int i = 0; i < side; i++)
    {
        delete[] arr[i];
    } delete[] arr;
}
