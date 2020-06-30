#include <iostream>
#include "conio.h"
#include <locale.h>
using namespace std;

# define MAX_LISTA 10 // Tamanho máximo da lista

//Funções
bool Inserir(float Lista[], float valor, int &PosUltimoElem);
bool InserirPos(float Lista[], int PosIns, float valor, int &PosUltimoElem);
bool Exibir(float Lista[], int PosUltimoElem);
int Pesquisar(float Lista[], float valor, int &PosUltimoElem);
bool RemoverElem(float Lista[], int valor, int &PosUltimoElem);

int main() {
    float ListaNotas[MAX_LISTA]; // Lista linear sequencial
    int PosUltimoElemLista = 0; // Qtde de elementos da lista
    bool Ret; // Recebe o retorno da função chamada
    int valor, cod, control, pos;
    
do {
    cout <<"Qual operacao deseja realizar? " <<endl <<endl
    <<"1 - Inserir valor" <<endl
    <<"2 - Inserir valor em uma posicao especifica" <<endl
    <<"3 - Exibir lista" <<endl
    <<"4 - Pesquisar valor" <<endl
    <<"5 - Remover valor" <<endl
    <<endl;
    cin >> cod;

    switch (cod) {
        case 1:
        cout <<"Digite o valor para insercao: ";
        cin >> valor;
        Ret = Inserir(ListaNotas, valor, PosUltimoElemLista); 
        if (Ret == true) {
            cout <<"Insercao efetuada com sucesso!" <<endl <<endl;
        }
        cout <<"Deseja realizar outra operacao? " <<endl <<endl
        <<"1 - Sim" <<endl
        <<"2 - Nao" <<endl <<endl;
        cin >> control;
        break;

        case 2:
        cout <<"Digite o valor para insercao: ";
        cin >> valor;
        cout <<"Digite a posicao para insercao: ";
        cin >> pos;
        Ret = InserirPos(ListaNotas, pos, valor, PosUltimoElemLista);
        if (Ret == true) {
            cout <<"Insercao efetuada com sucesso!" <<endl <<endl;
        }
        cout <<"Deseja realizar outra operacao? " <<endl <<endl
        <<"1 - Sim" <<endl
        <<"2 - Nao" <<endl <<endl;
        cin >> control;
        break;

        case 3:
        Ret = Exibir(ListaNotas, PosUltimoElemLista);
        if (Ret == false) {
            cout <<"Não foi possivel exobor a lista." <<endl;
        }
        cout <<"Deseja realizar outra operacao? " <<endl <<endl
        <<"1 - Sim" <<endl
        <<"2 - Nao" <<endl <<endl;
        cin >> control;
        break;

        case 4:
        cout <<"Digite o valor da pesquisa: ";
        cin >> valor;
        pos = Pesquisar(ListaNotas, valor, PosUltimoElemLista);
        if (pos == -1) {
            cout <<"Valor nao encontrado." <<endl;
        }
        else {
        cout <<"O valor foi encontrado na posicao: " <<pos <<endl <<endl;}
        cout <<"Deseja realizar outra operacao? " <<endl <<endl
        <<"1 - Sim" <<endl
        <<"2 - Nao" <<endl <<endl;
        cin >> control;
        break;

        case 5:
        cout <<"Digite o valor para remocao: "; cin >> valor;
        Ret = RemoverElem(ListaNotas, valor, PosUltimoElemLista);
        if (Ret == true) {
            cout <<"Remocao efetuada com sucesso!" <<endl;
        }
        cout <<"Deseja realizar outra operacao? " <<endl <<endl
        <<"1 - Sim" <<endl
        <<"2 - Nao" <<endl <<endl;
        cin >> control;
        break;

        default:
        cout <<endl;
    }    
} while (control == 1);
cout <<"\n" <<"Finalizado";    
}

bool Inserir(float Lista[], float valor, int &PosUltimoElem) {

    if (PosUltimoElem == MAX_LISTA) {
        cout <<"ERRO: Lista cheia";
        return false;
    }

    else {
        Lista[PosUltimoElem] = valor;
        PosUltimoElem++;
    }

    return true;
}

bool InserirPos(float Lista[], int PosIns, float valor, int &PosUltimoElem) {
    int ind;

    if (PosUltimoElem == MAX_LISTA) {
        cout <<"ERRO: Lista cheia.";
        return false;
    }
    else {
        for(ind = PosUltimoElem + 1; ind > PosIns; ind--) {
            Lista[ind] = Lista[ind - 1];
        }
        Lista[PosIns] = valor;
        PosUltimoElem++;
    }
    return true;
}

bool Exibir(float Lista[], int PosUltimoElem) {
    int ind;

    if (PosUltimoElem == 0) {
        cout <<"ERRO: Lista vazia.";
        return false;
    }

    for (ind = 0; ind < PosUltimoElem; ind++) {
        cout <<"Nota " <<ind <<": " <<Lista[ind] <<endl;
    }
    return true;
}

int Pesquisar(float Lista[], float valor, int &PosUltimoElem) {
    int ind;
    for(ind = 0; ind < PosUltimoElem; ind++) {
        if (Lista[ind] == valor) {
            return ind;
        }
    }
    return -1;
}

bool RemoverElem(float Lista[], int valor, int &PosUltimoElem) {
    int ind;
    int PosRem;

    if (PosUltimoElem == 0) {
        cout <<"ERRO: Lista vazia.";
        return false;
    }
    PosRem = Pesquisar(Lista, valor, PosUltimoElem);
    for (ind = PosRem; ind < PosUltimoElem; ind++) {
        Lista[ind] = Lista[ind + 1];
    }
    PosUltimoElem--;
    return true;
}