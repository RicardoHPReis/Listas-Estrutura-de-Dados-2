#include "hash.hpp"
#define EMPTY -99999

Hash* criar_hash (int tamanho) 
{ 
	Hash *hash = (Hash*) malloc (tamanho * sizeof(Hash));
	for (int i = 0; i < tamanho; i++) 
	{
		hash[i].chave = EMPTY;
	}
	return hash;
}

int buscar_hash (Hash *hash, int tamanho, int chave, int modo) 
{
	int j = 0, i = 0;
	do 
	{
    	switch (modo)
		{
			case 1:
				j = sondagem_linear(chave, i, tamanho);
				break;
			case 2:
				j = sondagem_quadratica(chave, i, tamanho);
				break;
			case 3:
				j = hash_duplo(chave, i, tamanho);
				break;
			default:
				j = sondagem_linear(chave, i, tamanho);
				break;
		}
		
    	printf("Testando chave: %d\n", j);
    	if (hash[j].chave == chave) 
			return j;
    	i++;
	} while ((i != tamanho) || (hash[j].chave != EMPTY));
}

int hash_inserir (Hash *hash, int tamanho, int chave, int modo, int *colisoes) 
{
	int j = 0, i = 0;
	do
	{
		switch (modo)
		{
			case 1:
				j = sondagem_linear(chave, i, tamanho);
				break;
			case 2:
				j = sondagem_quadratica(chave, i, tamanho);
				break;
			case 3:
				j = hash_duplo(chave, i, tamanho);
				break;
			default:
				j = sondagem_linear(chave, i, tamanho);
				break;
		}
		
    	if (hash[j].chave == EMPTY) 
		{
        	hash[j].chave = chave;
        	return j;
      	}
    	else
        	(*colisoes)++;
		
    	i++;
   } while (i != tamanho);
}

int sondagem_linear (int chave, int num, int tamanho) 
{
	return (chave % tamanho + num) % tamanho;
}

int sondagem_quadratica (int chave, int num, int tamanho) 
{
	return (chave % tamanho + 1*num + 3*(num*num)) % tamanho;
}

int hash_duplo (int chave, int num, int tamanho) 
{
	return (chave % tamanho + num*(1 + chave % (tamanho-1))) % tamanho;
}

void imprimir_hash (Hash *hash, int tamanho) 
{
	for (int i = 0; i < tamanho; i++) 
	{
    	if (hash[i].chave != EMPTY)
        	printf("%2d - %d\n", i, hash[i].chave);
    	else 
        	printf("%2d -   \n", i);
	}
	printf("\n");
}

void liberar_hash (Hash *hash) 
{
	free(hash);
}