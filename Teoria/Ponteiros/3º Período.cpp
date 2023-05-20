#include <iostream>
using namespace std;

struct dado
{
	int info1;
	int info2;  
};

int main( )
{
	setlocale(LC_ALL, "Portuguese");
	dado *produto = NULL; // Struct
	// Null � uma constante que vale 0 em c++

	// Alocando mem�ria	
	produto = new dado;
	// new ele cria um espa�o de mem�ria 
	
	// Inserindo dados
	// -> aponta para o valor
	produto->info1= 2;
	produto->info2 = 3;
	
	// Mostrando dados
	cout << "info1: " << produto->info1 << endl;
	cout << "info2: " << produto->info2 << endl;
	cout << endl;
	
	// Liberando mem�ria
	delete produto;
	
	return 0;
}