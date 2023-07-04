#include "arvore_binaria.h"

//========= Exercício 1 - Inserção ====
Arvore* inserirElemento(Arvore *arv, int n)
{
	if(verificaVazio(arv))
	{
		arv = (Arvore*) malloc (sizeof(Arvore));
		arv->info = n;
		arv->esq = NULL;
		arv->dir = NULL;
	}
	else if(arv->info > n)
		arv->esq = inserirElemento(arv->esq, n);
	else
		arv->dir = inserirElemento(arv->dir, n);
	
	return arv;
}

//========= Exercício 1 - Busca ====
int buscarElemento(Arvore* arv, int n)
{
	if(verificaVazio(arv))
		return 0;
	else if (arv->info > n)
		buscarElemento(arv->esq, n);
	else if (arv->info < n)
		buscarElemento(arv->dir, n);
	else
		return 1;
}

//========= Exercício 1 - Remoção ====
Arvore* removerElemento(Arvore *arv, int n)
{
	if(verificaVazio(arv))
		return NULL;
	else
	{
		if (arv->info > n)
			arv->esq = removerElemento(arv->esq, n);
		else if (arv->info < n)
			arv->dir = removerElemento(arv->dir, n);
		else
		{
			if(verificaVazio(arv->esq) && verificaVazio(arv->dir))
			{
				printf("Excluiu %d\n", arv->info);
				free(arv);
				arv = NULL;
			}
			else if(verificaVazio(arv->esq))
			{
				Arvore *aux;
				aux = arv;
				arv = arv->dir;
				printf("Excluiu %d\n", aux->info);
				free(aux);
				aux = NULL;
			}
			else if(verificaVazio(arv->dir))
			{
				Arvore *aux;
				aux = arv;
				arv = arv->esq;
				printf("Excluiu %d\n", aux->info);
				free(aux);
				aux = NULL;
			}
			else
			{
				Arvore *aux;
				aux = arv->esq;
				while(!verificaVazio(aux->dir))
				{
					aux = aux->dir;
				}
				arv->info = aux->info;
				aux->info = n;
				arv->esq = removerElemento(arv->esq, n);
			}
			/*else
			{
				Arvore *aux;
				aux = arv->dir;
				while(!verificaVazio(aux->dir))
				{
					aux = aux->esq;
				}
				arv->info = aux->info;
				aux->info = n;
				arv->dir = removerElemento(arv->dir, n);
			}*/
		}
	}
	return arv;
}

//========= Exercício 2 - mínimo ====
int menorElemento(Arvore *arv)
{
	if(verificaVazio(arv->esq))
		return arv->info;
	else
		menorElemento(arv->esq);
}

//========= Exercício 2 - máximo ====
int maiorElemento(Arvore *arv)
{
	if(verificaVazio(arv->dir))
		return arv->info;
	else
		maiorElemento(arv->dir);
}

//========= Exercício 3 - imprimir crescente ====
void imprimeCrescente(Arvore *arv)
{
	if(verificaVazio(arv))
		return;
	else
	{
		imprimeCrescente(arv->esq);
		printf("%d ", arv->info);
		imprimeCrescente(arv->dir);
	}
}

//========= Exercício 3 - imprimir decrescente ====
void imprimeDecrescente(Arvore *arv)
{
	if(verificaVazio(arv))
		return;
	else
	{
		imprimeDecrescente(arv->dir);
		printf("%d ", arv->info);
		imprimeDecrescente(arv->esq);
	}
}

//========= Exercício 4 - imprimir maior ramo ====
int maiorRamo(Arvore *arv)
{
	int ramo_esq = 0, ramo_dir = 0;
	if(verificaVazio(arv))
		return 0;
	else
    {
		ramo_esq += maiorRamo(arv->esq) + arv->info;
        ramo_dir += maiorRamo(arv->dir) + arv->info;
        if(ramo_esq > ramo_dir)
			return ramo_esq;
		else
			return ramo_dir;
    }
}

/*========= Exercício 5 - execução do programa ====
a) Levou 0,182 milissegundos.
b) Levou 0,001 milissegundos. 
Explicação: Foi mais rápido porque a árvore binária de busca foi construída corretamente na letra B e por isso pode fazer a pesquisa binária, que tem o custo computacional de log2(N), em comparação ao outro que o custo é de O(n).*/

int verificaVazio(Arvore *arv)
{
    return(NULL == arv);
}

void imprimeArvorePre(Arvore *arv)
{
    if(verificaVazio(arv))
    {
        return;
    }
    printf("%d ", arv->info);
    imprimeArvorePre(arv->esq);
    imprimeArvorePre(arv->dir);
}

void liberaArvore(Arvore *arv)
{
	if(!verificaVazio(arv))
    {
        liberaArvore(arv->esq);
        liberaArvore(arv->dir);
        free(arv);
    }
}

int main()
{
    Arvore *arv = NULL;
	arv = inserirElemento (arv, 50);
	arv = inserirElemento (arv, 30);
	arv = inserirElemento (arv, 90);
	arv = inserirElemento (arv, 20);
	arv = inserirElemento (arv, 40);
	arv = inserirElemento (arv, 95);
	arv = inserirElemento (arv, 10);
	arv = inserirElemento (arv, 35);
	arv = inserirElemento (arv, 45);

	printf("Imprimir em Pré-Ordem: ");
	imprimeArvorePre(arv);

	printf("\nImprimir em ordem crescente: ");
	imprimeCrescente(arv);

	printf("\nImprimir em ordem decrescente: ");
	imprimeDecrescente(arv);

	printf("\nImprimir menor elemento: %d", menorElemento(arv));
	printf("\nImprimir maior elemento: %d", maiorElemento(arv));

	printf("\nImprimir o maior ramo: %d", maiorRamo(arv));

	printf("\nBuscar pelo 10: ");
	if(buscarElemento(arv, 10))
	{
		printf("Verdade\n\n");
	}
	else
	{
		printf("Falso\n\n");
	}

	arv = removerElemento (arv, 95);
	arv = removerElemento (arv, 20);
	arv = removerElemento (arv, 50);
	imprimeArvorePre(arv);
	liberaArvore(arv);

    // Adição em ordem
	clock_t inicio;
    Arvore *arv_em_ordem = NULL, *arv_aleatoria = NULL;
    for (int i = 0; i < 10000; i++)
	{	
		arv_em_ordem = inserirElemento(arv_em_ordem, i);
	}
    inicio = clock();
    buscarElemento(arv_em_ordem, 1154321);
    printf("\n\nTempo de busca em árvore degenerada: %fs\n", (double) (clock() - inicio) / CLOCKS_PER_SEC);
	liberaArvore(arv_em_ordem);
	
    // Adição aleatória
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
	{	
        arv_aleatoria = inserirElemento(arv_aleatoria, rand() % 1000000);
	}
    inicio = clock();
    buscarElemento(arv_aleatoria, 1154321);
    printf("Tempo de busca em árvore aleatória: %fs\n", (double)(clock() - inicio) /CLOCKS_PER_SEC);
	liberaArvore(arv_aleatoria);
	
    return 0;
}