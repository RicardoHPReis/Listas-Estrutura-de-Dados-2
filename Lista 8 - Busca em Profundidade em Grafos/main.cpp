#include "grafoAdj.hpp"

int main() 
{
	int vertices_A = 12;
	
	GrafoAdjacente* grafo_Adj = criar_grafo_adjacente(vertices_A);
	printf("\nGrafo Adjacente:\n");
	adicionar_direcionada_grafo_adjacente (grafo_Adj, 0, 1);
	adicionar_direcionada_grafo_adjacente (grafo_Adj, 0, 3);
	adicionar_direcionada_grafo_adjacente (grafo_Adj, 1, 2);
	adicionar_direcionada_grafo_adjacente (grafo_Adj, 2, 5);
	adicionar_direcionada_grafo_adjacente (grafo_Adj, 4, 1);
	adicionar_direcionada_grafo_adjacente (grafo_Adj, 5, 4);
	adicionar_direcionada_grafo_adjacente (grafo_Adj, 5, 6);
	adicionar_direcionada_grafo_adjacente (grafo_Adj, 6, 0);
	adicionar_direcionada_grafo_adjacente (grafo_Adj, 6, 3);
	adicionar_direcionada_grafo_adjacente (grafo_Adj, 6, 4);
	adicionar_direcionada_grafo_adjacente (grafo_Adj, 7, 8);
	adicionar_direcionada_grafo_adjacente (grafo_Adj, 9, 10);
	adicionar_direcionada_grafo_adjacente (grafo_Adj, 10, 11);
	adicionar_direcionada_grafo_adjacente (grafo_Adj, 11, 9);
	imprimir_grafo_adjacente (grafo_Adj);

	printf("\nBusca por Profundidade:\n");
	busca_profundidade(grafo_Adj, 0);
	printf("\n");
	busca_profundidade(grafo_Adj, 7);
	printf("\n");
	busca_profundidade(grafo_Adj, 9);
	liberar_grafo_adjacente (grafo_Adj);

	//Exercício 3
	vertices_A = 7;
	grafo_Adj = criar_grafo_adjacente(vertices_A);
	printf("\n\nGrafo Adjacente:\n");
	adicionar_aresta_grafo_adjacente (grafo_Adj, 0, 1);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 0, 5);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 1, 2);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 1, 4);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 3, 6);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 4, 5);
	imprimir_grafo_adjacente (grafo_Adj);

	printf("\nO grafo é bipartido?\n");
	grafo_bipartido (grafo_Adj);
	liberar_grafo_adjacente (grafo_Adj);

	return 0;
}