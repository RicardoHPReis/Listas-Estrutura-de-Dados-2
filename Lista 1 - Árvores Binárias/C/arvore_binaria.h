#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    char info;
    struct arvore* esq;
    struct arvore* dir;
} Arvore;

Arvore* constroiArvore(char info, Arvore *e, Arvore *d);
int verificaVazio(Arvore *arv);
void liberaArvore(Arvore *arv);
void imprimeArvorePre(Arvore *arv);
void imprimeArvoreInOrdem(Arvore *arv);
void imprimeArvorePos(Arvore *arv);
int pertenceArvore(Arvore *arv, char c);
int contagemNos(Arvore *arv);
int calculaAlturaArvore(Arvore *arv);
int contagemFolhas(Arvore *arv);