#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct ponto
{
	float x;
	float y;
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

/*float area_triangulo(ponto A, ponto B, ponto C)
{
	int S1, S2, S3;
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	area = fabs(vetorial(AB, AC)) / 2;
	return area;
}*/

// Função que cria sentido
int sentido(ponto A, ponto B, ponto C)
{
	int vet;
	vetor AB;
	vetor AC;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A,C);
	vet = vetorial(AB, AC);
	//(1 Esquerda, -1 Direita e 0 Colinear)
	if (vet > 0)
		return 1;
	else if (vet < 0)
		return -1;
	else 
		return 0;
}

float area_retangulo(ponto A, ponto B, ponto C, ponto P)
{
	float S1, S2, S3; // Var. Auxiliares
	S1 = sentido(A, B, P);
	S2 = sentido(A, C, P);
	S3 = sentido(B, C, P);
	if (S1 == S2 && S2 == S3)
		return 1;
	else if (S1*S3 == -1 || S1*S2 == -1 || S2*S3 == -1)
		return -1;
	else
		return 0;
}

int main()
{
	float X1, Y1; // 1ª Var. Auxiliares
	float X2, Y2; // 2ª Var. Auxiliares
	float X3, Y3, res; // 3ª Var. Auxiliares
	cin >> X1 >> Y1;
	cin >> X2 >> Y2;
	cin >> X3 >> Y3;
	res = area_retangulo(X1, Y1, X2);
	cout << res;
	return 0;
}