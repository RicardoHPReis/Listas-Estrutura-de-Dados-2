#include "heapSort.hpp"

int main() 
{
	//Execício 1
	int heap_max[] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};
	int tamanho_max = (int)(sizeof(heap_max) / sizeof(heap_max[0]));
	printf("Exercício 1:\n");
	printf("Tamanho do vetor: %d\n", tamanho_max);
	printf("Vetor inicial: ");
	imprimir(heap_max, tamanho_max);
	heap_decrease_key(heap_max, tamanho_max, 0, 1);
	printf("Após a diminuição da posição 1° para o valor 1:\n");
	imprimir(heap_max, tamanho_max);
	//build_max_heap(heap_max, tamanho_max);
	//printf("Após recorganização: ");
	//imprimir(heap_max, tamanho_max);
	
	//Exercício 2
	int heap_min[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	int tamanho_min = (int)(sizeof(heap_min) / sizeof(heap_min[0]));
	printf("\n\nExercício 2:\n");
	printf("Tamanho do vetor: %d\n", tamanho_min);
	printf("Vetor inicial: ");
	imprimir(heap_min, tamanho_min);
	build_min_heap(heap_min, tamanho_min);
	printf("Vetor \"ordenado\": ");
	imprimir(heap_min, tamanho_min);
	heap_extract_min(heap_min, &tamanho_min);
	printf("Após a extração do menor valor: ");
	imprimir(heap_min, tamanho_min);
	heap_decrease_key(heap_min, tamanho_min, 8, 1);
	printf("Após a diminuição da posição 9° para o valor 1: ");
	imprimir(heap_min, tamanho_min);
	min_heap_insert(heap_min, &tamanho_min, 0);
	printf("Após a adição do valor 0: ");
	imprimir(heap_min, tamanho_min);
	
	return 0;
}