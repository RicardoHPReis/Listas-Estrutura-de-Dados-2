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

//Maximum
void max_heapify (int heap[], int tamanho, int num) 
{
	int maior;
	int esq = esquerda(num);
	int dir = direita(num);
	if(esq < tamanho && heap[esq] > heap[num])
		maior = esq;
	else
		maior = num;
	if (dir < tamanho && heap[dir] > heap[maior])
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

void heap_sort_max (int heap[], int tamanho) 
{
	build_max_heap(heap, tamanho);
	for(int i = tamanho-1; i >= 1; i--)
	{
		trocar(heap, 0, i);
		tamanho = i;
		max_heapify(heap, tamanho, 0);
	}
}

int heap_maximum (int heap[])
{
	return heap != NULL ? heap[0] : 0;
}

void heap_increase_key (int heap[], int tamanho, int posicao, int chave)
{
	if(heap[posicao] > chave)
	{
		printf("O valor da chave é menor que a chave atual\n");
		return;
	}

	heap[posicao] = chave;
	for(int i = posicao; i > 0 && heap[pai(i)] < heap[i]; i = pai(i))
	{
		trocar(heap, i, pai(i));
	}
}

int heap_extract_max (int heap[], int *tamanho)
{
	if(*tamanho < 1)
		return 0;
	
	int max = heap[0];
	heap[0] = heap[*tamanho - 1];
	*tamanho -= 1;
	max_heapify(heap, *tamanho, 0);
	return max;
}

void max_heap_insert (int heap[], int *tamanho, int valor)
{
	*tamanho += 1;
	heap[*tamanho - 1] = -100000;
	heap_increase_key(heap, *tamanho, *tamanho-1, valor);
}

//Minimum
void min_heapify (int heap[], int tamanho, int num) 
{
	int menor;
	int esq = esquerda(num);
	int dir = direita(num);
	if(esq < tamanho && heap[esq] < heap[num])
		menor = esq;
	else
		menor = num;
	if (dir < tamanho && heap[dir] < heap[menor])
		menor = dir;
	if(menor != num)
	{
		trocar(heap, num, menor);
		min_heapify(heap, tamanho, menor);
	}
}

void build_min_heap (int heap[], int tamanho) 
{
	for(int i = tamanho/2 - 1; i >= 0; i--)
	{
		min_heapify(heap, tamanho, i);
	}
}

void heap_sort_min (int heap[], int tamanho) 
{
	build_min_heap(heap, tamanho);
	for(int i = tamanho-1; i >= 1; i--)
	{
		trocar(heap, 0, i);
		tamanho = i;
		min_heapify(heap, tamanho, 0);
	}
}

int heap_minimum (int heap[])
{
	return heap != NULL ? heap[0] : 0;
}

void heap_decrease_key (int heap[], int tamanho, int posicao, int chave)
{
	if(heap[posicao] < chave)
	{
		printf("O valor da chave é maior que a chave atual!\n");
		return;
	}

	heap[posicao] = chave;
	for(int i = posicao; i > 0 && heap[pai(i)] > heap[i]; i = pai(i))
	{
		trocar(heap, i, pai(i));
	}
}

int heap_extract_min (int heap[], int *tamanho)
{
	if(*tamanho < 1)
		return 0;
	int min = heap[0];
	heap[0] = heap[*tamanho - 1];
	*tamanho -= 1;
	min_heapify(heap, *tamanho, 0);
	return min;
}

void min_heap_insert (int heap[], int *tamanho, int valor)
{
	*tamanho += 1;
	heap[*tamanho - 1] = 100000;
	heap_decrease_key(heap, *tamanho, *tamanho-1, valor);
}