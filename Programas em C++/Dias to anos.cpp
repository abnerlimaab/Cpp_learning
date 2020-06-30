#include <iostream>
using namespace std;
int main()
{
  // Receba a quantidade de dias que uma pessoa já viveu e informe quantos anos ela tem. Desconsidere os anos bissextos.
  int dias, anos;
  cout <<"Quantos dias você já viveu? ";
  cin >> dias;
  anos=dias/365;
  cout <<"Você já viveu " <<anos <<" anos!";
}