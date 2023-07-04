#include "heapSort.hpp"

int main() 
{
	int heap[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	int tamanho = (int)(sizeof(heap) / sizeof(heap[0]));
	printf("Tamanho do vetor: %d\n", tamanho);
	printf("Vetor inicial: ");
	imprimir(heap, tamanho);
	heap_sort(heap, tamanho);
	printf("Vetor ordenado: ");
	imprimir(heap, tamanho);
	return 0;
}