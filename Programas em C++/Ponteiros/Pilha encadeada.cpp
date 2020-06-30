#include <iostream> 
#include "conio.h"
#include <locale.h>
#include <string.h>
using namespace std; 

struct DADOS_ALUNO{
    // Dados
        int CodAluno;
        char Nome[100];
        int Turma;
    // Link
        struct DADOS_ALUNO * ptrLink;
}; 

DADOS_ALUNO* CriarPilha();
bool VerificarPilhaVazia(DADOS_ALUNO *ptrCab);
bool Empilhar(DADOS_ALUNO *ptrCab, int CodAluno, char Nome[], int Turma);

DADOS_ALUNO* CriarPilha() {
    DADOS_ALUNO *ptrCab;
    ptrCab = new DADOS_ALUNO;
    ptrCab->ptrLink = NULL;

    return ptrCab;
}

bool VerificarPilhaVazia(DADOS_ALUNO *ptrCab) {
    if(ptrCab->ptrLink == NULL)
        return true;
    else
        return false;
}

bool Empilhar(DADOS_ALUNO *ptrCab, int CodAluno, char Nome[], int Turma){
    DADOS_ALUNO *ptrNovo;
    DADOS_ALUNO *ptrAux;
    int Pos;

    // Cria o novo nó
        ptrNovo = new DADOS_ALUNO;
        if (ptrNovo == NULL){
            cout << "Memória insulficiente!";
            return false;
        }

        ptrNovo->CodAluno = CodAluno;
        strcpy(ptrNovo->Nome, Nome);
        ptrNovo->Turma = Turma;
        ptrNovo->ptrLink = NULL;

    // Insere no topo da pilha
        ptrAux = ptrCab;
        while(ptrAux->ptrLink != NULL){
        ptrAux = ptrAux->ptrLink;
        }

        ptrAux->ptrLink = ptrNovo;
        return true;
}

