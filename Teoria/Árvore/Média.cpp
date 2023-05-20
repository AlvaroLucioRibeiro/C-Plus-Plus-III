#include <iostream>
#include <iomanip>
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
void contaPreOrdem (treenodeptr arvore, double &N)
{
	if (arvore != NULL)
	{
		N++;
		contaPreOrdem(arvore->esq, N);
		contaPreOrdem(arvore->dir, N);
	}
}
/*----------------------------------------------------------------------------*/
void PreOrdem (treenodeptr arvore, double &media)
{
	if (arvore != NULL)
	{
		PreOrdem(arvore->esq, media);
		PreOrdem(arvore->dir, media);
		media = media + arvore -> info;
	}
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
	double Media; //Media 
	double n; // Dividendo

	// Inserindo dados na árvore
	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	// Chamandos a Funções
	PreOrdem(arvore, Media);
	contaPreOrdem(arvore, n);
	// Saída de Dados
	cout << fixed << setprecision(2);
	cout << "Media: " << Media / n << endl;
	
	tDestruir(arvore);

	return 0;
}