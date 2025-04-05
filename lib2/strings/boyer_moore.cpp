#include <vector>
#include <string>
#include <iostream>
#include <algorithm> // Para std::max
using namespace std;

/**
 * Preprocessa a tabela de bad character (caractere ruim)
 * 
 * @param padrao O padrão a ser buscado
 * @return Vetor contendo as distâncias de salto para cada caractere ASCII
 */
vector<int> preprocessarTabelaBadChar(const string& padrao) {
    const int TAMANHO_ALFABETO = 128; // Tamanho do ASCII básico
    int tamanhoPadrao = padrao.length();
    vector<int> tabelaBadChar(TAMANHO_ALFABETO, tamanhoPadrao); // Inicializa com o tamanho do padrão

    // Preenche a tabela com as distâncias do último caractere
    for (int indice = 0; indice < tamanhoPadrao - 1; indice++) {
        tabelaBadChar[padrao[indice]] = tamanhoPadrao - indice - 1;
    }

    return tabelaBadChar;
}

/**
 * Implementa o algoritmo Boyer-Moore para busca de padrões
 * 
 * @param texto O texto onde buscar o padrão
 * @param padrao O padrão a ser encontrado no texto
 * @return true se o padrão for encontrado, false caso contrário
 */
bool buscarPadraoBoyerMoore(const string& texto, const string& padrao) {
    int tamanhoTexto = texto.length();
    int tamanhoPadrao = padrao.length();
    
    // Caso especial: padrão vazio
    if (tamanhoPadrao == 0) return true;
    // Caso especial: padrão maior que o texto
    if (tamanhoPadrao > tamanhoTexto) return false;

    // Pré-processamento
    vector<int> tabelaBadChar = preprocessarTabelaBadChar(padrao);

    // Algoritmo principal
    int indiceTexto = tamanhoPadrao - 1; // Posição atual no texto

    while (indiceTexto < tamanhoTexto) {
        int indicePadrao = tamanhoPadrao - 1; // Começa do final do padrão
        int posicaoAtualTexto = indiceTexto;

        // Compara do final para o início do padrão
        while (indicePadrao >= 0 && texto[posicaoAtualTexto] == padrao[indicePadrao]) {
            posicaoAtualTexto--;
            indicePadrao--;
        }

        // Padrão encontrado
        if (indicePadrao == -1) {
            return true;
        }

        // Calcula o salto usando a heurística de bad character
        int caractereTextual = texto[posicaoAtualTexto];
        int saltoBadChar = tabelaBadChar[caractereTextual];
        int saltoSeguro = max(1, saltoBadChar - (tamanhoPadrao - 1 - indicePadrao));

        // Avança no texto
        indiceTexto += saltoSeguro;
    }

    return false;
}

int main() {
    string texto = "Este é um exemplo de texto para busca com Boyer-Moore";
    string padrao = "Boyer-Moore";

    bool encontrado = buscarPadraoBoyerMoore(texto, padrao);

    if (encontrado) {
        cout << "Padrão encontrado no texto!" << endl;
    } else {
        cout << "Padrão não encontrado." << endl;
    }

    return 0;
}