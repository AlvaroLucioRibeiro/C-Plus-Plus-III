#include <iostream>
#include <iomanip>
using namespace std;
// Fun��o para realizar raiz quadrada
float raiz(float x, float xo, float e)
{
	float aux, res; //Variavel auxiliar
	aux = ((xo * xo) - x);
	if (aux < 0)
		aux = aux * (-1);
	if (aux <= e)
		return xo;
	else
	{
		res = (((xo * xo) + x) / (2 * xo));
		return raiz(x, res, e);
	}
}
int main()
{
	setlocale(LC_ALL, "Portuguese");
	//Declara��o de Variaveis
	float x; // Valor de x para calculo
	float xo; // Estimativa inicial para x
	float e; // Limitante superior para erro
	float resultado; // Resultado
	// Entrada de Dados
	cin >> x;
	cin >> xo;
	cin >> e;
	// Chamada de fun��o
	resultado = raiz(x, xo, e);
	// Sa�da de Dados
	cout << fixed << setprecision(4);
	cout << resultado << endl;
	return 0;
}
