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
bool Removido; // Indica se o elemento foi removido
}; 

bool Enfileirar(DADOS_ALUNO Fila[], int CodAluno, char Nome[], int Turma, int &FimFila, int &TotalFila);
bool Exibir(DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila);
bool Desenfileirar(DADOS_ALUNO Fila[], int &IniFila, int &TotalFila);

int main() {
    DADOS_ALUNO FilaAlunos[MAX_FILA]; // Fila
    int IniFila = 0; // Inicio da fila
    int TotalFila = 0; // Totla de elementos da fila
    int FimFila = 0; // Fim da fila
    bool Ret; // Recebe o retorno da função chamada
    int CodAluno;
    char Nome[100];
    int Turma;
    bool Removido;
    int cod, control;

    do{
    cout << "Fila Circular - Estrututra de dados" <<endl <<endl
    << "1 - Enfileirar um elemento " <<endl
    << "2 - Exibir" <<endl
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
                Ret = Enfileirar(FilaAlunos, CodAluno, Nome, Turma, FimFila, TotalFila);
                if(Ret == true){cout << "Inserção efetuada com sucesso!" << endl;} 

                cout <<endl <<"Deseja realizar outra operação?" <<endl
                <<"1 - Sim" <<endl
                <<"2 - Não" <<endl;
                cin >> control;
                break;

            case 2:
                Ret = Exibir(FilaAlunos, IniFila, FimFila, TotalFila);
                if(Ret == false){cout << "Não foi possível exibir a fila." << endl;} 

                cout <<endl <<"Deseja realizar outra operação?" <<endl
                <<"1 - Sim" <<endl
                <<"2 - Não" <<endl;
                cin >> control;
                break;

            case 3:
                Ret = Desenfileirar(FilaAlunos, IniFila, TotalFila);
                if(Ret == false){cout << "Não foi possível desenfileirar a fila." <<endl;}

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

bool Enfileirar(DADOS_ALUNO Fila[], int CodAluno, char Nome[], int Turma, int &FimFila, int &TotalFila) {
    if (TotalFila == MAX_FILA){
        cout << "ERRO: Fila cheia.";
        return false;
    }
    else {
        Fila[FimFila].CodAluno = CodAluno;
        strcpy(Fila[FimFila].Nome, Nome);
        Fila[FimFila].Turma = Turma;
        Fila[FimFila].Removido = false;
        FimFila++;
    // Se chegou no fim da fila, então o próximo
    // elemento a ser inserido será no inicio da fila
    if (FimFila == MAX_FILA) {
        FimFila = 0;
        }   
    }
    TotalFila++;
    return true; 
}

bool Exibir(DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila) {
    int ind;
    if (TotalFila == 0){
        cout << "ERRO: Pilha vazia.";
        return false;
    }
    if (IniFila < FimFila){
        printf("Código do Aluno \t");
        printf("Nome \t \t");
        printf("Turma \t");
        cout <<endl;
        for(ind = IniFila; ind < FimFila; ind++ ){ 
            cout << Fila[ind].CodAluno; printf("\t \t \t");
            cout << Fila[ind].Nome; printf("\t \t");
            cout << Fila[ind].Turma; 
            cout <<endl;
        }
    }
    else {
        printf("Código do Aluno \t");
        printf("Nome \t \t");
        printf("Turma \t");
        cout <<endl;
        for(ind = IniFila; ind < MAX_FILA; ind++ ){
            if (Fila[ind].Removido == false){ 
                cout << Fila[ind].CodAluno; printf("\t \t \t");
                cout << Fila[ind].Nome; printf("\t \t");
                cout << Fila[ind].Turma; 
                cout <<endl;
            }
        }
        for(ind = 0; ind < FimFila; ind++ ){
            if (Fila[ind].Removido == false){
                cout << Fila[ind].CodAluno; printf("\t \t \t");
                cout << Fila[ind].Nome; printf("\t \t");
                cout << Fila[ind].Turma; 
                cout <<endl;
            }
        }
    }
    return true; 
}

bool Desenfileirar(DADOS_ALUNO Fila[], int &IniFila, int &TotalFila) {
    int ind;
    int PosRem;
    if (TotalFila == 0){
        cout << "ERRO: Fila vazia.";
        return false;
    }
    //Indica que o elemento do início da fila foi removido
    Fila[IniFila].Removido = true;
    IniFila++;
    // Se chegou no fim da fila, então o próximo
    // elemento a ser removido será no inicio da fila
    if (IniFila == MAX_FILA) {
        IniFila = 0;
    }
    TotalFila--;
    return true; 
}