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
// Conta o número de nós da árvore
int contaNos(treenodeptr arvore)
{
	int n = 0; // Número de nós da árvore
	contaPreOrdem(arvore, n);
	return n;
}
/*----------------------------------------------------------------------------*/
// Em-Ordem
void emOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << endl;
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
void posOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		posOrdem(arvore->esq);
		posOrdem(arvore->dir);
		cout << arvore->info << endl;
	}
}
/*----------------------------------------------------------------------------*/
int main()
{
	setlocale(LC_ALL, "Portuguese");
	treenodeptr arvore = NULL; // Ponteiro para a raiz
	int x; // Var Aux
	int res; // Resultado - Número de Folhas

	// Inserindo dados na árvore
	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}

	// Contado nós
	res = folhas(arvore);
	cout << res << endl;

	return 0;
}
