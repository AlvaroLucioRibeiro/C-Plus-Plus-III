#include <iostream>
using namespace std;
int main( )
{
	setlocale(LC_ALL, "Portuguese");
	int *vetor; // Ponteiro para o vetor
	int n; // Tamanho desejado para o vetor
	int i; // Contador
	int cont = 0; // Contador para quantia

	// Entre com o tamanho do vetor
	cout << "Entre com o tamanho do vetor: ";
	cin >> n;

	// Alocar mem�ria para o vetor
	vetor = new int[n];

	// Preencha o vetor
	cout << "Preencha os vetores com os n�meros desejados: ";
	for(i = 0; i < n; i++)
	{
		cin >> vetor[i];
		if ((vetor[i] % 2 == 0) && (vetor[i] >= 0))
			cont++;
	}

	// Sa�da de dados: Mostrando a quantia de n� pares e positivos
	cout << "Esta � a quantia de numeros pares e positivos: ";
	cout << cont << endl;

	// Liberar memoria alocada para o vetor
	delete [] vetor;
	return 0;
}