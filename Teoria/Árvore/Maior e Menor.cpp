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
// Fun��o que insere
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
// Fun��o de busca
// Retorna Null caso n�o encontre
treenodeptr tPesq(treenodeptr p, int x)
{
	if (p == NULL) // elemento n~ao encontrado
		return NULL;
	else if (x == p->info) // elemento encontrado na raiz
		return p;
	else if (x < p->info) // procura na sub�arvore esquerda
		return tPesq(p->esq, x);
	else // procura na sub�arvore direita
		return tPesq(p->dir, x);
}
/*----------------------------------------------------------------------------*/
// Pr�-Ordem
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
// Conta o n�mero de n�s da �rvore
int contaNos(treenodeptr arvore)
{
	int n = 0; // N�mero de n�s da �rvore
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
/*---------------------------------------------------------------------------*/
treenodeptr pMenor(treenodeptr arvore)
{
	if (arvore->esq == NULL)
		return arvore;
	else
		return pMenor(arvore->esq);
}
/*----------------------------------------------------------------------------*/
treenodeptr pMaior(treenodeptr arvore)
{
	if (arvore->dir == NULL)
		return arvore;
	else
		return pMaior(arvore->dir);
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
	treenodeptr maior;
	treenodeptr menor; // Maior e Menor

	// Inserindo dados na �rvore
	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}

	// Apresentando as sa�das
	maior = pMaior(arvore);
	menor = pMenor(arvore);
	
	cout << menor->info << " e " << maior->info << endl;

	return 0;
}