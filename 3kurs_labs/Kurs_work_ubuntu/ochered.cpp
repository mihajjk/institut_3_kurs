#include <iostream>
#include <cstdlib>
#include <csignal>
#include <unistd.h>
#include <ctime>
#include <fstream>

using namespace std;

bool GO = true;
string PID_pribora = "";

void sigusr2(int pid){
  GO = false;
}

int main(){
cout << "Мой PID : "<< getpid();
cout << "\nPID прибора : ";

while(PID_pribora == ""){
        std::ifstream in("tmp.txt");
        if(in.is_open()) getline(in,PID_pribora);
}
system("rm tmp.txt");

cout << PID_pribora <<endl;

cout << "\n чтобы остановить: kill -s SIGUSR2 <pid>"<< endl;
        while(GO){
        srand(time(0));
        sleep(rand()%3+6);
        kill(stoi(PID_pribora),10);
cout << " Заявочку отправил \n";
        signal(SIGUSR2, sigusr2);
        }
        return 0;
}
