#include "stdafx.hpp"

class Arvore_String
{
private:
	string info;
    int altura;
	Arvore_String* esq;
    Arvore_String* dir;

public:
	Arvore_String(string inf, int alt, Arvore_String *e, Arvore_String *d);
	~Arvore_String();
	
	string getInfo();
	void setInfo(string inf);
	int getAltura();
	void setAltura(int alt);
	Arvore_String* getEsquerda();
	void setEsquerda(Arvore_String* e);
	Arvore_String* getDireita();
	void setDireita(Arvore_String* d);

	bool verificaVazio(Arvore_String *arv);
	void imprimeArvorePre(Arvore_String *arv);
	void imprimir(Arvore_String *arv, int alt);
	void imprimirArvorePorAltura(Arvore_String *arv, int alt);
	void liberaArvore(Arvore_String *arv);
	Arvore_String* inserirElemento(Arvore_String *arv, string n);
	int buscarElemento(Arvore_String* arv, string n);
	Arvore_String* removerElemento(Arvore_String *arv, string n);

	///////
	Arvore_String* atualizarArvoreEsquerda(Arvore_String *arv);
	Arvore_String* atualizarArvoreDireita(Arvore_String *arv);
	int verificarEquilibrio(Arvore_String *arv);
	int calculaAltura(Arvore_String *arv);
	Arvore_String* rotacaoSimplesEsquerda(Arvore_String *arv);
	Arvore_String* rotacaoSimplesDireita(Arvore_String *arv);
	Arvore_String* rotacaoDuplaEsquerda(Arvore_String *arv);
	Arvore_String* rotacaoDuplaDireita(Arvore_String *arv);
};