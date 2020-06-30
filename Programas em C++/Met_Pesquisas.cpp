#include <iostream>
using namespace std;

bool PesquisaSequencial(int Nome_vetor[], int busca, int tamanho);
bool PesquisaBinaria(int Nome_vetor[], int busca, int tamanho);

int Numeros[5] {5, 4, 3, 2, 1};

int main() {
    int vlr_busca, cod, control;

    cout <<"Qual método de pesquisa deseja utilizar? " <<endl <<endl
    <<"1 - Pesquisa sequencial" << endl
    <<"2 - Pesquisa binaria" <<endl;

    cin >> cod;

do {
    cout <<"Qual o valor procurado? ";
    cin >> vlr_busca;

    switch (cod) {
        case 1:
        PesquisaSequencial(Numeros, vlr_busca, 5);
        cout << endl <<"Deseja realizar outra busca? \n"<<"1 - Sim\n" <<"2 - Mão\n"; cin >> control;
        break;

        case 2:
        PesquisaBinaria(Numeros, vlr_busca, 5);
        cout << endl <<"Deseja realizar outra busca? \n"<<"1 - Sim\n" <<"2 - Mão\n"; cin >> control;
        break;
        
        default:
        cout <<"Código inválido. Tente novamente.\n";
        }
    } while (control==1);
} 

bool PesquisaSequencial(int Nome_vetor[], int busca, int tamanho) {
    int ind, resultado;
    if (tamanho == 0) {
        cout << "Erro: Vetor vazio";
        return false;
    }
    for (ind = 0; ind < tamanho; ind++) {
        if (Nome_vetor[ind]== busca) {
        resultado = ind;
        cout <<"Valor " << busca << " encontrado na posicao: " << resultado <<".";
        }
    }
    return false;
}

bool PesquisaBinaria(int Nome_vetor[], int busca, int tamanho) {
        
    int inf = 0; // limite inferior
    int sup = tamanho - 1; // limite superior
    int meio, resultado;
    int i, j, menor, temp;

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

    if (tamanho == 0) {
        cout <<"Erro: vetor vazio.";
        return false;
    }

    while (inf <= sup) {
        meio = (inf + sup)/2;
        if (busca == Nome_vetor[meio]) {
            resultado = meio;
            cout <<"Valor " << busca << " encontrado na posicao: " << resultado <<".";
            return true;
        }

        else if (busca < Nome_vetor[meio])
                sup = meio -1;
        
        else 
                inf = meio + 1;
    }
    return false; // Não encontrado
}