#include <limits.h>  // Para usar INT_MAX
#include <string.h>  // Para usar memset
#include <iostream>  // Para entrada/saída
#include <queue>     // Para usar a fila na BFS
using namespace std;

#define NUM_VERTICES 6  // Número de vértices no grafo

/**
 * Realiza uma busca em largura (BFS) para encontrar caminhos aumentantes no grafo residual
 * 
 * @param grafoResidual Matriz que representa o grafo residual
 * @param fonte Nó fonte (início do caminho)
 * @param sumidouro Nó sumidouro (destino do caminho)
 * @param ancestrals Array que armazena o ancestral de cada nó no caminho encontrado
 * @return Verdadeiro se existe caminho da fonte ao sumidouro, falso caso contrário
 */
bool buscaEmLargura(int grafoResidual[NUM_VERTICES][NUM_VERTICES], int fonte, int sumidouro, int ancestrals[]) {
  bool visitados[NUM_VERTICES];  // Array para marcar nós visitados
  memset(visitados, 0, sizeof(visitados));  // Inicializa todos como não visitados

  queue<int> fila;  // Fila para a BFS
  fila.push(fonte);  // Começa pelo nó fonte
  visitados[fonte] = true;  // Marca como visitado
  ancestrals[fonte] = -1;   // O nó fonte não tem ancestral

  while (!fila.empty()) {
    int noAtual = fila.front();  // Pega o próximo nó da fila
    fila.pop();  // Remove da fila

    // Explora todos os vértices adjacentes
    for (int vizinho = 0; vizinho < NUM_VERTICES; vizinho++) {
      // Se o vizinho não foi visitado e há capacidade residual
      if (visitados[vizinho] == false && grafoResidual[noAtual][vizinho] > 0) {
        fila.push(vizinho);  // Adiciona à fila
        ancestrals[vizinho] = noAtual;  // Marca o ancestral
        visitados[vizinho] = true;  // Marca como visitado
      }
    }
  }

  // Retorna verdadeiro se alcançamos o sumidouro (existe caminho)
  return (visitados[sumidouro] == true);
}

/**
 * Implementa o algoritmo de Ford-Fulkerson para encontrar o fluxo máximo
 * 
 * @param grafo Matriz de adjacência representando o grafo
 * @param fonte Nó fonte (início)
 * @param sumidouro Nó sumidouro (destino)
 * @return O valor do fluxo máximo da fonte ao sumidouro
 */
int fordFulkerson(int grafo[NUM_VERTICES][NUM_VERTICES], int fonte, int sumidouro) {
  int noAtual, vizinho;

  // Cria e inicializa o grafo residual (inicialmente igual ao grafo original)
  int grafoResidual[NUM_VERTICES][NUM_VERTICES];
  for (noAtual = 0; noAtual < NUM_VERTICES; noAtual++)
    for (vizinho = 0; vizinho < NUM_VERTICES; vizinho++)
      grafoResidual[noAtual][vizinho] = grafo[noAtual][vizinho];

  int ancestrals[NUM_VERTICES];  // Array para armazenar o caminho encontrado pela BFS
  int fluxoMaximo = 0;  // Inicializa o fluxo máximo como zero

  // Enquanto existir caminho aumentante da fonte ao sumidouro
  while (buscaEmLargura(grafoResidual, fonte, sumidouro, ancestrals)) {
    // Encontra a capacidade residual mínima (gargalo) no caminho
    int fluxoCaminho = INT_MAX;
    for (vizinho = sumidouro; vizinho != fonte; vizinho = ancestrals[vizinho]) {
      noAtual = ancestrals[vizinho];
      fluxoCaminho = min(fluxoCaminho, grafoResidual[noAtual][vizinho]);
    }

    // Atualiza as capacidades residuais ao longo do caminho
    for (vizinho = sumidouro; vizinho != fonte; vizinho = ancestrals[vizinho]) {
      noAtual = ancestrals[vizinho];
      grafoResidual[noAtual][vizinho] -= fluxoCaminho;  // Reduz a capacidade na direção do fluxo
      grafoResidual[vizinho][noAtual] += fluxoCaminho;  // Aumenta a capacidade na direção contrária
    }

    // Adiciona o fluxo deste caminho ao fluxo total
    fluxoMaximo += fluxoCaminho;
  }

  return fluxoMaximo;
}

int main() {
  // Grafo de exemplo representado como matriz de adjacência
  // Cada valor representa a capacidade da aresta entre os nós
  int grafo[NUM_VERTICES][NUM_VERTICES] = {
      {0, 8, 0, 0, 3, 0},  // Arestas do nó 0
      {0, 0, 9, 0, 0, 0},   // Arestas do nó 1
      {0, 0, 0, 0, 7, 2},   // Arestas do nó 2
      {0, 0, 0, 0, 0, 5},    // Arestas do nó 3
      {0, 0, 7, 4, 0, 0},    // Arestas do nó 4
      {0, 0, 0, 0, 0, 0}     // Arestas do nó 5
  };

  // Calcula e imprime o fluxo máximo do nó 0 (fonte) ao nó 5 (sumidouro)
  cout << "Fluxo Máximo: " << fordFulkerson(grafo, 0, 5) << endl;
  
  return 0;
}