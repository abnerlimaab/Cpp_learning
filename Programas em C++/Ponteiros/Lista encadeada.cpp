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

DADOS_ALUNO* CriarLista();
bool VerificarListaVazia(DADOS_ALUNO *ptrCab);
bool Inserir(DADOS_ALUNO *ptrCab, int PosInserir, int CodAluno,  char Nome[], int Turma);
int PosicaoNo(DADOS_ALUNO *ptrCab, int CodAluno);
int ObterTamanho(DADOS_ALUNO *ptrCab);
void Exibir(DADOS_ALUNO *ptrCab);
bool Remover(DADOS_ALUNO *ptrCab, int PosRemover);

int main(){
} 

DADOS_ALUNO* CriarLista() {
    DADOS_ALUNO *ptrCab;
    ptrCab = new DADOS_ALUNO;
    ptrCab->ptrLink = NULL;
    return ptrCab; 
}

bool VerificarListaVazia(DADOS_ALUNO *ptrCab) {
    if(ptrCab->ptrLink == NULL)
        return true;
    else
        return false; 
}

bool Inserir(DADOS_ALUNO *ptrCab, int PosInserir, int CodAluno,  char Nome[], int Turma) {
    DADOS_ALUNO *ptrNovo;
    DADOS_ALUNO *ptrAux;
    int Pos; 

    // Cria o novo nó e atribui os dados às variáveis membros 
        ptrNovo = new DADOS_ALUNO;
            if (ptrNovo == NULL){
                cout << "Memória insulficiente!";
                return false;
                } 
        
            ptrNovo->CodAluno = CodAluno;
            strcpy(ptrNovo->Nome, Nome);
            ptrNovo->Turma = Turma;
            ptrNovo->ptrLink = NULL; 

    // Se a lista estiver vazia, insere no início da lista
        if( VerificarListaVazia(ptrCab) ){
        // Liga o primeiro nó ao nó cabeça
            ptrCab->ptrLink = ptrNovo;
            return true;
        } 

    // Se não foi informada a posição, então insere no fim da lista 
        if (PosInserir == 0){
        // Localiza o último nó
            ptrAux = ptrCab->ptrLink;
            while(ptrAux->ptrLink != NULL){
            ptrAux = ptrAux->ptrLink;}
            ptrAux->ptrLink = ptrNovo;
            return true;
        } 

    // Insere na posição informada 
        ptrAux = ptrCab;
        Pos = 1; 

        // Localiza a posição a ser inserida
            while((Pos < PosInserir) && (ptrAux != NULL)){
                ptrAux = ptrAux->ptrLink;
                Pos++;
            } 

            if(ptrAux == NULL){
                cout << "Posição não encontrada!";
                return false;
            } 

            ptrNovo->ptrLink = ptrAux->ptrLink;
            ptrAux->ptrLink = ptrNovo;
            return true; 
}

int PosicaoNo(DADOS_ALUNO *ptrCab, int CodAluno) {
    DADOS_ALUNO *ptrAux;
    int Posicao;

    // Se a lista estiver vazia
        if( VerificarListaVazia(ptrCab) ){
            cout << "Lista vazia!";
            return false;}

    ptrAux = ptrCab;
    Posicao = 0;

    // Localizar Nó
        while(ptrAux != NULL) {
            if (ptrAux -> CodAluno == CodAluno)
                break;

                Posicao++;
                ptrAux = ptrAux->ptrLink;
        }

        if(ptrAux == NULL){
            cout << "Código do aluno não encontrado!";
            return -1;
        }
    return Posicao;
}

int ObterTamanho(DADOS_ALUNO *ptrCab) {
    DADOS_ALUNO *ptrAux;
    int Pos;

    // Se a lista estiver vazia
        if( VerificarListaVazia(ptrCab) ){
            cout << "Lista vazia!";
            return false;
        }

    Pos = 0;
    ptrAux = ptrCab->ptrLink;

    // Conta os nós
        while(ptrAux != NULL){
            Pos++;
            ptrAux = ptrAux->ptrLink;
        }

    return Pos;
}

void Exibir(DADOS_ALUNO *ptrCab){
    DADOS_ALUNO *ptrAux;
    int Ind;

    ptrAux = ptrCab->ptrLink;
    Ind = 1;

    printf("Nó \t");
    printf("Código do Aluno \t");
    printf("Nome \t \t");
    printf("Turma \t");
    cout << endl;
    
    while(ptrAux != NULL){
        cout << Ind; printf("\t");
        cout << ptrAux -> CodAluno; printf("\t");
        cout << ptrAux -> Nome; printf("\t \t");
        cout << ptrAux -> Turma; printf("\t");
        cout << endl;

        Ind++;
        ptrAux = ptrAux->ptrLink;
    }
}

bool Remover(DADOS_ALUNO *ptrCab, int PosRemover){
    DADOS_ALUNO *ptrAux;
    DADOS_ALUNO *ptrAnterior;
    int Pos;

    // Se a lista estiver vazia
        if( VerificarListaVazia(ptrCab) ){
            cout << "Lista vazia!";
            return false;
        }

        if(PosRemover < 1){
            cout << "Código do aluno não encontrado!";
            return false;
        }
        
    ptrAux = ptrCab;
    ptrAnterior = ptrCab;
    Pos = 0;

    // Localiza a posição a ser removida
        while((Pos < PosRemover) && (ptrAux != NULL)){
            ptrAnterior = ptrAux;
            ptrAux = ptrAux->ptrLink;
            Pos++;
        }

        if(ptrAux == NULL){
            cout << "Posição inválida!";
            return false;
        }
        
        ptrAnterior->ptrLink = ptrAux->ptrLink;
        delete ptrAux;
}