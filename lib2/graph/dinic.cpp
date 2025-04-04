#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Listas globais para representar o grafo
vector<vector<int>> capacidade;  // Matriz de capacidades
vector<vector<int>> adj;         // Lista de adjacência
vector<int> nivel;              // Níveis dos vértices
vector<int> ponteiro;           // Ponteiros para DFS
int fonte, sumidouro, numVertices;

// Inicializa as estruturas do grafo
void inicializarDinic(int n, int s, int t) {
    numVertices = n;
    fonte = s;
    sumidouro = t;
    capacidade.assign(n, vector<int>(n, 0));
    adj.assign(n, vector<int>());
    nivel.assign(n, -1);
    ponteiro.assign(n, 0);
}

// Adiciona aresta ao grafo
void adicionarAresta(int u, int v, int cap) {
    capacidade[u][v] = cap;
    adj[u].push_back(v);
    adj[v].push_back(u); // Para aresta reversa
}

// BFS para construir o grafo em camadas
bool bfs() {
    fill(nivel.begin(), nivel.end(), -1);
    nivel[fonte] = 0;
    
    queue<int> q;
    q.push(fonte);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (nivel[v] == -1 && capacidade[u][v] > 0) {
                nivel[v] = nivel[u] + 1;
                q.push(v);
            }
        }
    }
    
    return nivel[sumidouro] != -1;
}

// DFS para enviar fluxo bloqueante
int dfs(int u, int fluxo) {
    if (u == sumidouro) return fluxo;
    
    for (int& i = ponteiro[u]; i < adj[u].size(); i++) {
        int v = adj[u][i];
        
        if (nivel[v] == nivel[u] + 1 && capacidade[u][v] > 0) {
            int fluxoEnviado = dfs(v, min(fluxo, capacidade[u][v]));
            
            if (fluxoEnviado > 0) {
                capacidade[u][v] -= fluxoEnviado;
                capacidade[v][u] += fluxoEnviado;
                return fluxoEnviado;
            }
        }
    }
    
    return 0;
}

// Calcula o fluxo máximo usando Dinic
int calcularFluxoMaximo() {
    int fluxoMaximo = 0;
    
    while (bfs()) {
        fill(ponteiro.begin(), ponteiro.end(), 0);
        
        while (int fluxo = dfs(fonte, INT_MAX)) {
            fluxoMaximo += fluxo;
        }
    }
    
    return fluxoMaximo;
}

int main() {
    // Exemplo de uso
    int n = 6;
    fonte = 0;
    sumidouro = 5;
    
    inicializarDinic(n, fonte, sumidouro);
    
    // Adiciona arestas (mesmo grafo dos exemplos anteriores)
    adicionarAresta(0, 1, 8);
    adicionarAresta(0, 4, 3);
    adicionarAresta(1, 2, 9);
    adicionarAresta(2, 4, 7);
    adicionarAresta(2, 5, 2);
    adicionarAresta(4, 3, 4);
    adicionarAresta(3, 5, 5);
    adicionarAresta(4, 2, 7);
    
    cout << "Fluxo Máximo (Dinic): " << calcularFluxoMaximo() << endl;
    
    return 0;
}