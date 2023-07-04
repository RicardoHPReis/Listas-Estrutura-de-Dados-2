#include "grafoAdj.hpp"
#define BRANCO 0
#define CINZA 1
#define PRETO 2

GrafoAdjacente* criar_grafo_adjacente (int tamanho) 
{
	GrafoAdjacente *grafo = (GrafoAdjacente*) malloc (sizeof(GrafoAdjacente));
	grafo->arestas = 0;
	grafo->vertices = tamanho;
	grafo->adj = (NoAdjacente**) malloc (tamanho*sizeof(NoAdjacente*));
	for (int v = 0; v < grafo->vertices; v++) 
	{
		grafo->adj[v] = NULL;
	}
	return grafo;
}

void zerar_grafo_adjacente (GrafoAdjacente *grafo)
{
	NoAdjacente *atual;
	NoAdjacente *aux;
	for (int v = 0; v < grafo->vertices; v++) 
	{
		atual = grafo->adj[v];
    	while (atual != NULL) 
		{
            aux = atual;
            atual = atual->proximo;
            free(aux);
        }
        grafo->adj[v] = NULL;
	}
}

void imprimir_grafo_adjacente (GrafoAdjacente *grafo)
{
	NoAdjacente *aux;
    for (int i = 0; i < grafo->vertices; i++)
    {
        printf("%d -> ", i);
        aux = grafo->adj[i];
        while (aux != NULL)
        {
            printf("%d, ", aux->id);
            aux = aux->proximo;
        }
        printf("\n");
    }
}

void imprimir_grafo_peso_adjacente (GrafoAdjacente *grafo)
{
	NoAdjacente *aux;
    for (int i = 0; i < grafo->vertices; i++)
    {
        printf("%d -> ", i);
        aux = grafo->adj[i];
        while (aux != NULL)
        {
            printf("%d: (w:%d), ", aux->id, aux->peso);
            aux = aux->proximo;
        }
        printf("\n");
    }
}

void adicionar_vertice_grafo_adjacente (GrafoAdjacente *grafo, int *tamanho, int vertices)
{
	grafo->vertices = (*tamanho) + vertices;
	(*tamanho) = (*tamanho) + vertices;
	grafo->adj = (NoAdjacente**) realloc (grafo->adj, (*tamanho)*sizeof(NoAdjacente*));
	for (int v = 0; v < grafo->vertices; v++)
	{
		grafo->adj[v] = NULL;
	}
}

void adicionar_aresta_grafo_adjacente (GrafoAdjacente *grafo, int aresta1, int aresta2)
{
	grafo->arestas--;
	adicionar_peso_grafo_adjacente (grafo, aresta1, aresta2, 1);
	adicionar_peso_grafo_adjacente (grafo, aresta2, aresta1, 1);
}

void adicionar_direcionada_grafo_adjacente (GrafoAdjacente *grafo, int inicio, int fim)
{
	adicionar_peso_grafo_adjacente (grafo, inicio, fim, 1);
}

void adicionar_peso_grafo_adjacente (GrafoAdjacente *grafo, int inicio, int fim, int peso)
{
	NoAdjacente *aux;
	if ((inicio >= grafo->vertices || inicio < 0) || (fim >= grafo->vertices || fim < 0))
	{	
        return;
	}
	
	grafo->arestas++;
	aux = grafo->adj[inicio];
	if(grafo->adj[inicio] == NULL)
	{
		grafo->adj[inicio] = (NoAdjacente*) malloc (sizeof(NoAdjacente));
		grafo->adj[inicio]->id = fim;
		grafo->adj[inicio]->peso = peso;
		grafo->adj[inicio]->proximo = NULL;
	}
	else
	{
		while (aux->proximo != NULL)
	    {
	        aux = aux->proximo;
	    }
		aux->proximo = (NoAdjacente*) malloc (sizeof(NoAdjacente));
		aux->proximo->id = fim;
		aux->proximo->peso = peso;
		aux->proximo->proximo = NULL;
	}
}

void busca_profundidade (GrafoAdjacente* grafo, int inicio) 
{
    int* visitas = (int*) calloc (grafo->vertices, sizeof(int));
    visita_DFS(grafo, inicio, visitas);
    free(visitas);
}

void visita_DFS (GrafoAdjacente* grafo, int vertice, int* tempo)
{
    tempo[vertice] = CINZA;
    printf("%d ", vertice);

    NoAdjacente* aux = grafo->adj[vertice];
    while (aux != NULL)
	{
        if (tempo[aux->id] == BRANCO)
            visita_DFS(grafo, aux->id, tempo);
        aux = aux->proximo;
    }
}

void grafo_bipartido (GrafoAdjacente* grafo) 
{
	int* cor = (int*) calloc (grafo->vertices, sizeof(int));

    for (int i = 0; i < grafo->vertices; i++)
	{
        if (cor[i] == BRANCO) 
		{
            if (verifica_grafo_bipartido(grafo, i, cor)) 
			{
                free(cor);
                printf("Não é bipartido!");
				return;
            }
        }
    }

	printf("É bipartido!");
    free(cor);
}

int verifica_grafo_bipartido (GrafoAdjacente* grafo, int vertice, int *cor) 
{
    cor[vertice] = CINZA;

    NoAdjacente* aux = grafo->adj[vertice];
    while (aux != NULL) 
	{
        int adjVertex = aux->id;

        if (cor[aux->id] == BRANCO) 
		{
            cor[aux->id] = (cor[vertice] == CINZA) ? PRETO : CINZA;
			
            if (!verifica_grafo_bipartido(grafo, aux->id, cor))
                return 0;
        } 
		else if (cor[aux->id] == cor[vertice])
            return 0;

        aux = aux->proximo;
    }

    return 1;
}

void liberar_grafo_adjacente (GrafoAdjacente *grafo) 
{
	NoAdjacente *atual;
	NoAdjacente *aux;
	for (int v = 0; v < grafo->vertices; v++) 
	{
		atual = grafo->adj[v];
    	while (atual != NULL) 
		{
            aux = atual;
            atual = atual->proximo;
            free(aux);
        }
        grafo->adj[v] = NULL;
	}
	free(grafo->adj);
	free(grafo);
}