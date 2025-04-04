#include <vector>
#include <queue>
#include <climits>
using namespace std;

/**
 * Calcula a Minimum Spanning Tree usando o algoritmo de Prim
 * @param grafo Matriz de adjacência representando o grafo
 * @param numVertices Número de vértices no grafo
 * @return Vetor de pais representando a MST (pai[i] = pai do vértice i)
 */
vector<int> primMST(const vector<vector<int>>& grafo, int numVertices) {
    vector<int> chaves(numVertices, INT_MAX);      // Valores mínimos para incluir na MST
    vector<bool> naMST(numVertices, false);       // Verifica se o vértice está na MST
    vector<int> paisMST(numVertices, -1);         // Armazena a estrutura da MST
    
    // Fila de prioridade para selecionar a próxima aresta de menor peso
    // Armazena pares (chave, vértice)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaPrioridade;
    
    // Começa pelo vértice 0
    chaves[0] = 0;
    filaPrioridade.push({0, 0});
    
    while (!filaPrioridade.empty()) {
        int verticeAtual = filaPrioridade.top().second;
        filaPrioridade.pop();
        
        naMST[verticeAtual] = true;
        
        // Percorre todos os vértices adjacentes
        for (int vizinho = 0; vizinho < numVertices; vizinho++) {
            // Se há aresta, o vizinho não está na MST e o peso é menor que a chave atual
            if (grafo[verticeAtual][vizinho] && !naMST[vizinho] && 
                grafo[verticeAtual][vizinho] < chaves[vizinho]) {
                
                chaves[vizinho] = grafo[verticeAtual][vizinho];
                paisMST[vizinho] = verticeAtual;
                filaPrioridade.push({chaves[vizinho], vizinho});
            }
        }
    }
    
    return paisMST;
}