#include "stdafx.hpp"

typedef struct No {
	int id;
	int peso;
	struct No *proximo;
} NoAdjacente;

typedef struct {
	int arestas;
	int vertices;
	NoAdjacente **adj;
} GrafoAdjacente;

GrafoAdjacente* criar_grafo_adjacente (int tamanho);
void zerar_grafo_adjacente (GrafoAdjacente* grafo);
void imprimir_grafo_adjacente (GrafoAdjacente* grafo);
void imprimir_grafo_peso_adjacente (GrafoAdjacente *grafo);
void adicionar_vertice_grafo_adjacente (GrafoAdjacente* grafo, int *tamanho, int vertices);
void adicionar_aresta_grafo_adjacente (GrafoAdjacente* grafo, int aresta1, int aresta2);
void adicionar_direcionada_grafo_adjacente (GrafoAdjacente* grafo, int inicio, int fim);
void adicionar_peso_grafo_adjacente (GrafoAdjacente* grafo, int inicio, int fim, int peso);
void arestas_incidentes_grafo_adjacente (GrafoAdjacente* grafo, int vertice);
void arestas_saida_grafo_adjacente (GrafoAdjacente* grafo, int vertice);
void vertices_adjacentes_grafo_adjacente (GrafoAdjacente* grafo, int vertice);
void liberar_grafo_adjacente (GrafoAdjacente *grafo);