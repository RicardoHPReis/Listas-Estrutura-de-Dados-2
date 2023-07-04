#include "stdafx.hpp"

typedef struct {
	int arestas;
	int vertices; 
	int **matriz;
} GrafoMatriz;

GrafoMatriz* criar_grafo_matriz (int tamanho);
void zerar_grafo_matriz (GrafoMatriz* grafo);
void imprimir_grafo_matriz (GrafoMatriz* grafo);
void adicionar_vertice_grafo_matriz (GrafoMatriz* grafo, int *tamanho, int vertices);
void adicionar_aresta_grafo_matriz (GrafoMatriz* grafo, int aresta1, int aresta2);
void adicionar_direcionada_grafo_matriz (GrafoMatriz* grafo, int inicio, int fim);
void adicionar_peso_grafo_matriz (GrafoMatriz* grafo, int inicio, int fim, int peso);
void arestas_incidentes_grafo_matriz (GrafoMatriz* grafo, int vertice);
void arestas_saida_grafo_matriz (GrafoMatriz* grafo, int vertice);
void vertices_adjacentes_grafo_matriz (GrafoMatriz* grafo, int vertice);
void liberar_grafo_matriz (GrafoMatriz *grafo);