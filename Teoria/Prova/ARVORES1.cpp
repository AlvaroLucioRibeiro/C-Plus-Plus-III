#include<iostream>
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

void emOrdemImpar (treenodeptr arvore)
{
    if (arvore != NULL)
    {
        emOrdemImpar(arvore->esq);
        if(arvore->info%2==1)
            cout << arvore->info << endl;
        emOrdemImpar(arvore->dir);
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
    
    // Mostrando elementos impares e ordem crescente
    emOrdemImpar(arvore);
    
    // Liberando a memoria usada pela arvore
    tDestruir(arvore);
    
    return 0;
}