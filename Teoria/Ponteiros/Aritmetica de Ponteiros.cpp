#include <iostream>
using namespace std;
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	// Todo vetor � um ponteiro (Ex.: 0x67Fef4)
	int vetor[3];
	int *p;
	
	vetor[0] = 4;
	vetor[1] = -2;
	vetor[2] = 7;
	
	p = vetor;

	cout << "vetor: " << vetor << endl;
	cout << "*vetor: " << *vetor << endl;
	
	cout << "*p: " << *p << endl;
	// Esse p++, ele vai pegar o endere�o e deslocar para direita no tamanho de um inteiro 
	p++; 
	cout << "*p (Ap�s um p++): " << *p << endl;
	
	p++;
	cout << "*p (Ap�s dois p++): " << *p << endl;
	
	p = p - 2;
	cout << "*p (Voltando no valor inicial): " << *p << endl;
	
	// Se caso continuar esse lixo de mem�ria entra como resultado
	
	return 0;
}