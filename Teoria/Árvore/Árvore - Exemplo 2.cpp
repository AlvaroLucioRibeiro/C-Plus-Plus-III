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
/*----------------------------------------------------------------------------*/
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
// Retorna Null caso não encontrado
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
int main()
{
	setlocale(LC_ALL, "Portuguese");
	treenodeptr arvore = NULL; // Ponteiro para a raiz
	treenodeptr aux;
	int x;
	/*------------------------------------------------------------------------*/
	// Entrando com dados
	tInsere(arvore, 14);
	tInsere(arvore, 4);
	tInsere(arvore, 18);
	tInsere(arvore, 5);
	x = 4;
	aux = tPesq(arvore, x);
	if (aux != NULL)
		cout << aux->info << endl;
	else
		cout << x << " não encontrado" << endl;
	/*------------------------------------------------------------------------*/
	/*// Mostrando a árvore
	cout << "Raiz: " << arvore->info << endl;
	cout << "Filho esquerdo: " << (arvore->esq)->info << endl;
	cout << "Filho direito: " << (arvore->dir)->info << endl;
	cout << "Filho esquerdo -> direito: " << (arvore->esq->dir)->info << endl;*/
	return 0;
}
