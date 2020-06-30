#include <iostream>
using namespace std;
int main()
{
// Declarações
int cod, qtde, control;
float valPg, valTot;
const char * n100="Hamburguer", * n101="Cachorro Quente", * n102="Milk-shake", * n103="Pizza Brotinho", * n104="Cheeseburguer";
const float v100=5.50, v101=4.50, v102=7.00, v103=8.00, v104=8.50;
valTot=0;

// Cardápio
cout <<"\n\n---CARDÁPIO---\n\n";
cout <<"100 - Hambúrguer - R$5,50\n";
cout <<"101 - Cachorro-quente - R$ 4,50\n";
cout <<"102 - Milk-shake - R$ 7,00\n";
cout <<"103 - Pizza brotinho - R$ 8,00\n";
cout <<"104 - Cheeseburguer - R$ 8,50\n\n";
cout <<"----------------------\n\n";

do
{
  cout <<"\n" <<"Informe o código do pedido: "; cin >> cod;
  cout <<"Informe a quantidade: "; cin >> qtde;
  cout <<"\n\n";

  switch (cod)
  {
    case 100:
    valPg=qtde*v100;
    valTot+=valPg;
    cout <<"Você adicionou " <<n100 <<"\n";
    cout <<"Quantidade: " <<qtde <<"\n";
    cout <<"Valor do pedido: R$ " <<valPg <<"\n";
    if (valPg!=valTot)
    {
      cout <<"Valor Total: R$ " <<valTot <<"\n";
      cout <<"Deseja adicionar outro pedido? \n"<<"1 - Sim\n" <<"2 - Mão\n"; cin >> control;
    }
    else
    {
      cout <<"Deseja adicionar outro pedido? \n"<<"1 - Sim\n" <<"2 - Mão\n"; cin >> control;
    } break;

    case 101:
    valPg=qtde*v101;
    valTot+=valPg;
    cout <<"Você adicionou " <<n101 <<"\n";
    cout <<"Quantidade: " <<qtde <<"\n";
    cout <<"Valor do pedido: R$ " <<valPg <<"\n";
    if (valPg!=valTot)
    {
      cout <<"Valor Total: R$ " <<valTot <<"\n";
      cout <<"Deseja adicionar outro pedido? \n"<<"1 - Sim\n" <<"2 - Mão\n"; cin >> control;
    }
    else
    {
      cout <<"Deseja adicionar outro pedido? \n"<<"1 - Sim\n" <<"2 - Mão\n"; cin >> control;
    } break;

    case 102:
    valPg=qtde*v102;
    valTot+=valPg;
    cout <<"Você adicionou " <<n102 <<"\n";
    cout <<"Quantidade: " <<qtde <<"\n";
    cout <<"Valor do pedido: R$ " <<valPg <<"\n";
    if (valPg!=valTot)
    {
      cout <<"Valor Total: R$ " <<valTot <<"\n";
      cout <<"Deseja adicionar outro pedido? \n"<<"1 - Sim\n" <<"2 - Mão\n"; cin >> control;
    }
    else
    {
      cout <<"Deseja adicionar outro pedido? \n"<<"1 - Sim\n" <<"2 - Mão\n"; cin >> control;
    } break;

    case 103:
    valPg=qtde*v103;
    valTot+=valPg;
    cout <<"Você adicionou " <<n103 <<"\n";
    cout <<"Quantidade: " <<qtde <<"\n";
    cout <<"Valor do pedido: R$ " <<valPg <<"\n";
    if (valPg!=valTot)
    {
      cout <<"Valor Total: R$ " <<valTot <<"\n";
      cout <<"Deseja adicionar outro pedido? \n"<<"1 - Sim\n" <<"2 - Mão\n"; cin >> control;
    }
    else
    {
      cout <<"Deseja adicionar outro pedido? \n"<<"1 - Sim\n" <<"2 - Mão\n"; cin >> control;
    } break;

    case 104:
    valPg=qtde*v104;
    valTot+=valPg;
    cout <<"Você adicionou " <<n104 <<"\n";
    cout <<"Quantidade: " <<qtde <<"\n";
    cout <<"Valor do pedido: R$ " <<valPg <<"\n";
    if (valPg!=valTot)
    {
      cout <<"Valor Total: R$ " <<valTot <<"\n";
      cout <<"Deseja adicionar outro pedido? \n"<<"1 - Sim\n" <<"2 - Mão\n"; cin >> control;
    }
    else
    {
      cout <<"Deseja adicionar outro pedido? \n"<<"1 - Sim\n" <<"2 - Mão\n"; cin >> control;
    } break;
  default:
  cout <<"Código inválido. Tente novamente.\n";
  }
} while (control==1);
cout <<"\n" <<"Pedido encerrado";
}
