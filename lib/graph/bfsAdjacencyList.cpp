#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// exploração em arvore a partir de um vertice s
void bfs(vector <vector<int>>& adj, int s){
    // cria uma fila para a bfs
    queue <int> q;

    // marca todos os vertices como nao visitados
    vector<bool> visited(adj.size(), false);

    // marca o vertice inicial como visitado e adiciona a fila
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        // tira o vertice da fila e faz o print
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        // para cada vertice adjacente do curr, verifica se ja foi visitado
        // senao foi visitado marca ele e adiciona a fila
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void addEdge(vector<vector<int>>& adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int v = 5;

    // criando grafo, apenas com os vertices
    vector<vector<int>> adj(v);

    // Adicionando arestas ao grafo
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    // Visualização do grafo
    //     0
    //    / \
    //   1   2
    //  / \ /  
    // 3   4


    // Executando uma busca em largura no grafo a partir do vertice v
    cout << "BFS começando do vertice 0: \n";
    bfs(adj, 0);

    return 0;
}