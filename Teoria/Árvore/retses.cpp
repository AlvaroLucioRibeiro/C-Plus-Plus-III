#include <iostream>
#include <iomanip>
using namespace std;
struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode* treenodeptr;
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
	else             // insere na subarvore direita
		tInsere(p->dir, x);
}
void PreOrdem (treenodeptr arvore, double &media)
{
	if (arvore != NULL)
	{
		PreOrdem(arvore->esq, media);
		PreOrdem(arvore->dir, media);
		media = media + arvore -> info;
	}
}
void contaPreOrdem (treenodeptr arvore, double &N)
{
	if (arvore != NULL)
	{
		N++;
		contaPreOrdem(arvore->esq, N);
		contaPreOrdem(arvore->dir, N);
	}
}
void tDestruir (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore == NULL;
}
int main()
{
	cout << fixed << setprecision(2);
	treenodeptr arvore = NULL; // ponteiro para a arvore
	int x;
	double media;
	double N;
	// Inserindo dados na arvore
	cin >> x;
	while (x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	PreOrdem (arvore, media);
	contaPreOrdem (arvore, N);
	cout << "Media: " << media / N << endl;
	tDestruir(arvore);
	return 0;
}
