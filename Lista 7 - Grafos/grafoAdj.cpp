#include "grafoAdj.hpp"

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

void arestas_incidentes_grafo_adjacente (GrafoAdjacente *grafo, int vertice)
{
	int num = 0;
	NoAdjacente *aux;
	aux = grafo->adj[vertice];
	while (aux != NULL)
    {
		num++;
        aux = aux->proximo;
    }
	printf("Número de arestas incidentes ao vértice %d: %d\n", vertice, num);
}

void arestas_saida_grafo_adjacente (GrafoAdjacente *grafo, int vertice)
{
	int num = 0;
	NoAdjacente *aux;
	for (int i = 0; i < grafo->vertices; i++)
    {
        aux = grafo->adj[i];
        while (aux != NULL)
        {
			if(aux->id == vertice)
            	num++;
            aux = aux->proximo;
        }
    }
	printf("Número de arestas que saem do vértice %d: %d\n", vertice, num);
}

void vertices_adjacentes_grafo_adjacente (GrafoAdjacente *grafo, int vertice)
{
	NoAdjacente *aux;
	aux = grafo->adj[vertice];
	printf("Vértices adjacentes ao vértice %d: ", vertice);
	while (aux != NULL)
    {
        printf("%d ", aux->id);
        aux = aux->proximo;
    }
	printf("\n");
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