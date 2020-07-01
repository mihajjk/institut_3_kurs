/*
        Якомазов М.С. 17ВИ1
        String60   (41+19)

    Дана строка, содержащая полное имя файла.
    Выделить из названия этой строки название первого каталога (без символа "\").
    Если файл содержится в корневом каталоге, то вывести символ "\".

    Примеры:


        При вводе : "C:\Users\jacicAca\Documents\SQL.exe"
        Ответ : "Documents"

        При вводе : "C:\SQLServer2017Media"
        Ответ : "\"

*/

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

void search(string str) {
    int right = str.rfind('\\');
    //cout << right;//для проверки включать

    int left = str.rfind('\\', right-1);
    //cout << left;

    if (left == -1)
    {
        cout << "\\";
    }
    else
    {
        cout << "Первый каталог :  ";
        for (int i = left+1; i < right; i++)
        {
            cout << str[i];
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    string str;
    cout << "Введите путь файла > ";
    cin >> str;
    cout << endl;

    search(str);
}
