#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
/*----------------------------------------------------------------------------*/
struct ponto
{
	float x;
	float y;
};
typedef ponto vetor;
/*----------------------------------------------------------------------------*/
vetor cria_vetor(ponto A, ponto B)
{
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}
/*----------------------------------------------------------------------------*/
float vetorial(vetor A, vetor B)
{
	float v;
	v = A.x * B.y - A.y * B.x;
	return v;
}
/*----------------------------------------------------------------------------*/
float escalar(vetor A, vetor B)
{
	float e;
	e = A.x * B.x + A.y * B.y;
	return e;
}
/*----------------------------------------------------------------------------*/
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
/*----------------------------------------------------------------------------*/
int main()
{
	setlocale(LC_ALL, "Portuguese");
	int i; // Contador
	float area = 0; // Resultado Final
	float res1, res2, res3, res4, res5; // Somando todas as areas
	ponto vetor [100]; // Struct

	// Entrada de dados
	for(i = 0; i < 9; i++)
	{
		cin >> vetor[i].x >> vetor[i].y;
		res1 = area_triangulo(vetor[0], vetor[1], vetor[2]);
		res2 = area_triangulo(vetor[3], vetor[5], vetor[6]);
		res3 = area_triangulo(vetor[4], vetor[7], vetor[8]);
		res4 = area_triangulo(vetor[1], vetor[2], vetor[6]);
		res5 = area_triangulo(vetor[2], vetor[6], vetor[7]);
	}
	
	// Calculo e Saída de dados 
	area = res1 + res2 + res3 + res4 + res5; 
	cout << fixed << setprecision(2) << endl;
	cout << area << " m2" << endl;
	return 0;
}
