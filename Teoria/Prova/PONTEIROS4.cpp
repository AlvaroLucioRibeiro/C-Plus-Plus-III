#include<iostream>
using namespace std;

// Estrutura para armazenar os dados de cada aluno
struct dados
{
    int mat;
    int nota1;
    int nota2;
    float media;
};

int main()
{
    dados *alunos; // ponteiro para o vetor de dados dos alunos
    int N; // número de alunos
    int i; // contador
    int passaram; // numero de alunos aprovados
    
    // Lendo numero de alunos
    cin >> N;
    
    // Alocando memória para o vetor
    alunos = new dados [N];
    
    // Lendo os dados de cada aluno
    for(i=0;i<N;i++)
    {
        cin >> alunos[i].mat;
        cin >> alunos[i].nota1;
        cin >> alunos[i].nota2;
    }
    
    // Calculando a média de cada aluno
    for(i=0;i<N;i++)
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2)/2.0;
    
    // Verificando quantos passaram
    passaram = 0;
    for(i=0;i<N;i++)
        if(alunos[i].media >= 60.0)
            passaram++;
            
    // Apresentando o resultado
    cout << "Numero de alunos aprovados: " << passaram << endl;
    
    // Liberando memória utilizada pelo vetor
    delete [] alunos;
    
    return 0;
}