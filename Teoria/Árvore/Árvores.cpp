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

/*----------------------------------------------------------------------------*/
int treenodeptr_pMaior(treenodeptr arvore)
{
	if (arvore->dir == NULL)
		return arvore->info;
	else
		return treenodeptr_pMaior(arvore->dir);
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
	int x; // Var Aux - Var. para entrada: 12 10 20 5 11 0
	int n; // numero de nós inseridos

	// Inserindo dados na árvore
	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}

	// Contado nós
	n = treenodeptr_pMaior(arvore);
	cout << n;

	/*  Percurso pré-ordem
		cout << "Pré-Ordem: " << endl;
		preOrdem(arvore);

		// Percurso em-ordem
		cout << "em-Ordem: " << endl;
		emOrdem(arvore);

		// Percurso pós-ordem
		cout << "Pós-Ordem: " << endl;
		posOrdem(arvore);*/
	return 0;
}
