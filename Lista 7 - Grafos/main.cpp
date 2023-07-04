#include "grafoAdj.hpp"
#include "grafoMat.hpp"

int main() 
{
	int vertices_A = 6;
	int vertices_M = 6;
	
	GrafoAdjacente* grafo_Adj = criar_grafo_adjacente(vertices_A);
	GrafoMatriz* grafo_Mat = criar_grafo_matriz(vertices_M);

	//Exercício 1
	printf("\nGrafos Matriz:\n");
	adicionar_aresta_grafo_matriz (grafo_Mat, 0, 1);
	adicionar_aresta_grafo_matriz (grafo_Mat, 0, 2);
	adicionar_aresta_grafo_matriz (grafo_Mat, 0, 5);
	adicionar_aresta_grafo_matriz (grafo_Mat, 1, 2);
	adicionar_aresta_grafo_matriz (grafo_Mat, 1, 3);
	adicionar_aresta_grafo_matriz (grafo_Mat, 2, 3);
	adicionar_aresta_grafo_matriz (grafo_Mat, 2, 4);
	adicionar_aresta_grafo_matriz (grafo_Mat, 3, 4);
	adicionar_aresta_grafo_matriz (grafo_Mat, 4, 5);
	imprimir_grafo_matriz (grafo_Mat);
	zerar_grafo_matriz (grafo_Mat);

	printf("\nGrafos Adjacentes:\n");
	adicionar_aresta_grafo_adjacente (grafo_Adj, 0, 1);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 0, 2);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 0, 5);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 1, 2);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 1, 3);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 2, 3);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 2, 4);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 3, 4);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 4, 5);
	imprimir_grafo_adjacente (grafo_Adj);
	zerar_grafo_adjacente (grafo_Adj);
	
	//Exercício 2
	printf("\nGrafos Matriz:\n");
	adicionar_direcionada_grafo_matriz (grafo_Mat, 0, 1);
	adicionar_direcionada_grafo_matriz (grafo_Mat, 0, 5);
	adicionar_direcionada_grafo_matriz (grafo_Mat, 1, 2);
	adicionar_direcionada_grafo_matriz (grafo_Mat, 1, 3);
	adicionar_direcionada_grafo_matriz (grafo_Mat, 2, 0);
	adicionar_direcionada_grafo_matriz (grafo_Mat, 2, 4);
	adicionar_direcionada_grafo_matriz (grafo_Mat, 3, 2);
	adicionar_direcionada_grafo_matriz (grafo_Mat, 4, 3);
	adicionar_direcionada_grafo_matriz (grafo_Mat, 5, 4);
	imprimir_grafo_matriz (grafo_Mat);
	zerar_grafo_matriz (grafo_Mat);

	printf("\nGrafos Adjacentes:\n");
	adicionar_aresta_grafo_adjacente (grafo_Adj, 0, 1);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 0, 5);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 1, 2);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 1, 3);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 2, 0);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 2, 4);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 3, 2);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 4, 3);
	adicionar_aresta_grafo_adjacente (grafo_Adj, 5, 4);
	imprimir_grafo_adjacente (grafo_Adj);
	zerar_grafo_adjacente (grafo_Adj);
	
	//Exercício 3
	printf("\nGrafos Matriz:\n");
	adicionar_peso_grafo_matriz (grafo_Mat, 0, 1, 1);
	adicionar_peso_grafo_matriz (grafo_Mat, 0, 3, 5);
	adicionar_peso_grafo_matriz (grafo_Mat, 1, 3, 8);
	adicionar_peso_grafo_matriz (grafo_Mat, 2, 0, 5);
	adicionar_peso_grafo_matriz (grafo_Mat, 2, 3, 4);
	adicionar_peso_grafo_matriz (grafo_Mat, 3, 3, 6);
	adicionar_peso_grafo_matriz (grafo_Mat, 3, 4, 3);
	adicionar_peso_grafo_matriz (grafo_Mat, 4, 2, 7);
	adicionar_peso_grafo_matriz (grafo_Mat, 4, 5, 9);
	adicionar_peso_grafo_matriz (grafo_Mat, 5, 0, 2);
	imprimir_grafo_matriz (grafo_Mat);

	printf("\nGrafos Adjacentes:\n");
	adicionar_peso_grafo_adjacente (grafo_Adj, 0, 1, 1);
	adicionar_peso_grafo_adjacente (grafo_Adj, 0, 3, 5);
	adicionar_peso_grafo_adjacente (grafo_Adj, 1, 3, 8);
	adicionar_peso_grafo_adjacente (grafo_Adj, 2, 0, 5);
	adicionar_peso_grafo_adjacente (grafo_Adj, 2, 3, 4);
	adicionar_peso_grafo_adjacente (grafo_Adj, 3, 3, 6);
	adicionar_peso_grafo_adjacente (grafo_Adj, 3, 4, 3);
	adicionar_peso_grafo_adjacente (grafo_Adj, 4, 2, 7);
	adicionar_peso_grafo_adjacente (grafo_Adj, 4, 5, 9);
	adicionar_peso_grafo_adjacente (grafo_Adj, 5, 0, 2);
	imprimir_grafo_peso_adjacente (grafo_Adj);

	printf("\nGrafos Matriz:\n");
	arestas_incidentes_grafo_matriz (grafo_Mat, 3);
	arestas_saida_grafo_matriz (grafo_Mat, 4);
	vertices_adjacentes_grafo_matriz (grafo_Mat, 2);
	liberar_grafo_matriz (grafo_Mat);
	
	printf("\nGrafos Adjacentes:\n");
	arestas_incidentes_grafo_adjacente (grafo_Adj, 3);
	arestas_saida_grafo_adjacente (grafo_Adj, 4);
	vertices_adjacentes_grafo_adjacente (grafo_Adj, 2);
	liberar_grafo_adjacente (grafo_Adj);

	return 0;
}