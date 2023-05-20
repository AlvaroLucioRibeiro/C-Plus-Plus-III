#include <iostream> 
#include <climits> // INT_MAX
using namespace std;

int main()
{
	int custo[100][100]; // 100 numero maximo de focos
	// custo[i][j] = custo de ir de um foco 'i' para a foco 'j'
	int foco_inicial; // Primeiro foco e ultimo foco
	int n; // numero de focos

	cin >> n;
	while(n <= 2 || n >= 8)
	{
		cin >> n;
	}

	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			cin >> custo[i][j];
			custo[j][i] = custo[i][j]; // Custo de i->j = custo de j->i
		}
		
	cin >> foco_inicial;
	bool vis[100]; // marca se ja visitou ou nao um foco
	int menor_custo; // menor custo da viagem
	int custo_at; // menor custo atual
	int foco_atual; // foco atual
	int proximo_foco; // proximo foco

	// inicializando vetor vis (nenhum foco foi visitada no inicio)
	for(int i = 0; i < n; i++)
		vis[i] = false;

	// guloso
	menor_custo = 0;
	foco_atual = foco_inicial;
	for(int i = 0; i < n - 1; i++) // n-1 vezes = qnt de caminhos (exceto a volta para o foco inicial)
	{
		vis[foco_atual] = true; // marco que ja visitei a foco atual
		// encontrar qual o proximo foco mais proximo
		custo_at = INT_MAX;
		for(int j = 0; j < n; j++)
		{
			if(!vis[j] && custo_at > custo[foco_atual][j])
			{
				proximo_foco = j;
				custo_at = custo[foco_atual][j];
			}
		}
		menor_custo += custo_at;
		foco_atual = proximo_foco;
	}
	menor_custo += custo[foco_atual][foco_inicial];
	cout << menor_custo << endl;

	return 0;
}