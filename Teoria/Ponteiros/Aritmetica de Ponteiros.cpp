#include <iostream>
using namespace std;
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	// Todo vetor é um ponteiro (Ex.: 0x67Fef4)
	int vetor[3];
	int *p;
	
	vetor[0] = 4;
	vetor[1] = -2;
	vetor[2] = 7;
	
	p = vetor;

	cout << "vetor: " << vetor << endl;
	cout << "*vetor: " << *vetor << endl;
	
	cout << "*p: " << *p << endl;
	// Esse p++, ele vai pegar o endereço e deslocar para direita no tamanho de um inteiro 
	p++; 
	cout << "*p (Após um p++): " << *p << endl;
	
	p++;
	cout << "*p (Após dois p++): " << *p << endl;
	
	p = p - 2;
	cout << "*p (Voltando no valor inicial): " << *p << endl;
	
	// Se caso continuar esse lixo de memória entra como resultado
	
	return 0;
}