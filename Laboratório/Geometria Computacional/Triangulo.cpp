#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct ponto
{
	float x;
	float y;
	float z;
};
typedef ponto vetor;

vetor cria_vetor(ponto A, ponto B)
{
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A, vetor B)
{
	float v;
	v = A.x * B.y - A.y * B.x;
	return v;
}

float escalar(vetor A, vetor B)
{
	float e;
	e = A.x * B.x + A.y * B.y;
	return e;
}

float area_triangulo(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	area = fabs(vetorial(AB, AC)) / 2;
	return area;
}

/*// Função que cria sentido
int sentido(ponto A, ponto B, ponto C)
{
	int vet;
	vetor AB;
	vetor AC;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	vet = vetorial(AB, AC);
	//(1 Esquerda, -1 Direita e 0 Colinear)
	if (vet > 0)
		return 1;
	else if (vet < 0)
		return -1;
	else
		return 0;
}*/
int main()
{
	int i, j; // Contador
	float res; // Resultado
	int n; // Quantidade de conjuntos
	ponto vetor [100]; // Struct
	cin >> n;
	for(j = 0; j < n; j++)
		for(i = 0; i < 3; i++)
	{
		cin >> vetor[i].x >> vetor[i].y;
		res = area_triangulo(vetor[0], vetor[1], vetor[2]);
	}
	cout << setprecision(2);
	cout << res << endl;
	if (res < 1)
		cout << "Nao formam triangulo" << endl;
	else
		cout << "Formam triangulo" << endl;
	return 0;
}
