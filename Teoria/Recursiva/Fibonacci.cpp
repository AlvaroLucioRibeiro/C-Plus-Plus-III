#include <iostream>
using namespace std;
// Fun��o para realizar fibonacci
int Comb(int n, int k)
{
	if (k == 1 || k == 0) // Condi��o de parada
		return n;
	else if (k == n) 
		return 1;
	else
		return Comb(n - 1, k -1) + Comb(n - 1, k);
}
int main()
{
	setlocale(LC_ALL, "Portuguese");
	//Declara��o de Variaveis
	int n; // N�mero de pessoas
	int k; // N�mero de pessoas formadas
	int resultado; // Resultado
	// Entrada de Dados
	cin >> n;
	cin >> k;
	// Chamada de fun��o
	resultado = Comb(n, k);
	// Sa�da de Dados
	cout << resultado;
	return 0;
}