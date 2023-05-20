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
void preOrdem (treenodeptr arvore, int &cont, int pesq, bool &conf)
{
	if (arvore != NULL)
	{
		if(arvore->info == pesq)
            conf = true;
        if(!conf)
            cont++;
		preOrdem(arvore->esq, cont, pesq, conf);
		preOrdem(arvore->dir, cont, pesq, conf);
	}
}
/*----------------------------------------------------------------------------*/
// Em-Ordem
void emOrdem (treenodeptr arvore, int &cont, int pesq, bool &conf)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq, cont, pesq, conf);
		if(arvore->info == pesq)
            conf = true;
        if(!conf)
            cont++;
		emOrdem(arvore->dir, cont, pesq, conf);
	}
}
/*----------------------------------------------------------------------------*/
// Pos-Ordem
void posOrdem (treenodeptr arvore, int &cont, int pesq, bool &conf)
{
	if (arvore != NULL)
	{
		posOrdem(arvore->esq, cont, pesq, conf);
		posOrdem(arvore->dir, cont, pesq, conf);
		if(arvore->info == pesq)
			conf = true;
		if(!conf)
			cont++;
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
	int x; // Var Aux para entrada
	int cPre = 0, cPos = 0, cEm = 0; // Contadores
	int pesq; // Var aux para pesquisa
	bool conf = false; // Var booleana confirma

	// Inserindo dados na árvore
	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	cin >> pesq;

	// Percurso pré -ordem
	preOrdem(arvore, cPre, pesq, conf);
	conf = false;
	// Percurso em-ordem
	emOrdem(arvore, cEm, pesq, conf);
	conf = false;
	// Percurso pós-ordem
	posOrdem(arvore, cPos, pesq, conf);

	// Apresentando a saída
	if(cPre < cEm)
	{
		if(cPre < cPos)
			cout << "Pre" << endl;
		else
			cout << "Pos" << endl;
	}
	else
	{
		if(cEm < cPos)
			cout << "Em" << endl;
		else
			cout << "Pos" << endl;
	}

	// Destruido a arvore
	tDestruir(arvore);

	return 0;
}
