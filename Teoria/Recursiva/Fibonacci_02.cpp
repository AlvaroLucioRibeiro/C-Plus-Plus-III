#include <iostream>
using namespace std;
// Fun��o para realizar fibonacci
int Comb(int n)
{
	if (n == 1 || n == 0) // Condi��o de parada
		return 1;
	else
		return Comb(n - 1) + Comb(n - 2);
}
int main()
{
	setlocale(LC_ALL, "Portuguese");
	//Declara��o de Variaveis
	int n; // N�mero de pessoas
	int resultado; // Resultado
	// Entrada de Dados
	cin >> n;
	// Chamada de fun��o
	resultado = Comb(n);
	// Sa�da de Dados
	cout << resultado;
	return 0;
}