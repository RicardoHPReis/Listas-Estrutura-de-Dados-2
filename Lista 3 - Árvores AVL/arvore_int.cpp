#include "arvore_int.hpp"

Arvore_Int::Arvore_Int(int inf, int alt, Arvore_Int *e, Arvore_Int *d)
{
    info = inf;
	altura = alt;
    esq = e;
    dir = d;
}

Arvore_Int::~Arvore_Int()
{
}

int Arvore_Int::getInfo()
{
	return info;
}

void Arvore_Int::setInfo(int inf)
{
	info = inf;
}

int Arvore_Int::getAltura()
{
	return altura;
}

void Arvore_Int::setAltura(int alt)
{
	altura = alt;
}

Arvore_Int* Arvore_Int::getEsquerda()
{
	return esq;
}

void Arvore_Int::setEsquerda(Arvore_Int* e)
{
	esq = e;
}

Arvore_Int* Arvore_Int::getDireita()
{
	return dir;
}

void Arvore_Int::setDireita(Arvore_Int* d)
{
	dir = d;
}

void Arvore_Int::imprimeArvorePre(Arvore_Int *arv)
{
    if(arv->verificaVazio(arv))
    {
        return;
    }
    cout << arv->info << endl;
    arv->esq->imprimeArvorePre(arv->esq);
    arv->dir->imprimeArvorePre(arv->dir);
}

bool Arvore_Int::verificaVazio(Arvore_Int *arv)
{
    return(NULL == arv);
}

void Arvore_Int::liberaArvore(Arvore_Int *arv)
{
	if(!arv->verificaVazio(arv))
    {
        arv->esq->liberaArvore(arv->esq);
        arv->dir->liberaArvore(arv->dir);
		//cout << arv->info << endl;
        delete(arv);
    }
}

void Arvore_Int::imprimir(Arvore_Int *arv, int alt)
{
	if(arv->verificaVazio(arv) || alt < 0)
		return;
	else if(alt == 0)
		cout << arv->info << "	";
	else
	{
		alt--;
		arv->esq->imprimir(arv->esq, alt);
		cout << "	";
		arv->dir->imprimir(arv->dir, alt);
	}
}

void Arvore_Int::imprimirArvorePorAltura(Arvore_Int *arv, int alt)
{
	for(int i = 0; i < alt; i++)
	{
		for(int j = alt-1; j >= i; j--)
		{
			cout << "	";
		}
		imprimir(arv, i);
		cout << endl;
	}
	cout << endl << endl;
}

Arvore_Int* Arvore_Int::inserirElemento(Arvore_Int *arv, int n)
{
	if(arv->verificaVazio(arv))
	{
		arv = new Arvore_Int(n, 0, NULL, NULL);
		//cout << "Criou " << n << endl;
	}
	else if(arv->info > n)
		arv->esq = arv->esq->inserirElemento(arv->esq, n);
	else
		arv->dir = arv->dir->inserirElemento(arv->dir, n);
	
	arv = arv->atualizarArvoreEsquerda(arv);
	arv = arv->atualizarArvoreDireita(arv);
	
	return arv;
}

int Arvore_Int::buscarElemento(Arvore_Int* arv, int n)
{
	if(arv->verificaVazio(arv))
		return 0;
	else if (arv->info > n)
		arv->esq->buscarElemento(arv->esq, n);
	else if (arv->info < n)
		arv->dir->buscarElemento(arv->dir, n);
	else
		return 1;
}

Arvore_Int* Arvore_Int::removerElemento(Arvore_Int *arv, int n)
{
	if(arv->verificaVazio(arv))
		return NULL;
	else
	{
		if (arv->info > n)
			arv->esq = arv->esq->removerElemento(arv->esq, n);
		else if (arv->info < n)
			arv->dir = arv->dir->removerElemento(arv->dir, n);
		else
		{
			if(arv->esq->verificaVazio(arv->esq) && arv->dir->verificaVazio(arv->dir))
			{
				cout << "Excluiu " << arv->info << endl;
				delete(arv);
				arv = NULL;
			}
			else if(arv->esq->verificaVazio(arv->esq))
			{
				Arvore_Int *aux;
				aux = arv;
				arv = arv->dir;
				cout << "Excluiu " << arv->info << endl;
				delete(aux);
				aux = NULL;
			}
			else if(arv->dir->verificaVazio(arv->dir))
			{
				Arvore_Int *aux;
				aux = arv;
				arv = arv->esq;
				cout << "Excluiu " << arv->info << endl;
				delete(aux);
				aux = NULL;
			}
			else
			{
				Arvore_Int *aux;
				aux = arv->esq;
				while(!aux->verificaVazio(aux->dir))
				{
					aux = aux->dir;
				}
				arv->info = aux->info;
				aux->info = n;
				arv->esq = arv->esq->removerElemento(arv->esq, n);
			}
			/*else
			{
				Arvore_Int *aux;
				aux = arv->dir;
				while(!aux->verificaVazio(aux->dir))
				{
					aux = aux->esq;
				}
				arv->info = aux->info;
				aux->info = n;
				arv->dir = arv->dir->removerElemento(arv->dir, n);
			}*/
		}
	}

	if(!arv->verificaVazio(arv))
	{
		arv = arv->atualizarArvoreEsquerda(arv);
		arv = arv->atualizarArvoreDireita(arv);
	}
	
	return arv;
}

Arvore_Int* Arvore_Int::atualizarArvoreEsquerda(Arvore_Int *arv)
{
	arv->altura = arv->calculaAltura(arv);
	if(arv->verificarEquilibrio(arv) <= -2)
	{
		if(arv->esq->verificarEquilibrio(arv->esq) <= 0)
			arv = arv->rotacaoSimplesDireita(arv);
		else
			arv = arv->rotacaoDuplaDireita(arv);
	}
	return arv;
}

Arvore_Int* Arvore_Int::atualizarArvoreDireita(Arvore_Int *arv)
{
	arv->altura = arv->calculaAltura(arv);
	if(arv->verificarEquilibrio(arv) >= 2)
	{
		if(arv->dir->verificarEquilibrio(arv->dir) >= 0)
			arv = arv->rotacaoSimplesEsquerda(arv);
		else
			arv = arv->rotacaoDuplaEsquerda(arv);
	}
	return arv;
}

int Arvore_Int::verificarEquilibrio(Arvore_Int *arv)
{
	return (arv->dir->calculaAltura(arv->dir) - arv->esq->calculaAltura(arv->esq));
}

int Arvore_Int::calculaAltura(Arvore_Int *arv)
{
	if(arv->verificaVazio(arv))
		return -1;
	else
    {
		int altura_esq = arv->esq->calculaAltura(arv->esq);
        int altura_dir = arv->dir->calculaAltura(arv->dir);
        if(altura_esq > altura_dir)
			return altura_esq + 1;
		else
			return altura_dir + 1;
    }
}

Arvore_Int* Arvore_Int::rotacaoSimplesEsquerda(Arvore_Int *arv)
{
	Arvore_Int *aux = arv->dir;
	arv->dir = aux->esq;
	aux->esq = arv;
	arv->altura = arv->verificarEquilibrio(arv);
	aux->altura = aux->verificarEquilibrio(aux);
	return aux;
}

Arvore_Int* Arvore_Int::rotacaoSimplesDireita(Arvore_Int *arv)
{
	Arvore_Int *aux = arv->esq;
	arv->esq = aux->dir;
	aux->dir = arv;
	arv->altura = arv->verificarEquilibrio(arv);
	aux->altura = aux->verificarEquilibrio(aux);
	return aux;
}

Arvore_Int* Arvore_Int::rotacaoDuplaEsquerda(Arvore_Int *arv)
{
	arv->dir = arv->dir->rotacaoSimplesDireita(arv->dir);
	return arv->rotacaoSimplesEsquerda(arv);
}

Arvore_Int* Arvore_Int::rotacaoDuplaDireita(Arvore_Int *arv)
{
	arv->esq = arv->esq->rotacaoSimplesEsquerda(arv->esq);
	return arv->rotacaoSimplesDireita(arv);
}