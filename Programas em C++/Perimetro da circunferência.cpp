#include <iostream>
using namespace std;
//A tarefa da função será calcular o perímetro da circunferência. O cálculo do perímetro da circunferência é dado pela fórmula P = 2 · p · r. O raio será passado para a função como parâmetro, a função calculará e retornará o valor do perímetro da circunferência
float CalcPerimetroCircunferencia(float raio);
// Protótipo da função
int main()
{
float Per;
// Chamando a função
Per = CalcPerimetroCircunferencia(5);
cout << "O perimêtro da circunferência é: " << Per;
}

float CalcPerimetroCircunferencia(float raio)
{
  float Perimetro;
  // P = 2;pi.r
  Perimetro = 2 * 3.14 * raio;
  return Perimetro;
}