#include "stdafx.hpp"

int pai (int num) ;
int esquerda (int num);
int direita (int num);
void trocar (int heap[], int a, int b);
void imprimir (int heap[], int tamanho);
void imprimir_nivel (int heap[], int tamanho);
void max_heapify (int heap[], int tamanho, int num);
void build_max_heap (int heap[], int tamanho);
void heap_sort (int heap[], int tamanho);