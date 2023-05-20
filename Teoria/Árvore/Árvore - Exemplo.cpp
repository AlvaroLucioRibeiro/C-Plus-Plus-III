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

int main()
{
	setlocale(LC_ALL, "Portuguese");
	treenodeptr arvore = NULL; // Ponteiro para a raiz
	int x; // Var. aux. para inserir dados

	/*------------------------------------------------------------------------*/
	x = 14;
	arvore = new treenode; // Alocando memória
	arvore->info = x; // Preenchendo campo info
	arvore->esq = NULL;
	arvore->dir = NULL;
	/*------------------------------------------------------------------------*/
	x = 4; // Filho esquerdo
	arvore->esq = new treenode;
	(arvore->esq)->info = x;
	(arvore->esq)->esq = NULL;
	(arvore->esq)->dir = NULL;
	/*------------------------------------------------------------------------*/
	x = 18; // Filho direito 
	arvore->dir = new treenode;
	(arvore->dir)->info = x;
	(arvore->dir)->esq = NULL;
	(arvore->dir)->dir = NULL;
	/*------------------------------------------------------------------------*/
	// Mostrando a árvore
	cout << "Raiz: " << arvore->info << endl;
	cout << "Filho esquerdo: " << (arvore->esq)->info << endl;
	cout << "Filho direito: " << (arvore->dir)->info << endl;
	
	return 0;
}
