#include <iostream> 
#include "conio.h"
#include <locale.h>
#include <string.h>
using namespace std; 
 
int main(){ 
 
 // SEÇÃO 1: Declaração de variáveis  
 char Tipo;  //M: Masculino   F: Feminino  
 int Idade; 	
 float	Preco;	
 
 // SEÇÃO 2: Atribuição de valores  
 Tipo = 'M';  
 Idade = 30; 	
 Preco	=	145.50;	

cout << "Valor de Idade: " << Idade << endl; 
cout << "Endereço de Idade: " << &Idade << endl;  

cout << "Valor de Preço:	"	<<	Preco	<<	endl;
cout << "Endereço de Preço:	"	<<	&Preco	<<	endl;
 
 system("pause > null"); }