#include <iostream>
using namespace std;
/*----------------------------------------------------------------------------*/
struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode* treenodeptr;
// Typedef = onde tiver * substritui por treenodeptr
// Função que insere
void tInsere(treenodeptr &p, int x)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);
	else // insere na subarvore direita
		tInsere(p->dir, x);
}
/*----------------------------------------------------------------------------*/
// Função de busca
// Retorna Null caso não encontre
treenodeptr tPesq(treenodeptr p, int x)
{
	if (p == NULL) // elemento n~ao encontrado
		return NULL;
	else if (x == p->info) // elemento encontrado na raiz
		return p;
	else if (x < p->info) // procura na sub´arvore esquerda
		return tPesq(p->esq, x);
	else // procura na sub´arvore direita
		return tPesq(p->dir, x);
}
/*----------------------------------------------------------------------------*/
// Pré-Ordem
void contaPreOrdem(treenodeptr arvore, int &n)
{
	if (arvore != NULL)
	{
		n++;
		contaPreOrdem(arvore->esq, n);
		contaPreOrdem(arvore->dir, n);
	}
}
/*----------------------------------------------------------------------------*/
// Em-Ordem
void emOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << " ";
		emOrdem(arvore->dir);
	}
}
/*----------------------------------------------------------------------------*/
int folhas(treenodeptr arvore)
{
	if(arvore == NULL)
		return 0;
	else if(arvore->esq == NULL && arvore->dir == NULL)
		return 1;
	else
		return folhas(arvore->esq) + folhas(arvore->dir);
}
/*----------------------------------------------------------------------------*/
treenodeptr tMenor(treenodeptr &raiz)
{
	treenodeptr t;
	t = raiz;
	if (t->esq == NULL) // encontrou o menor valor
	{
		raiz = raiz->dir;
		return t;
	}
	else // continua a busca na sub´arvore esquerda
		return tMenor(raiz->esq);
}
// Remove
int tRemove(treenodeptr &raiz, int x)
{
	treenodeptr p;
	if (raiz == NULL) // ´arvore vazia
		return 1;
	if (x == raiz->info)
	{
		p = raiz;
		if (raiz->esq == NULL) // a raiz n~ao tem filho esquerdo
			raiz = raiz->dir;
		else if (raiz->dir == NULL) // a raiz n~ao tem filho direito
			raiz = raiz->esq;
		else // a raiz tem ambos os filhos
		{
			p = tMenor(raiz->dir);
			raiz->info = p->info;
		}
		delete p;
		return 0;
	}
	else if (x < raiz->info)
		return tRemove(raiz->esq, x);
	else
		return tRemove(raiz->dir, x);
}
/*----------------------------------------------------------------------------*/
void tDestruir (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}
/*----------------------------------------------------------------------------*/
int main()
{
	setlocale(LC_ALL, "Portuguese");
	treenodeptr arvore = NULL; // Ponteiro para a raiz
	int x; // Var Aux
	int rem; // Removendo nó

	// Inserindo dados na árvore
	cin >> x;
	while(x != 0)
	{
		tInsere(arvore, x);
		cin >> x;
	}

	// Removendo
	cin >> rem;
	while(tRemove(arvore, rem) == 0)
		tRemove(arvore, rem);
	emOrdem(arvore);
	tDestruir(arvore);

	rturn 0;
}