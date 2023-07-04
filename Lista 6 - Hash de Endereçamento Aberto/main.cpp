#include "hash.hpp"

int main() 
{
	//Execício 3
	int colisoes = 0;
	int modo = 0;
	int tamanho = 11;

	cout << "1 - Linear" << endl;
	cout << "2 - Quadrática" << endl;
	cout << "3 - Hash Duplo" << endl;
	cout << "Digite um modo de sondagem de hash: ";
	cin >> modo;
	cout << endl;
	
	Hash *hash = criar_hash(tamanho);
	hash_inserir(hash, tamanho, 10, modo, &colisoes);
	hash_inserir(hash, tamanho, 22, modo, &colisoes);
	hash_inserir(hash, tamanho, 31, modo, &colisoes);
	hash_inserir(hash, tamanho, 4, modo, &colisoes);
	hash_inserir(hash, tamanho, 15, modo, &colisoes);
	hash_inserir(hash, tamanho, 28, modo, &colisoes);
	hash_inserir(hash, tamanho, 17, modo, &colisoes);
	hash_inserir(hash, tamanho, 88, modo, &colisoes);
	hash_inserir(hash, tamanho, 59, modo, &colisoes);
	
	cout << "Número de colisões: " << colisoes << endl;
	imprimir_hash(hash, tamanho);
	liberar_hash(hash);
	return 0;
}