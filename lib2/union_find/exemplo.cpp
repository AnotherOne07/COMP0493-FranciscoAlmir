#include <iostream>
#include "prim.cpp"
#include "kruskal.cpp"

int main() {
    // Exemplo para Kruskal
    vector<Aresta> arestas = {
        Aresta(0, 1, 10),
        Aresta(0, 2, 6),
        Aresta(0, 3, 5),
        Aresta(1, 3, 15),
        Aresta(2, 3, 4)
    };
    
    vector<Aresta> mstKruskal = kruskalMST(arestas, 4);
    cout << "Arestas na MST (Kruskal):\n";
    for (const auto& aresta : mstKruskal) {
        cout << aresta.verticeA << " - " << aresta.verticeB << " : " << aresta.peso << "\n";
    }

    // Exemplo para Prim
    vector<vector<int>> grafo = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    vector<int> mstPrim = primMST(grafo, 5);
    cout << "\nArestas na MST (Prim):\n";
    for (int i = 1; i < 5; i++) {
        cout << mstPrim[i] << " - " << i << " : " << grafo[i][mstPrim[i]] << "\n";
    }

    return 0;
}