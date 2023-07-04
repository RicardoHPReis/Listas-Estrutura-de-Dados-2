#include "stdafx.hpp"

int pai (int num) ;
int esquerda (int num);
int direita (int num);
void trocar (int heap[], int a, int b);
void imprimir (int heap[], int tamanho);
void imprimir_nivel (int heap[], int tamanho);

//Maximum
void max_heapify (int heap[], int tamanho, int num);
void build_max_heap (int heap[], int tamanho);
void heap_sort_max (int heap[], int tamanho);
int heap_maximum (int heap[]);
void heap_increase_key (int heap[], int tamanho, int posicao, int chave);
int heap_extract_max (int heap[], int *tamanho);
void max_heap_insert (int heap[], int *tamanho, int valor);

//Minimum
void min_heapify (int heap[], int tamanho, int num);
void build_min_heap (int heap[], int tamanho);
void heap_sort_min (int heap[], int tamanho);
int heap_minimum (int heap[]);
void heap_decrease_key (int heap[], int tamanho, int posicao, int chave);
int heap_extract_min (int heap[], int *tamanho);
void min_heap_insert (int heap[], int *tamanho, int valor);