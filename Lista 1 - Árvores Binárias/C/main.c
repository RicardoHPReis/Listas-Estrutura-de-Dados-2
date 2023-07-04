#include "arvore_binaria.h"

/*========= Exercício 1 - pré-ordem ====
Considerando a árvore a seguir, defina a saída para os percursos:
• pré-ordem (R,E,D): a, b, d, c, e, f
• in-ordem (E,R,D): d, b, a, e, c, f
• pós-ordem (E,D,R): d, b, e, f, c, a*/

//========= Exercício 2 - pré-ordem ====
void imprimeArvorePre(Arvore *arv)
{
    if(verificaVazio(arv))
    {
        return;
    }
    printf("%c\n", arv->info);
    imprimeArvorePre(arv->esq);
    imprimeArvorePre(arv->dir);
}

//========= Exercício 2 - in-ordem ====
void imprimeArvoreInOrdem(Arvore *arv)
{
    if(verificaVazio(arv))
    {
        return;
    }
    imprimeArvorePre(arv->esq);
    printf("%c\n", arv->info);
    imprimeArvorePre(arv->dir);
}

//========= Exercício 2 - pós-ordem ====
void imprimeArvorePos(Arvore *arv)
{
    if(verificaVazio(arv))
    {
        return;
    }
    imprimeArvorePos(arv->esq);
    imprimeArvorePos(arv->dir);
    printf("%c\n", arv->info);
}

//========= Exercício 3 - pertence ====
int pertenceArvore(Arvore *arv, char c)
{
	if(!verificaVazio(arv))
    {
		if(arv->info == c)
		{
			return 1;
		}
		else
		{	
	    	if(pertenceArvore(arv->esq, c) || pertenceArvore(arv->dir, c))
				return 1;
		}
    }
	return 0;
}

//========= Exercício 4 - conta nós ====
int contagemNos(Arvore *arv)
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
int calculaAlturaArvore(Arvore *arv)
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
int contagemFolhas(Arvore *arv)
{
	int folhas = 0;
	if(!verificaVazio(arv))
    {
		if(verificaVazio(arv->esq) && verificaVazio(arv->dir))
		{
			folhas++;
		}
		folhas += contagemFolhas(arv->esq);
    	folhas += contagemFolhas(arv->dir);
    }
	return folhas;
}

Arvore* constroiArvore(char info, Arvore *e, Arvore *d)
{
    Arvore *no;
	no = (Arvore*) malloc (sizeof(Arvore));
    no->info = info;
    no->esq = e;
    no->dir = d;
    return no;
}

int verificaVazio(Arvore *arv)
{
    return(NULL == arv);
}

void liberaArvore(Arvore *arv)
{
	if(!verificaVazio(arv))
    {
        liberaArvore(arv->esq);
        liberaArvore(arv->dir);
		printf("Apagou a letra %c\n", arv->info);
        free(arv);
    }
}

int main()
{
    Arvore *arv, *a0, *a1, *a2, *a3, *a4, *a5;
	int altura, folhas, nos;
    a0 = constroiArvore('A', NULL, NULL);
	a1 = constroiArvore('B', NULL, a0);
    a2 = constroiArvore('C', NULL, a1);
    a3 = constroiArvore('D', NULL, NULL);
    a4 = constroiArvore('E', NULL, NULL);
    a5 = constroiArvore('F', a3, a4);
    arv = constroiArvore('G', a2, a5);
	
	printf("Pré-Ordem:\n");
    imprimeArvorePre(arv);
	
	printf("\n\nIn-Ordem:\n");
	imprimeArvoreInOrdem(arv);
	
	printf("\n\nPos-Ordem:\n");
    imprimeArvorePos(arv);
	
	printf("\nPertence F? ");
	if(pertenceArvore(arv, 'F'))
	{
		printf("Verdade");
	}
	else
	{
		printf("Falso");
	}
	printf("\nPertence Z? ");
	if(pertenceArvore(arv, 'Z'))
	{
		printf("Verdade\n\n");
	}
	else
	{
		printf("Falso\n\n");
	}
	
	nos = contagemNos(arv);
	printf("N° de nós: %d\n", nos);
	
	altura = calculaAlturaArvore(arv);
	printf("Altura da árvore: %d\n", altura);
	
	folhas = contagemFolhas(arv);
	printf("N° de folhas: %d\n", folhas);
	
	printf("\n\nApagar:\n");
	liberaArvore(arv);
	
    return 0;
}