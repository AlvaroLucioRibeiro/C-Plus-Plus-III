#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
/*----------------------------------------------------------------------------*/
void rabin_karp(char T[], char P[], int tamT, int tamP, int d, int q) //!!! d = Cardinalidade
{

	int h, ultimo; // valor utilizado para calculo de hash
	int p = 0; // padrao convertido para inteiro
	int t = 0; // texto convertido para inteiro
	int x = 0; // Contador

	for(int i = 0; i < tamP; i++)
	{
		p = (d * p + (P[i] - '0')) % q; // converte o padrao
		t = (d * t + (T[i] - '0')) % q; // converte o texto para o primeiro valor (t0)
	}

	h = (int)pow(d, tamP - 1) % q; // utilizado para calculo de hash

	for(int i = 0; i <= tamT - tamP; i++)
	{
		if(p == t) // Se encontrei um valor de hash valido
		{
			// Verifico se ha diferencas
			int j;
			for(j = 0; j < tamP; j++)
			{
				if(P[j] != T[i + j])
					break;
			}
			x++;
			if(j == tamP)
				ultimo = i;
		}
		if(i < tamT - tamP) // se ainda nao cheguei no final
		{
			t = (d * ( t - (T[i] - '0') * h ) + (T[i + tamP] - '0')) % q; // atualizo o ti para ti+1
			if(t < 0) t += q;
		}
	}
	if (x > 0)
	{
		cout << "Ultima ocorrencia: " << ultimo << endl;
		cout << x - 1 << " ocorrencia(s)";
	}
	else
		cout << x << " ocorrencia(s)";
}
/*----------------------------------------------------------------------------*/
int main()
{
	setlocale(LC_ALL, "Portuguese");
	int N, M; // N: Texto, M: Padrão
	int Q = 13, D = 10; // Utilizar q = 13 e d = 10
	char s[30], t[30]; // declaracao de uma string de 30 posicoes
	int i; // Contador
	cin >> N >> M;
	for(i = 0; i < N; i++)
		cin >> s[i];
	for(i = 0; i < M; i++)
		cin >> t[i];
	rabin_karp(s, t, N, M, D, Q);
	return 0;
}
