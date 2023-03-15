#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arvore {
    int info;
    struct arvore* esq;
    struct arvore* dir;
} Arvore;

int verificaVazio(Arvore *arv);
void imprimeArvorePre(Arvore *arv);
void liberaArvore(Arvore *arv);

///////
Arvore* inserirElemento(Arvore *arv, int n);
int buscarElemento(Arvore* arv, int n);
Arvore* removerElemento(Arvore *arv, int n);
int menorElemento(Arvore *arv);
int maiorElemento(Arvore *arv);
void imprimeCrescente(Arvore *arv);
void imprimeDecrescente(Arvore *arv);
int maiorRamo(Arvore *arv);