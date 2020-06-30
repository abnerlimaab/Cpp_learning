#include <iostream>
using namespace std;
int main()
{
  // // Sabendo que o dono de uma loja aplica 20% sobre o valor de compra de um produto, informe o valor sugerido para venda com base no valor pago na compra do produto.;
  float valCompra, valVenda;
  const float porcentagem=1.20;
  cout <<"Informe o valor de compra do produto ";
  cin >> valCompra;
  valVenda=valCompra*porcentagem;
  cout <<"O produto deve ser vendido por: R$ " <<valVenda;
}