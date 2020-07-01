/*

            Dynamic20. Даны указатели P1 и P2 на начало и конец непустой очереди. Извлекать
        из очереди элементы, пока значение начального элемента очереди
        не станет четным, и выводить значения извлеченных элементов (если очередь
        не содержит элементов с четными значениями, то извлечь все ее элементы).
        Вывести также новые адреса начала и конца очереди (для пустой
        очереди дважды вывести NIL). После извлечения элементов из очереди
        освобождать память, которую они занимали.
*/
 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
* Элемент односвязного списка
*/
struct Node
{
    int value;
    Node *next;

    Node(int val)
    {
        value = val;
        next = 0;
    }
};

void InitQueue(int D, Node *&p1, Node *&p2)
{
    p1 = new Node(D);
    p2 = p1;
}

void Enqueue(int D, Node *&p2)
{
    Node *newNode = new Node(D);
    p2->next = newNode;
    p2 = newNode;
}

int Dequeue(Node *&p1)
{
    int result = p1->value;
    Node *temp = p1;
    p1 = p1->next;
    delete temp;
    return result;
}

int main()
{
    Node *p1 = 0;
    Node *p2 = p1;

    cout << p1 << ' ' << p2 << endl;

    InitQueue(1, p1, p2);
    cout << p1 << ' ' << p2 << endl;


    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        Enqueue(rand() % 100, p2);
    }

    // После ввода
    cout << p1 << ' ' << p2 << endl;

    while(p1 != NULL)
    {
        int t = Dequeue(p1);
        cout << t << '\t';
        if(t % 2 == 0) break;
    }

    cout << endl << p1 << ' ' << p2 << endl;

    return 0;
}
