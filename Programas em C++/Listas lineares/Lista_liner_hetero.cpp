#include <iostream>
#include "conio.h"
#include <locale.h>
#include <string.h>
using namespace std;

# define MAX_LISTA 5 // Tamanho Máximo da Lista Linear Sequencial

struct DADOS_ALUNO{
int CodAluno;
char Nome[100];
int Turma;
};

bool Inserir(DADOS_ALUNO Lista[], int CodAluno, char Nome[], int Turma, int &PosUltimoElem);
bool InserirPos(DADOS_ALUNO Lista[], int PosIns, int CodAluno,  char Nome[], int Turma, int &PosUltimoElem);
bool Exibir(DADOS_ALUNO Lista[], int PosUltimoElem);
int Pesquisar(DADOS_ALUNO Lista[], int CodAluno, int &PosUltimoElem);
bool RemoverElem(DADOS_ALUNO Lista[], int CodAluno, int &PosUltimoElem);

int main(){
DADOS_ALUNO ListaDeAlunos[MAX_LISTA]; // Lista Linear
int PosUltimoElemLista = 0; // Qtde de elementos da lista
bool Ret; // Recebe o retorno da função chamada
int cod, control;
int Turma, CodAluno, pos;
char Nome[100];

do{
cout << "Lista linear com estruturas heterogenias" <<endl <<endl
<< "1 - Inserir Aluno" <<endl
<< "2 - Inserir Aluno em posição especifica" <<endl
<< "3 - Exibir lista" <<endl
<< "4 - Pesquisar Aluno" <<endl
<< "5 - Remover Aluno" <<endl
<<endl;

cin >> cod;

switch (cod)
{
case 1: // 1 - Inserir elemento
    cout << "Digite o código do aluno: ";
    cin >> CodAluno;
    cout << "Digite o nome do aluno: ";
    cin >> Nome;
    cout << "Digite a turma: ";
    cin >> Turma; 

    Ret = Inserir(ListaDeAlunos, CodAluno, Nome, Turma,
    PosUltimoElemLista);
    if(Ret == true){cout << "Inserção efetuada com sucesso!" << endl;} 

    cout <<endl <<"Deseja realizar outra operação?" <<endl
    <<"1 - Sim" <<endl
    <<"2 - Não" <<endl;
    cin >> control;
    break;

case 2: // 2 - Inserir elemento em posição especifica
    cout << "Inserção: " << endl;
    cout << "Digite o código do aluno: ";
    cin >> CodAluno; 
    cout << "Digite o nome do aluno: ";
    cin >> Nome;
    cout << "Digite a turma: ";
    cin >> Turma;
    cout << "Digite o posição para inserção: ";
    cin >> pos;
    Ret = InserirPos(ListaDeAlunos, pos, CodAluno, Nome, Turma,
    PosUltimoElemLista);
    if(Ret == true){cout << "Inserção efetuada com sucesso!" << endl;} 
    
    cout <<endl <<"Deseja realizar outra operação?" <<endl
    <<"1 - Sim" <<endl
    <<"2 - Não" <<endl;
    cin >> control;
    break;

case 3: // 3 - Exibir
    Ret = Exibir(ListaDeAlunos, PosUltimoElemLista);
    if(Ret == false){cout << "Não foi possível exibir a lista." << endl;}

    cout <<endl <<"Deseja realizar outra operação?" <<endl
    <<"1 - Sim" <<endl
    <<"2 - Não" <<endl;
    cin >> control;
    break;

case 4: // Pesquisar
    cout << "Digite o código do aluno: ";
    cin >> CodAluno;
    pos = Pesquisar(ListaDeAlunos, CodAluno, PosUltimoElemLista);
    cout <<"Aluno encontrado na posição: " << pos <<" do vetor." <<endl <<endl;
    printf("Código do Aluno \t");
    printf("Nome \t \t");
    printf("Turma \t");
    cout <<endl;
    cout << ListaDeAlunos[pos].CodAluno; printf("\t \t \t");
    printf(ListaDeAlunos[pos].Nome); printf("\t \t");
    cout << (ListaDeAlunos[pos].Turma);  
    cout <<endl;

    cout <<endl <<"Deseja realizar outra operação?" <<endl
    <<"1 - Sim" <<endl
    <<"2 - Não" <<endl;
    cin >> control;
    break;

case 5: // Remover Aluno
    cout << "Digite o código do aluno para remoção: ";
    cin >> CodAluno;
    Ret = RemoverElem(ListaDeAlunos, CodAluno, PosUltimoElemLista);
    if(Ret == true){cout << "Remoção efetuada com sucesso!" << endl;}

    cout <<endl <<"Deseja realizar outra operação?" <<endl
    <<"1 - Sim" <<endl
    <<"2 - Não" <<endl;
    cin >> control;
    break;

default:
    cout <<endl;

} 
} while (control == 1);
cout <<"\n" <<"Finalizado";
}

bool Inserir(DADOS_ALUNO Lista[], int CodAluno, char Nome[], int Turma, int &PosUltimoElem) {
    if (PosUltimoElem == MAX_LISTA){
    cout << "ERRO: Lista cheia.";
    return false;
    }
    else {
    Lista[PosUltimoElem].CodAluno = CodAluno;
    strcpy(Lista[PosUltimoElem].Nome, Nome);
    Lista[PosUltimoElem].Turma = Turma;
    PosUltimoElem++;
    }
    return true; 
}

bool InserirPos(DADOS_ALUNO Lista[], int PosIns, int CodAluno,  char Nome[], int Turma, int &PosUltimoElem) {
    int ind;
    if (PosUltimoElem == MAX_LISTA){
    cout << "ERRO: Lista cheia.";
    return false;
    }
    else {
    // Desloca os itens da lista
    for(ind = PosUltimoElem + 1; ind > PosIns; ind-- ){
    Lista[ind] = Lista[ind-1];
    }
     // Insere novo elemento
    Lista[PosIns].CodAluno = CodAluno;
    strcpy(Lista[PosIns].Nome, Nome);
    Lista[PosIns].Turma = Turma;
    PosUltimoElem++;
    } 
    return true; 
}

bool Exibir(DADOS_ALUNO Lista[], int PosUltimoElem) {
    int ind;
    char chCodAluno[3], chTurma[3];
    if (PosUltimoElem == 0){
    cout << "ERRO: Lista vazia.";
    return false;
    } 
    printf("Código do Aluno \t");
    printf("Nome \t \t");
    printf("Turma \t");
    cout <<endl;

    for(ind = 0; ind < PosUltimoElem; ind++ ){
    cout << Lista[ind].CodAluno; printf("\t \t \t");
    printf(Lista[ind].Nome); printf("\t \t");
    cout << (Lista[ind].Turma);  
    cout <<endl;
    }
    return true;
}

int Pesquisar(DADOS_ALUNO Lista[], int CodAluno, int &PosUltimoElem) {
    int ind;
    for(ind = 0; ind < PosUltimoElem; ind++ ){
        if (Lista[ind].CodAluno == CodAluno){
        return ind;
        }
    }
    return -1; 
}

bool RemoverElem(DADOS_ALUNO Lista[], int CodAluno, int &PosUltimoElem) {
    int ind;
    int PosRem;
    if (PosUltimoElem == 0){
        cout << "ERRO: Lista vazia.";
        return false;
        }
    // Encontra a posição do elemento que será removido
    PosRem = Pesquisar(Lista, CodAluno, PosUltimoElem);
    // Desloca a lista sobrepondo o elemento a ser removido
    for(ind = PosRem; ind < PosUltimoElem; ind++ ){
        Lista[ind] = Lista[ind+1];
        }
    PosUltimoElem--;
    return true; 
}
