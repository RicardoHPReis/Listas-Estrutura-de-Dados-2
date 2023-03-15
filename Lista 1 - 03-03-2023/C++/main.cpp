#include "arvore_binaria.hpp"

int main()
{
    Arvore *arv, *a0, *a1, *a2, *a3, *a4, *a5;
    a0 = new Arvore("A", NULL, NULL);
	a1 = new Arvore("B", NULL, a0);
    a2 = new Arvore("C", NULL, a1);
    a3 = new Arvore("D", NULL, NULL);
    a4 = new Arvore("E", NULL, NULL);
    a5 = new Arvore("F", a3, a4);
    arv = new Arvore("G", a2, a5);
	
	cout << "Pré-Ordem:" << endl;
    arv->imprimeArvorePre(arv);

	cout << "\n\nIn-Ordem:" << endl;
	arv->imprimeArvoreInOrdem(arv);

	cout << "\n\nPós-Ordem:" << endl;
    arv->imprimeArvorePos(arv);
	
	printf("\nPertence F? ");
	cout << arv->pertenceArvore(arv, "F") << endl;
	cout << arv->pertenceArvore(arv, "Z") << endl;
	
	cout << "N° de nós:" << arv->contagemNos(arv) << endl;
		
	cout << "Altura da árvore:" << arv->calculaAlturaArvore(arv) << endl;
	
	cout << "N° de folhas:" << arv->contagemFolhas(arv) << endl;
	
	cout << "\n\nApagar:" << endl;
	arv->liberaArvore(arv);
	
    return 0;
}