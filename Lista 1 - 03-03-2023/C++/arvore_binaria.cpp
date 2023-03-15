#include "arvore_binaria.hpp"

/*========= Exercício 1 - pré-ordem ====
Considerando a árvore a seguir, defina a saída para os percursos:
• pré-ordem (R,E,D): a, b, d, c, e, f
• in-ordem (E,R,D): d, b, a, e, c, f
• pós-ordem (E,D,R): d, b, e, f, c, a*/

//========= Exercício 2 - pré-ordem ====
void Arvore::imprimeArvorePre(Arvore *arv)
{
    if(verificaVazio(arv))
    {
        return;
    }
    cout << arv->info << endl;
    imprimeArvorePre(arv->esq);
    imprimeArvorePre(arv->dir);
}

//========= Exercício 2 - in-ordem ====
void Arvore::imprimeArvoreInOrdem(Arvore *arv)
{
    if(verificaVazio(arv))
    {
        return;
    }
    imprimeArvorePre(arv->esq);
    cout << arv->info << endl;
    imprimeArvorePre(arv->dir);
}

//========= Exercício 2 - pós-ordem ====
void Arvore::imprimeArvorePos(Arvore *arv)
{
    if(verificaVazio(arv))
    {
        return;
    }
    imprimeArvorePos(arv->esq);
    imprimeArvorePos(arv->dir);
    cout << arv->info << endl;
}

//========= Exercício 3 - pertence ====
bool Arvore::pertenceArvore(Arvore *arv, string c)
{
	if(!verificaVazio(arv))
    {
		if(arv->info == c)
		{
			return true;
		}
		else
		{	
	    	if(pertenceArvore(arv->esq, c) || pertenceArvore(arv->dir, c))
				return true;
		}
    }
	return false;
}

//========= Exercício 4 - conta nós ====
int Arvore::contagemNos(Arvore *arv)
{
	int nos = 0;
	if(!verificaVazio(arv))
    {
		nos++;
	    nos += contagemNos(arv->esq);
	    nos += contagemNos(arv->dir);
    }
	return nos;
}

//========= Exercício 5 - calcula altura ====
int Arvore::calculaAlturaArvore(Arvore *arv)
{
	if(verificaVazio(arv))
		return -1;
	else
    {
		int altura_esq = calculaAlturaArvore(arv->esq);
        int altura_dir = calculaAlturaArvore(arv->dir);
        if(altura_esq > altura_dir)
			return altura_esq + 1;
		else
			return altura_dir + 1;
    }
}

//========= Exercício 6 - conta folhas ====
int Arvore::contagemFolhas(Arvore *arv)
{
	int folhas = 0;
	if(!verificaVazio(arv))
    {
		if(verificaVazio(arv->esq) && verificaVazio(arv->dir))
			folhas++;
		folhas += contagemFolhas(arv->esq);
    	folhas += contagemFolhas(arv->dir);
    }
	return folhas;
}

Arvore::Arvore(string inf, Arvore *e, Arvore *d)
{
    info = inf;
    esq = e;
    dir = d;
}

Arvore::~Arvore()
{
}

string Arvore::getInfo()
{
	return info;
}

void Arvore::setInfo(string inf)
{
	info = inf;
}

Arvore* Arvore::getEsquerda()
{
	return esq;
}

void Arvore::setEsquerda(Arvore* e)
{
	esq = e;
}

Arvore* Arvore::getDireita()
{
	return dir;
}

void Arvore::setDireita(Arvore* d)
{
	dir = d;
}

bool Arvore::verificaVazio(Arvore *arv)
{
    return(NULL == arv);
}

void Arvore::liberaArvore(Arvore *arv)
{
	if(!verificaVazio(arv))
    {
        liberaArvore(arv->esq);
        liberaArvore(arv->dir);
		cout << arv->info << endl;
        free(arv);
    }
}