#include <iostream>
#include "conio.h"
#include <locale.h>
#include <string.h>
using namespace std;

# define MAX_FILA 5 // Tamanho Máximo da Pilha

struct DADOS_ALUNO{
int CodAluno;
char Nome[100];
int Turma;
}; 

bool Enfileirar(DADOS_ALUNO Fila[], int CodAluno, char Nome[], int Turma, int &FimFila);
bool ExibirPrimeiro(DADOS_ALUNO Fila[], int IniFila, int FimFila);
bool Desenfileirar(DADOS_ALUNO Fila[], int &PosTopo);

int main() {
    DADOS_ALUNO FilaAlunos[MAX_FILA]; // Fila
    int IniFila= 0; // Inicio da fila
    int FimFila = 0; // Fim da fila
    bool Ret; // Recebe o retorno da função chamada
    int cod, control;
    int CodAluno;
    char Nome[100];
    int Turma;

    do{
    cout << "FILA - Estrututra de dados" <<endl <<endl
    << "1 - Enfileirar um elemento " <<endl
    << "2 - Exibir o primeiro elemento da fila" <<endl
    << "3 - Desenfileirar um elemento" <<endl
    <<endl;

    cin >> cod;

        switch (cod)
        {
            case 1:
                cout << "Digite o código do aluno: ";
                cin >> CodAluno;
                cout << "Digite o nome do aluno: ";
                cin >> Nome;
                cout << "Digite a turma: ";
                cin >> Turma;
                Ret = Enfileirar(FilaAlunos, CodAluno, Nome, Turma, FimFila);
                if(Ret == true){cout << "Inserção efetuada com sucesso!" << endl;}

                cout <<endl <<"Deseja realizar outra operação?" <<endl
                <<"1 - Sim" <<endl
                <<"2 - Não" <<endl;
                cin >> control;
                break;

            case 2:
                Ret = ExibirPrimeiro(FilaAlunos, IniFila, FimFila);
                if(Ret == false){cout << "Não foi possível exibir a fila." << endl;}

                cout <<endl <<"Deseja realizar outra operação?" <<endl
                <<"1 - Sim" <<endl
                <<"2 - Não" <<endl;
                cin >> control;
                break;

            case 3:
                Ret = Desenfileirar(FilaAlunos, FimFila);
                if(Ret == false){cout << "Não foi possível desenfileirar a fila." <<
                endl;}

                cout <<endl <<"Deseja realizar outra operação?" <<endl
                <<"1 - Sim" <<endl
                <<"2 - Não" <<endl;
                cin >> control;
                break;

            default:
                 break;
        }
    }while (control == 1);
}

bool Enfileirar(DADOS_ALUNO Fila[], int CodAluno, char Nome[], int Turma, int &FimFila) {
    if (FimFila == MAX_FILA){
        cout << "ERRO: Fila cheia.";
        return false;
        }
    else {
        Fila[FimFila].CodAluno = CodAluno;
        strcpy(Fila[FimFila].Nome, Nome);
        Fila[FimFila].Turma = Turma;
        FimFila++;
        }
    return true; 
}

bool ExibirPrimeiro(DADOS_ALUNO Fila[], int IniFila, int FimFila) {
    if (FimFila == 0){
        cout << "ERRO: Fila vazia.";
        return false;
    } 
    // Exibe o elemento do TOPO da pilha
    printf("Código do Aluno \t");
    printf("Nome \t \t");
    printf("Turma \t");
    cout <<endl;

    cout << Fila[IniFila].CodAluno; printf("\t \t \t");
    cout << Fila[IniFila].Nome; printf("\t \t");
    cout << Fila[IniFila].Turma; 
    cout <<endl;
    return true;
}

bool Desenfileirar(DADOS_ALUNO Fila[], int &PosTopo) {
    int ind;
    if (PosTopo == 0){
        cout << "ERRO: Lista vazia.";
        return false;
    }
    // Desloca a pilha sobrepondo o primeiro elemento
    for(ind = 0; ind < PosTopo; ind++ ){
        Fila[ind] = Fila[ind+1];
    }
    PosTopo--;
    return true; 
}