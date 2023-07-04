#include "grafoMat.hpp"

GrafoMatriz* criar_grafo_matriz (int tamanho) 
{
	GrafoMatriz *grafo = (GrafoMatriz*) malloc (sizeof(GrafoMatriz));
	grafo->arestas = 0;
	grafo->vertices = tamanho;
	grafo->matriz = (int**) malloc (tamanho*sizeof(int*));
	for (int v = 0; v < grafo->vertices; v++) 
	{
		grafo->matriz[v] = (int*) calloc (0, tamanho*sizeof(int));
	}
	return grafo;
}

void imprimir_grafo_matriz (GrafoMatriz* grafo)
{
	printf("	");
	for (int a = 0; a < grafo->vertices; a++) 
	{
		printf("%d ", a);
	}
	printf("\n");
	for (int i = 0; i < grafo->vertices; i++)
	{
		printf("%d	", i);
		for (int j = 0; j < grafo->vertices; j++) 
		{
			printf("%d ", grafo->matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void zerar_grafo_matriz (GrafoMatriz* grafo)
{
	for (int i = 0; i < grafo->vertices; i++)
	{
		for (int j = 0; j < grafo->vertices; j++) 
		{
			grafo->matriz[i][j] = 0;
		}
	}
}

void adicionar_vertice_grafo_matriz (GrafoMatriz* grafo, int *tamanho, int vertices)
{
	int num = grafo->vertices;
	grafo->vertices = (*tamanho) + vertices;
	(*tamanho) = (*tamanho) + vertices;
	grafo->matriz = (int**) realloc (grafo->matriz, (*tamanho)*sizeof(int*));
	for (int v = 0; v < grafo->vertices; v++)
	{
		grafo->matriz[v] = (int*) realloc (grafo->matriz[v], (*tamanho)*sizeof(int));
	}
	for (int i = num; i < grafo->vertices; i++)
	{
		for (int j = num; j < grafo->vertices; j++) 
		{
			grafo->matriz[i][j] = 0;
		}
	}
}

void adicionar_aresta_grafo_matriz (GrafoMatriz* grafo, int aresta1, int aresta2)
{
	if(grafo->matriz[aresta1][aresta2] != 1 && grafo->matriz[aresta2][aresta1] != 1)
		grafo->arestas++;
	if(aresta1 < grafo->vertices && aresta2 < grafo->vertices)
	{
		grafo->matriz[aresta1][aresta2] = 1;
		grafo->matriz[aresta2][aresta1] = 1;
	}
}

void adicionar_direcionada_grafo_matriz (GrafoMatriz* grafo, int inicio, int fim)
{
	if(grafo->matriz[inicio][fim] != 1 && grafo->matriz[fim][inicio] != 1)
		grafo->arestas++;
	if(inicio < grafo->vertices && fim < grafo->vertices)
		grafo->matriz[inicio][fim] = 1;
}

void adicionar_peso_grafo_matriz (GrafoMatriz* grafo, int inicio, int fim, int peso)
{
	if(grafo->matriz[inicio][fim] == 0 && grafo->matriz[fim][inicio] == 0)
		grafo->arestas++;
	if(inicio < grafo->vertices && fim < grafo->vertices)
		grafo->matriz[inicio][fim] = peso;
}

void arestas_incidentes_grafo_matriz (GrafoMatriz* grafo, int vertice)
{
	int num = 0;
	for (int j = 0; j < grafo->vertices; j++)
	{
		if(grafo->matriz[j][vertice] > 0)
			num++;
	}
	printf("Número de arestas incidentes ao vértice %d: %d\n", vertice, num);
}

void arestas_saida_grafo_matriz (GrafoMatriz* grafo, int vertice)
{
	int num = 0;
	for (int i = 0; i < grafo->vertices; i++)
	{
		if(grafo->matriz[vertice][i] > 0)
			num++;
	}
	printf("Número de arestas que saem do vértice %d: %d\n", vertice, num);
}

void vertices_adjacentes_grafo_matriz (GrafoMatriz* grafo, int vertice)
{
	printf("Vértices adjacentes ao vértice %d: ", vertice);
	for (int i = 0; i < grafo->vertices; i++)
	{
		if(grafo->matriz[vertice][i] > 0)
			printf("%d ", i);
	}
	printf("\n");
}

void liberar_grafo_matriz (GrafoMatriz *grafo) 
{
	for (int v = 0; v < grafo->vertices; v++) 
	{
    	if (grafo->matriz[v] != NULL)
    		free(grafo->matriz[v]);
	}
	free(grafo->matriz);
	free(grafo);
}