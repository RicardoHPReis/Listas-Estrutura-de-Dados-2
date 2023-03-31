#include "stdafx.hpp"

class Arvore_Int
{
private:
	int info;
    int altura;
	Arvore_Int* esq;
    Arvore_Int* dir;

public:
	Arvore_Int(int inf, int alt, Arvore_Int *e, Arvore_Int *d);
	~Arvore_Int();
	
	int getInfo();
	void setInfo(int inf);
	int getAltura();
	void setAltura(int alt);
	Arvore_Int* getEsquerda();
	void setEsquerda(Arvore_Int* e);
	Arvore_Int* getDireita();
	void setDireita(Arvore_Int* d);

	bool verificaVazio(Arvore_Int *arv);
	void imprimeArvorePre(Arvore_Int *arv);
	void imprimirArvorePorAltura(Arvore_Int *arv, int alt);
	void imprimir(Arvore_Int *arv, int alt);
	void liberaArvore(Arvore_Int *arv);
	Arvore_Int* inserirElemento(Arvore_Int *arv, int n);
	int buscarElemento(Arvore_Int* arv, int n);
	Arvore_Int* removerElemento(Arvore_Int *arv, int n);

	///////
	Arvore_Int* atualizarArvoreEsquerda(Arvore_Int *arv);
	Arvore_Int* atualizarArvoreDireita(Arvore_Int *arv);
	int verificarEquilibrio(Arvore_Int *arv);
	int calculaAltura(Arvore_Int *arv);
	Arvore_Int* rotacaoSimplesEsquerda(Arvore_Int *arv);
	Arvore_Int* rotacaoSimplesDireita(Arvore_Int *arv);
	Arvore_Int* rotacaoDuplaEsquerda(Arvore_Int *arv);
	Arvore_Int* rotacaoDuplaDireita(Arvore_Int *arv);
};