#include <iostream>
#include <vector>
#include <queue>
#include <climits> // Para INT_MAX
using namespace std;

/**
 * Realiza a Busca em Largura (BFS) para o algoritmo de Edmonds-Karp
 * 
 * @param grafo Lista de adjacência representando o grafo
 * @param capacidade Matriz de capacidades das arestas
 * @param fluxo Matriz de fluxos atuais
 * @param ancestral Vetor para armazenar o caminho encontrado
 * @param fluxoCaminho Vetor para armazenar o fluxo possível até cada nó
 * @param fonte Nó de origem
 * @param sumidouro Nó de destino
 * @return O fluxo máximo possível no caminho encontrado
 */
int buscaEmLarguraEK(const vector<vector<int>>& grafo, const vector<vector<int>>& capacidade,
                    vector<vector<int>>& fluxo, vector<int>& ancestral, 
                    vector<int>& fluxoCaminho, int fonte, int sumidouro) {
    queue<int> fila;
    fila.push(fonte);
    ancestral.assign(grafo.size(), -1);
    fluxoCaminho.assign(grafo.size(), 0);
    fluxoCaminho[fonte] = INT_MAX; // Fluxo infinito na fonte

    while (!fila.empty()) {
        int noAtual = fila.front();
        fila.pop();

        // Explora todos os vizinhos do nó atual
        for (int vizinho : grafo[noAtual]) {
            // Se há capacidade residual e o vizinho não foi visitado
            if (capacidade[noAtual][vizinho] - fluxo[noAtual][vizinho] > 0 && 
                ancestral[vizinho] == -1) {
                ancestral[vizinho] = noAtual;
                fluxoCaminho[vizinho] = min(fluxoCaminho[noAtual], 
                                          capacidade[noAtual][vizinho] - fluxo[noAtual][vizinho]);
                
                if (vizinho == sumidouro) {
                    return fluxoCaminho[sumidouro]; // Caminho aumentante encontrado
                }
                fila.push(vizinho);
            }
        }
    }
    return 0; // Nenhum caminho aumentante encontrado
}

/**
 * Implementa o algoritmo de Edmonds-Karp para encontrar o fluxo máximo
 * 
 * @param grafo Lista de adjacência do grafo
 * @param capacidade Matriz de capacidades das arestas
 * @param fonte Nó de origem
 * @param sumidouro Nó de destino
 * @return O valor do fluxo máximo da fonte ao sumidouro
 */
int edmondsKarp(const vector<vector<int>>& grafo, const vector<vector<int>>& capacidade, 
               int fonte, int sumidouro) {
    int numNos = grafo.size();
    vector<vector<int>> fluxo(numNos, vector<int>(numNos, 0)); // Inicializa fluxo zero
    vector<int> ancestral(numNos); // Para armazenar o caminho
    vector<int> fluxoCaminho(numNos); // Fluxo máximo até cada nó
    int fluxoMaximo = 0;

    while (true) {
        int fluxoAtual = buscaEmLarguraEK(grafo, capacidade, fluxo, ancestral, 
                                        fluxoCaminho, fonte, sumidouro);
        if (fluxoAtual == 0) break; // Não há mais caminhos aumentantes

        // Atualiza o fluxo máximo
        fluxoMaximo += fluxoAtual;

        // Atualiza as capacidades residuais ao longo do caminho
        int no = sumidouro;
        while (no != fonte) {
            int noAnterior = ancestral[no];
            fluxo[noAnterior][no] += fluxoAtual; // Aumenta fluxo na direção do caminho
            fluxo[no][noAnterior] -= fluxoAtual; // Diminui fluxo na direção contrária
            no = noAnterior;
        }
    }

    return fluxoMaximo;
}

int main() {
    // Exemplo de grafo (lista de adjacência)
    vector<vector<int>> grafo = {
        {1, 4},    // Nó 0 (fonte) conecta a 1 e 4
        {2},        // Nó 1 conecta a 2
        {4, 5},     // Nó 2 conecta a 4 e 5
        {5},        // Nó 3 conecta a 5
        {2, 3},     // Nó 4 conecta a 2 e 3
        {}          // Nó 5 (sumidouro) sem conexões de saída
    };

    // Matriz de capacidades (inicializada com zero)
    vector<vector<int>> capacidade(6, vector<int>(6, 0));
    capacidade[0][1] = 8;
    capacidade[0][4] = 3;
    capacidade[1][2] = 9;
    capacidade[2][4] = 7;
    capacidade[2][5] = 2;
    capacidade[4][3] = 4;
    capacidade[3][5] = 5;
    capacidade[4][2] = 7;

    int fonte = 0;
    int sumidouro = 5;

    cout << "Fluxo Máximo (Edmonds-Karp): " 
         << edmondsKarp(grafo, capacidade, fonte, sumidouro) << endl;

    return 0;
}