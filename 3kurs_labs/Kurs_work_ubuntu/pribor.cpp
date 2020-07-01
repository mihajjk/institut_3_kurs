#include <iostream>
#include <queue>
#include <cstdlib>
#include <csignal>
#include <unistd.h>
#include <ctime>
#include <fstream>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <cmath>

using namespace std;

queue <int> q;
int maxQ = 3;
int inQ = 0;

float midInQ = 0;
int vsegoZayavok = 0;
int obclycjili = 0;
int poteri = 0;

//добавить в очередь
void sigusr1(int sig){
        if(inQ == maxQ){
        poteri++;
        cout << "Очередь заполнена \n"; // ( ͡° ͜ʖ ͡°)
        }else{
        vsegoZayavok++;
        //sost();
                inQ++;
                srand(time(0));//автоматическая рандомизация ??
                q.push(rand()%10+5);
                cout << "add > "<<q.front()<<endl;
        }
}

void obr(){
        midInQ = (midInQ + inQ)/2;
        if(!q.empty()){
        inQ--;
                for(int i = 0;i < q.front();i++){
                        cout << i << endl;
                        sleep(1);
                        cout << "inQ : "<<inQ <<endl;
                }
                q.pop();
        }
        obclycjili++;
}

bool GO = true;
void stop(int sig){
        GO = false;
}                                                                                                                     int main(){

cout << "Введите длину очереди : ";
cin >> maxQ;
if(maxQ <= 0) return 0;

cout << "\nПрибор начал работу \n";
cout << "Мой pid - "<< getpid() <<endl;

system("pidof -s PRIBOR > tmp.txt");
 auto starT = std::chrono::steady_clock::now();
        while(GO){
                //sost();
                obr();
                signal(SIGUSR1, sigusr1);//10
                //sost();
                //kill -s PRIBOR
                signal(SIGUSR2, stop);
        }
        auto enD = std::chrono::steady_clock::now();
auto elapsed_sec = std::chrono::duration_cast<std::chrono::seconds>(enD-starT);
cout << "Time  = "<< elapsed_sec.count()<<" sec." << endl;
double time = (double)elapsed_sec.count()/60;
cout << "Time = ";
printf(" %.5f",time);
cout << " min"<<endl;

//кол-во заявок делим на минуты
        cout << "Количество обработанных заявок : " << vsegoZayavok << "(без учета потеряных)"<< endl;
        cout << "Количество потеряных заявок : " << poteri << endl;
        cout << "Кол-во обслуженых заявок : " << obclycjili <<endl;
        cout << "Средняя интенсивность входного потока: "<< (vsegoZayavok+poteri)/time << " в минуту. \n";
        cout << "Средняя интенсивность выходного потока : " << obclycjili/time << " в минуту. \n";
        cout << "Средняя длина очереди : "<< midInQ << endl;
        return 0; 
}
