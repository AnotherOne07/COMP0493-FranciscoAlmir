#include <vector>
using namespace std;

/**
 * Estrutura para representar o Union-Find (Conjuntos Disjuntos)
 */
vector<int> pais;     // Armazena o pai de cada elemento
vector<int> ranks;    // Armazena o rank (altura) de cada conjunto

/**
 * Inicializa a estrutura Union-Find
 * @param numElementos Quantidade de elementos
 */
void inicializarUnionFind(int numElementos) {
    pais.resize(numElementos);
    ranks.resize(numElementos, 0);
    for (int i = 0; i < numElementos; i++) {
        pais[i] = i;  // Cada elemento é seu próprio pai inicialmente
    }
}

/**
 * Encontra o representante (raiz) do conjunto contendo 'elemento'
 * com path compression
 * @param elemento Elemento a ser encontrado
 * @return Representante do conjunto
 */
int encontrar(int elemento) {
    if (pais[elemento] != elemento) {
        pais[elemento] = encontrar(pais[elemento]);  // Path compression
    }
    return pais[elemento];
}

/**
 * Une os conjuntos contendo 'elementoA' e 'elementoB'
 * @param elementoA Primeiro elemento
 * @param elementoB Segundo elemento
 */
void unir(int elementoA, int elementoB) {
    int raizA = encontrar(elementoA);
    int raizB = encontrar(elementoB);

    if (raizA != raizB) {
        // Union by rank
        if (ranks[raizA] > ranks[raizB]) {
            pais[raizB] = raizA;
        } else if (ranks[raizA] < ranks[raizB]) {
            pais[raizA] = raizB;
        } else {
            pais[raizB] = raizA;
            ranks[raizA]++;
        }
    }
}