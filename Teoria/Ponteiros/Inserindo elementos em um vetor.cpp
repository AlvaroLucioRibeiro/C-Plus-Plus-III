#include <iostream>
using namespace std;
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	int *vetor; // Ponteiro para o vetor
	int n; // Tamanho desejado para o vetor
	int i; // Contador

	// Entre com o tamanho do vetor
	cout << "Entre com o tamanho do vetor: ";
	cin >> n;

	// Alocar mem�ria para o vetor
	vetor = new int[n];

	// Preencha o vetor
	cout << "Preencha os vetores com os n�meros desejados: ";
	for(i = 0; i < n; i++)
		cin >> vetor[i];

	// Sa�da de dados: Mostrando o vetor
	cout << "Este � o seu vetor: ";
	for(i = 0; i < n; i++)
		cout << vetor[i] << " ";
	cout << endl;
	
	// Liberar memoria alocada para o vetor
	delete [] vetor;
	return 0;
}