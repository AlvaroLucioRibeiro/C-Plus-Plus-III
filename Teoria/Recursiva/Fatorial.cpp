#include <iostream>
using namespace std;
// Fun��o para realizar fatora��o
int fatorial(int fat)
{
	if (fat == 0) // Condi��o de parada
		return 1;
	else
		return fat * fatorial (fat - 1);
}
int main()
{
	setlocale(LC_ALL, "Portuguese");
	//Declara��o de Variaveis
	int fat; // Valor do fatorial a descobrir
	int resultado; // Resultado
	// Entrada de Dados
	cin >> fat;
	// Chamada de fun��o
	resultado = fatorial(fat);
	// Sa�da de Dados
	cout << resultado;
	return 0;
}