#include "stdafx.hpp"

typedef struct {
   int chave;
} Hash;

int sondagem_linear (int chave, int num, int tamanho);
int sondagem_quadratica (int chave, int num, int tamanho);
int hash_duplo (int chave, int num, int tamanho);
Hash* criar_hash (int tamanho);
int buscar_hash (Hash *hash, int tamanho, int chave, int modo);
int hash_inserir (Hash *hash, int tamanho, int chave, int modo, int *colisoes);
void imprimir_hash (Hash *hash, int tamanho);
void liberar_hash (Hash *hash);