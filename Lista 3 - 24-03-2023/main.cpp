#include "arvore_int.hpp"
#include "arvore_string.hpp"

int main()
{
	Arvore_Int *arvI = NULL;
	Arvore_String *arvC = NULL;
	Arvore_String *arvS = NULL;
	
	//========= Exercício 1 - Inserção da Árvore AVL ====
 	arvC = arvC->inserirElemento (arvC, "Q");
	arvC = arvC->inserirElemento (arvC, "Z");
	arvC = arvC->inserirElemento (arvC, "W");
	arvC = arvC->inserirElemento (arvC, "Y");
	arvC = arvC->inserirElemento (arvC, "T");
	arvC = arvC->inserirElemento (arvC, "M");
	arvC = arvC->inserirElemento (arvC, "E");
	arvC = arvC->inserirElemento (arvC, "W");
	arvC = arvC->inserirElemento (arvC, "X");
	arvC = arvC->inserirElemento (arvC, "S");
	arvC = arvC->inserirElemento (arvC, "F");
	arvC = arvC->inserirElemento (arvC, "G");
	arvC = arvC->inserirElemento (arvC, "A");
	arvC = arvC->inserirElemento (arvC, "H");
	arvC = arvC->inserirElemento (arvC, "N");
	arvC = arvC->inserirElemento (arvC, "O");
	arvC = arvC->inserirElemento (arvC, "P");
	arvC = arvC->inserirElemento (arvC, "R");
	
	arvC->imprimirArvorePorAltura(arvC, arvC->calculaAltura(arvC));

	
	//========= Exercício 2 - Remoção da Árvore AVL ====
	for(int i=1; i<=40; i++)
	{		
 		arvI = arvI->inserirElemento(arvI, i);
	}
	arvI->imprimirArvorePorAltura(arvI, arvI->calculaAltura(arvI));

	arvI = arvI->removerElemento(arvI, 1);
	arvI->imprimirArvorePorAltura(arvI, arvI->calculaAltura(arvI));

	
	//========= Exercício 3 - Árvore AVL com Palavras ====
	arvS = arvS->inserirElemento (arvS, "Pedro");
	arvS = arvS->inserirElemento (arvS, "Joaquim");
	arvS = arvS->inserirElemento (arvS, "Sandra");
	arvS = arvS->inserirElemento (arvS, "Daniele");
	arvS = arvS->inserirElemento (arvS, "Jhony");
	arvS = arvS->inserirElemento (arvS, "Bruna");
	arvS = arvS->inserirElemento (arvS, "Roberto");
	arvS = arvS->inserirElemento (arvS, "Ricardo");
	arvS = arvS->inserirElemento (arvS, "Rafael");
	arvS = arvS->inserirElemento (arvS, "Hayana");
	arvS = arvS->inserirElemento (arvS, "Lorena");
	arvS = arvS->inserirElemento (arvS, "Mariana");
	arvS = arvS->inserirElemento (arvS, "Marina");
	arvS = arvS->inserirElemento (arvS, "Roberta");
	arvS = arvS->inserirElemento (arvS, "Chayene");
	arvS = arvS->inserirElemento (arvS, "Edmundo");
	
	arvS->imprimirArvorePorAltura(arvS, arvS->calculaAltura(arvS));
	
	arvI->liberaArvore(arvI);
	arvC->liberaArvore(arvC);
	arvS->liberaArvore(arvS);
	
    return 0;
}