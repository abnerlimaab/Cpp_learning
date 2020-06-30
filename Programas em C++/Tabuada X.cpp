#include <iostream>
using namespace std;
int main()
{
int num, contador, res;
contador=0;

cout <<"Você deseja ver a tabuada de qual número? "; cin >>num;

while (contador<=10)
{
  res=num*contador;
  cout <<num <<" X " <<contador <<" = " <<res <<"\n";
  contador++;
}
}
