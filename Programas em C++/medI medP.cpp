#include <iostream>
using namespace std;
int main()
{
int idade, qtde, somaI;
float medP, medI, peso, somaP;
		
		qtde=0;
		peso=1.0;
		somaI=0;
		somaP=0.0;

while (peso!=0)
{
cout <<"Qual a sua idade? "; cin >> idade;
somaI+=idade;
cout <<"Qual o seu peso? "; cin >> peso;
somaP+=peso;
qtde++;
}

somaI-=idade;
qtde--;
medI=somaI/qtde;
medP=somaP/qtde;

cout <<"Entrevistados: " <<qtde <<"\n";
cout <<"Idade média: " << medI <<"\n";
cout <<"Peso médio: " << medP <<"\n";
}
