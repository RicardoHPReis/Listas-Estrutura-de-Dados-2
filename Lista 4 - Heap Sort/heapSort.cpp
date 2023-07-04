#include "heapSort.hpp"

int pai (int num) 
{
   return (num - 1)/2;
}

int esquerda (int num) 
{
   return num * 2 + 1;
}

int direita (int num) 
{
   return num * 2 + 2;
}

void trocar (int heap[], int a, int b) 
{
   int aux = heap[a];
   heap[a] = heap[b];
   heap[b] = aux;
}

void imprimir (int heap[], int tamanho) 
{
   for (int i = 0; i < tamanho; i++) 
   {
	   printf("%d ", heap[i]);
   }
   printf("\n");
}

void max_heapify (int heap[], int tamanho, int num) 
{
	int maior;
	int esq = esquerda(num);
	int dir = direita(num);
	if(esq < tamanho && heap[esq] < heap[num])
		maior = esq;
	else
		maior = num;
	if (dir < tamanho && heap[dir] < heap[maior])
		maior = dir;
	if(maior != num)
	{
		trocar(heap, num, maior);
		max_heapify(heap, tamanho, maior);
	}
}

void build_max_heap (int heap[], int tamanho) 
{
	for(int i = tamanho/2 - 1; i >= 0; i--)
	{
		max_heapify(heap, tamanho, i);
	}
}

void heap_sort (int heap[], int tamanho) 
{
	build_max_heap(heap, tamanho);
	for(int i = tamanho-1; i >= 1; i--)
	{
		trocar(heap, 0, i);
		tamanho = i;
		max_heapify(heap, tamanho, 0);
	}
}