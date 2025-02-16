#include <iostream>
#include <vector>

using namespace std;


// vetor para registrar vetores visitados
vector<bool> visited;

// Adiciona aresta ao grafo
void addEdge(vector<vector<int>>& adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// busca em largura a partir de um vertice start
void dfs(vector<vector<int>>& adj, int start) {
    cout << start << " ";
    visited[start] = true;

    for (int v : adj[start]) {
        if (!visited[v]) {
            dfs(adj, v);
        }
    }
}

int main() {
    int v = 6;
    
    // lista de adjacencia para armazenar o grafo
    vector <vector<int>> adj(v);
    
    visited.resize(v, false);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);

    cout << "dfs começando a partir do vértice 0: ";
    dfs(adj, 0);
    cout << endl;

    return 0;
}

