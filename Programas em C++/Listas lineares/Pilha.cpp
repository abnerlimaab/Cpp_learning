#include <iostream>
#include "conio.h"
#include <locale.h>
#include <string.h>
using namespace std;

struct DADOS_ALUNO{
int CodAluno;
char Nome[100];
int Turma;
}; 

bool Empilhar(DADOS_ALUNO Pilha[], int CodAluno, char Nome[], int Turma, int &PosTopo);
bool ExibirTopo(DADOS_ALUNO Pilha[], int PosTopo);
bool Exibir(DADOS_ALUNO Pilha[], int PosTopo);
bool Desempilhar(int &PosTopo);

# define MAX_PILHA 5 // Tamanho Máximo da Pilha

int main() {
    DADOS_ALUNO PilhaAlunos[MAX_PILHA];// Pilha
    int PosTopo = 0; // Posição do topo
    bool Ret; // Recebe o retorno da função chamada
    int cod, control;
    int CodAluno;
    char Nome[100];
    int Turma;

    do{
    cout << "PILHA - Estrututra de dados" <<endl <<endl
    << "1 - Empilhar (Push) " <<endl
    << "2 - Exibir o topo da pilha (Stacktop)" <<endl
    << "3 - Exibir toda a pilha (Pop)" <<endl
    << "4 - Desempilhar" <<endl
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
                Ret = Empilhar(PilhaAlunos, CodAluno, Nome, Turma, PosTopo);
                if(Ret == true){cout << "Inserção efetuada com sucesso!" << endl;} 

                cout <<endl <<"Deseja realizar outra operação?" <<endl
                <<"1 - Sim" <<endl
                <<"2 - Não" <<endl;
                cin >> control;
                break;

            case 2:
                Ret = ExibirTopo(PilhaAlunos, PosTopo);
                if(Ret == false){cout << "Não foi possível exibir a pilha." << endl;} 

                cout <<endl <<"Deseja realizar outra operação?" <<endl
                <<"1 - Sim" <<endl
                <<"2 - Não" <<endl;
                cin >> control;
                break;

            case 3:
                Ret = Exibir(PilhaAlunos, PosTopo);
                if(Ret == false){cout << "Não foi possível exibir a pilha." <<endl;} 

                cout <<endl <<"Deseja realizar outra operação?" <<endl
                <<"1 - Sim" <<endl
                <<"2 - Não" <<endl;
                cin >> control;
                break;

            case 4:
                Ret = Desempilhar(PosTopo);
                if(Ret == false){cout << "Não foi possível desempilhar a pilha."<< endl;} 

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

bool Empilhar(DADOS_ALUNO Pilha[], int CodAluno, char Nome[], int Turma, int &PosTopo) {
    if (PosTopo == MAX_PILHA){
        cout << "ERRO: Pilha cheia.";
        return false;
    }
    else {
        Pilha[PosTopo].CodAluno = CodAluno;
        strcpy(Pilha[PosTopo].Nome, Nome);
        Pilha[PosTopo].Turma = Turma;
        PosTopo++;
    }
    return true; 
}

bool ExibirTopo(DADOS_ALUNO Pilha[], int PosTopo) {
    if (PosTopo == 0){
        cout << "ERRO: Pilha vazia.";
        return false;
    }
    // Exibe o elemento do TOPO da pilha
    printf("Código do Aluno \t");
    printf("Nome \t \t");
    printf("Turma \t");
    cout <<endl;

    cout << Pilha[PosTopo - 1].CodAluno; printf("\t \t \t");
    cout << Pilha[PosTopo - 1].Nome; printf("\t \t");
    cout << Pilha[PosTopo - 1].Turma; 
    cout <<endl;
    return true;
}

bool Exibir(DADOS_ALUNO Pilha[], int PosTopo) {
    int ind;
    if (PosTopo == 0){
    cout << "ERRO: Pilha vazia.";
    return false;
    }
    // Exibe do TOPO para o FUNDO
        printf("Código do Aluno \t");
        printf("Nome \t \t");
        printf("Turma \t");
        cout <<endl;
    for(ind = PosTopo - 1; ind >= 0; ind-- ){ 
        cout << Pilha[ind].CodAluno; printf("\t \t \t");
        cout << Pilha[ind].Nome; printf("\t \t");
        cout << Pilha[ind].Turma; 
        cout <<endl;
    }
    return true;
}

bool Desempilhar(int &PosTopo) {
    if (PosTopo == 0){
        cout << "ERRO: pilha vazia.";
        return false;
    }
    else {
    // Desempilha o elemento do topo
    PosTopo--;
    }
    return true; 
}