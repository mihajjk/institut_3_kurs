/*

  ! НЕ ИСПОЛЬЗОВАТЬ ОПЕРАТОРЫ ЦИКЛА

    Синтаксическйий анализатор

    на ввод : M(52,66)
    вывод : 66

    на ввод : m(12, 5)
    вывод : 5
*/
#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int Min(int a, int b) {
    if (a > b) return b;
    else return a;
}

int Max(int a, int b) {
    if (a < b) return b;
    else return a;
}

void sravnenie(string str, int a, int b) {
    int G = (int)str[0];
    //Проверка ASCII кода
    //cout << G;
    if ( G == 77)
    {
        cout << "Максимальный : "<< Max(a, b);
    }
    else
    {
        cout << "Минимальный : "<< Min(a, b);
    }
}

string func(string str, int i) {
    string resq = "";
    resq += str[i];

    if (str[i+1] == ')' || str[i+1] == ',')
    {
        return resq;
    }
    else {
        i++;
        resq += func(str, i);
    }

    return resq;
}


int main()
{
    setlocale(LC_ALL, "");
    //int num(0);
    string str;

    cout << "Введите строку : ";
    cin >> str;
    cout << endl;

    int a =  stoi (func(str,2));
    //cout << a;
    int b =  stoi (func(str, log10(a) + 4));
    //cout << b;

    sravnenie(str, a, b);
}
