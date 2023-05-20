#include<iostream>
#include<iomanip>
#include<list>
using namespace std;

struct treenode
{
    int info;
    treenode *esq;
    treenode *dir;
};
typedef treenode *treenodeptr;

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

float calcMedia(treenodeptr t)
{
    list<treenodeptr> q; // fila auxiliar
	treenodeptr n = t; // ponteiro para varrer a árvore
	int soma=0; // soma dos nós
	int nos=0; // número de nós
	
	if (t != NULL)
	{
		q.push_front(n);
		while (!q.empty())
		{
			n = q.front();
			q.pop_front();
			if (n->esq != NULL)
				q.push_back(n->esq);
			if (n->dir != NULL)
				q.push_back(n->dir);
			soma += n->info;
			nos++;
		}
	}
	
	return (float)soma/nos;
}

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

int main()
{
    treenodeptr arvore=NULL; // ponteiro para a arvore
    int x; // var aux para leitura dos dados
    
    // Lendo dados e armazenando na arvore
    cin >> x;
    while(x!=-1)
    {
        tInsere(arvore,x);
        cin >> x;
    }
    
    // Mostrando media dos elementos da arvore
    cout << fixed << setprecision(2);
    cout << "media = " << calcMedia(arvore) << endl;
    
    // Liberando a memoria usada pela arvore
    tDestruir(arvore);
    
    return 0;
}