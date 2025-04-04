#include <algorithm>
#include <vector>
#include "union_find.cpp"
using namespace std;

/**
 * Estrutura para representar uma aresta do grafo
 */
struct Aresta {
    int verticeA, verticeB;
    int peso;
    
    // Construtor
    Aresta(int a, int b, int w) : verticeA(a), verticeB(b), peso(w) {}
    
    // Operador para ordenar as arestas por peso
    bool operator<(const Aresta& outra) const {
        return peso < outra.peso;
    }
};

/**
 * Calcula a Minimum Spanning Tree usando o algoritmo de Kruskal
 * @param arestas Lista de arestas do grafo
 * @param numVertices Número de vértices no grafo
 * @return Vetor de arestas que formam a MST
 */
vector<Aresta> kruskalMST(vector<Aresta>& arestas, int numVertices) {
    vector<Aresta> arvoreGeradoraMinima;
    
    // Inicializa a estrutura Union-Find
    inicializarUnionFind(numVertices);
    
    // Ordena as arestas por peso crescente
    sort(arestas.begin(), arestas.end());
    
    // Percorre todas as arestas ordenadas
    for (const Aresta& aresta : arestas) {
        int raizA = encontrar(aresta.verticeA);
        int raizB = encontrar(aresta.verticeB);
        
        // Se os vértices estão em conjuntos diferentes, não formam ciclo
        if (raizA != raizB) {
            unir(aresta.verticeA, aresta.verticeB);
            arvoreGeradoraMinima.push_back(aresta);
            
            // A MST tem exatamente numVertices-1 arestas
            if (arvoreGeradoraMinima.size() == numVertices - 1) {
                break;
            }
        }
    }
    
    return arvoreGeradoraMinima;
}