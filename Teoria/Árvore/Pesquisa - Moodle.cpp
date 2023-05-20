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
int main()
{
	setlocale(LC_ALL, "Portuguese");
	treenodeptr arvore = NULL; // Ponteiro para a raiz
	treenodeptr aux;
	int n; // Número de entradas
	int i; // Contador
	int x, y; // Insere e Procura
	/*------------------------------------------------------------------------*/
	// Entrando com dados
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> x;
		tInsere(arvore, x);
	}
	cin >> y;
	aux = tPesq(arvore, y);
	/*------------------------------------------------------------------------*/
	// Saída de dados
	if (aux != NULL)
		cout << "Encontrado" << endl;
	else
		cout << "Nao encontrado" << endl;
	return 0;
}
