#include <vector>
#include <iostream>
using namespace std;

class FenwickTree {
private:
    vector<int> arvore;  // Estrutura de dados da árvore
    int tamanho;         // Tamanho do array original

public:
    /**
     * Constrói a Fenwick Tree a partir de um array
     * @param array Array de entrada
     */
    FenwickTree(const vector<int>& array) {
        tamanho = array.size();
        arvore.resize(tamanho + 1, 0);
        
        // Constrói a árvore inicial
        for (int i = 0; i < tamanho; i++) {
            atualizar(i, array[i]);
        }
    }

    /**
     * Atualiza o valor na posição 'indice' adicionando 'diferenca'
     * @param indice Posição a ser atualizada (0-based)
     * @param diferenca Valor a ser adicionado
     */
    void atualizar(int indice, int diferenca) {
        indice++; // Convertendo para 1-based
        while (indice <= tamanho) {
            arvore[indice] += diferenca;
            indice += indice & (-indice); // Move para o próximo nó
        }
    }

    /**
     * Consulta a soma do prefixo até o índice 'indice' (inclusive)
     * @param indice Índice final do prefixo (0-based)
     * @return Soma do intervalo [0..indice]
     */
    int consultarSoma(int indice) {
        indice++; // Convertendo para 1-based
        int soma = 0;
        while (indice > 0) {
            soma += arvore[indice];
            indice -= indice & (-indice); // Move para o nó pai
        }
        return soma;
    }

    /**
     * Consulta a soma do intervalo [inicio..fim]
     * @param inicio Índice inicial (0-based)
     * @param fim Índice final (0-based)
     * @return Soma do intervalo [inicio..fim]
     */
    int consultarIntervalo(int inicio, int fim) {
        return consultarSoma(fim) - consultarSoma(inicio - 1);
    }
};