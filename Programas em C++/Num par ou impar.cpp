#include <iostream>
using namespace std;
int main()
{
int num;

cout <<"Informe um número qualquer: "; cin >> num;

while (num!=-1)
{
  if (num%2==0)
  {
    cout <<"Este número é par!\n";
  }
  else
  {
    cout <<"Este número é impar!\n";
  }
  cout <<"Informe um número qualquer: "; cin >> num;

}
}
