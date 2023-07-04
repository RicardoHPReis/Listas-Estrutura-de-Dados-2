#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Arvore
{
private:
    string info;
    Arvore* esq;
    Arvore* dir;

public:
	Arvore(string info, Arvore *e, Arvore *d);
	~Arvore();
	
	string getInfo();
	void setInfo(string inf);
	Arvore* getEsquerda();
	void setEsquerda(Arvore* e);
	Arvore* getDireita();
	void setDireita(Arvore* d);

	bool verificaVazio(Arvore *arv);
	void imprimeArvorePre(Arvore *arv);
	void imprimeArvoreInOrdem(Arvore *arv);
	void imprimeArvorePos(Arvore *arv);
	bool pertenceArvore(Arvore *arv, string c);
	int contagemNos(Arvore *arv);
	int calculaAlturaArvore(Arvore *arv);
	int contagemFolhas(Arvore *arv);
	void liberaArvore(Arvore *arv);
};