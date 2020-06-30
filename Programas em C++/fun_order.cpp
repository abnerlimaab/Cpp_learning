#include <iostream>
using namespace std;
bool SelectionSort(int Nome_vetor[], int tamanho);
bool InsertionSort(int Nome_vetor[], int tamanho);
bool BubbleSort(int Nome_vetor[], int tamanho);
void imprimir_vetor(int Nome_vetor[], int tamanho);


int Numeros[5] {5, 4, 3, 2, 1};

int main() 
{
}

void imprimir_vetor(int Nome_vetor[], int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
  cout <<Nome_vetor[i] <<"   ";
  }
}

bool SelectionSort(int Nome_vetor[], int tamanho) {
  int temp;
  int i, j, menor;

  if (tamanho == 0) {
    cout <<"Erro: Vetor vazio. ";
    return false;
  }

  for (i = 0; i < (tamanho - 1); i++) {
    menor = i;
    for (j = (i+1); j < tamanho; j++) {
      // Encontra a posição do menor valor no vetor
      if (Nome_vetor[j] < Nome_vetor[menor]) {
        menor = j;
      }
    }
    if (i != menor) {
      // Troca
      temp = Nome_vetor[i];
      Nome_vetor[i] = Nome_vetor[menor];
      Nome_vetor[menor] = temp;
    }
  }
      return true;
}

bool InsertionSort(int Nome_vetor[], int tamanho) {
  int temp;
  int i, j;

  if (tamanho == 0) {
    cout <<"Erro: Vetor vazio.";
    return false;
      }
      for (i = 1; i < tamanho; i++) {
        temp = Nome_vetor[i];
        j = i - 1;
        while ((j>=0) && (temp < Nome_vetor[j])) {
          Nome_vetor[j+1] = Nome_vetor[j];
          j--;
        }
        Nome_vetor[j+1] = temp;
      }
      return true;
}

bool BubbleSort(int Nome_vetor[], int tamanho) {
  int temp;
  int i, j;

  if (tamanho == 0) {
    cout << "ERRO: Vetor vazio. ";
    return false;
  }

  for(j = tamanho - 1; j>=1; j--) {
    for(i = 0; i < j; i++) {
      if (Nome_vetor[i] > Nome_vetor[i + 1]) {
        temp = Nome_vetor[i];
        Nome_vetor[i] = Nome_vetor[i + 1];
        Nome_vetor[i + 1] = temp;
      }
    }
  }
  return false;
}