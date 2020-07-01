/*
    Якомазов М.С.
    Вариант19 File20

            File20. Дан файл вещественных чисел. Найти общее количество его локальных
        экстремумов, то есть локальных минимумов и локальных максимумов
        (определения локального минимума и локального максимума даны в
        заданиях File18 и File19).

*/

//#include "stdafx.h"
#include "pch.h"
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int N = 0;

//
double calculateExtremumi(double *arr, int n) {
    double result = 0;
    cout << "Цифр - "<< N << endl;
    if (arr[0] > arr[1] || arr[0] < arr[1]) {
        result++;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) {
            result++;//максимумы
            cout <<" "<< arr[i]<<" ";
        }
        if (arr[i] < arr[i + 1] && arr[i] < arr[i - 1]) {
            result++;//минимумы
            cout << " " << arr[i] << " ";
        }
    }
    cout << endl;
    return --result;
}

void fill_array(double *arrays, int n) {
    ifstream file;
    file.open("input.txt");
    for (int i = 0; i < n; i++)
    {
        file >> arrays[i];
    }
    file.close();
}
void find_count() {
    ifstream file;
    file.open("input.txt");
    int counter = 0;
    string num;
    while (!file.eof()) {
        file >> num;
        counter++;
    }
    N = counter;
    file.close();
}
int main()
{
    setlocale(LC_ALL, "");
    find_count();
    double *array_nums = new double[N];
    fill_array(array_nums, N);
    int result = calculateExtremumi(array_nums, N);
    cout << "Ответ  = " << result;
    delete[] array_nums;
    system("pause");
    return 0;
}
