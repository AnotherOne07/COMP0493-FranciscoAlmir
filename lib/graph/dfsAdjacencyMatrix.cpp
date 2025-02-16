#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector <vector<int>> adj;

// Adiciona aresta ao grafo
void addEdge(int x, int y){
    adj[x][y] = 1;
    adj[y][x] = 1;
}

// Realiza uma busca em profundidade no grafo usando uma pilha de recursão 
void dfs(int start, vector<bool>& visited){
    // Print do vértice inicial
    cout << start << " ";

    // Marca o vertice inicial de busca como visitado
    visited[start] = true;

    // para cada vertice adjacente nao visitado de start
    // será feita um bfs recusivamente
    for(int i = 0; i < adj[start].size(); i++){
        if(adj[start][i] == 1 && (!visited[i])){
            dfs(i, visited);
        }
    }
}

int main(){
    int v = 5;

    int e = 4;

    // Inicializa a matrix com dimensão VxV
    // todas as posições ij serão preenchidas com 0
    adj = vector<vector<int>> (v, vector<int>(v, 0));

    // Adiciona as arestas do grafo
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(0, 4);
    
    // Vetor dos vertices visitados
    // sendo que cada vertice sera visitado uma unica vez
    // ao inicializar, nenhum vertice foi visitado ainda
    vector<bool> visited(v, false);
    
    // realiza um dfs a partir do vértice 0
    dfs(0, visited);
    
    return 0;
}

