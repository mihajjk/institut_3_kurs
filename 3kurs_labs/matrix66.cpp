/* Matrix_66.cpp
    Matrix66. Дана матрица размера M × N.
    Удалить ее последний столбец, содержащий только отрицательные элементы
*/

#include "pch.h"
#include <iostream>
#include <ctime>
#include<iomanip>

using namespace std;

void fullArray(int rows, int columns, int **arr) {
    //заполнение
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = rand() % 21 - 10;
        }
    }
}

//здесь endColumns столбец который не выводить если -1 то все выводить
void printArray(int rows, int columns, int **arr, int endColumn) {
    cout << endl;
    for (int i = 0; i < columns; i++)
    {
        if (i == endColumn)
        {
            continue;
        }
        cout << setw(4) << i + 1 ;
    }    cout << endl;

    //вывод без последнего столбца с отрицательными элементами
    //
    if (endColumn != -1)
    {
        cout << " Столбец с отрицательными элементами : " << endColumn + 1 << endl;
    }

        for (int i(0); i < rows; i++)
        {
            for (int j(0); j < columns; j++)
            {
                if (j != endColumn)
                {
                    cout << setw(4) << arr[i][j];
                }
            }
            cout << endl;
        }
}

int endColumn(int row, int col, int **arr) {
//   номер столбца с отрицательными элементамиесли такого столбца нет >>  -1 -по дефолту
    int endColumn(-1);
    //ноходим столбец с отрицательными элементами
    bool flag(true);
    int i(0), j(0);
    for (j; j < col; j++)
    {
        flag = (true);
        for (i = 0; i < row; i++)
        {
            if (arr[i][j] > 0)    //если в столбце есть хоть 1 элемент > 0
            {
                flag = false;
            }
        }
        if (flag == true)
        {
            endColumn = j;
        }
    }
    return endColumn;
}

int main()
{
    setlocale(LC_ALL, "");
    srand(time(0));

    int row(0);
    int col(0);
    cout << "Введите количество строк "; cin >> row;
    cout << "Введите количество столбцов"; cin >> col;

    int **p = new int*[row]; //создание строк
    for (int i = 0; i < row; i++) {
        p[i] = new int[col];
    }

    int end(-2);
    fullArray(row,col,p);
    printArray(row,col,p,end);

    end = endColumn(row,col,p); //хранит номер столбца с отрицательными элементами
    printArray(row, col, p, end);

    //освобождаем память
    for (int i = 0; i < row; i++)
    {
        delete[]p[i];
    }delete[]p;
}
