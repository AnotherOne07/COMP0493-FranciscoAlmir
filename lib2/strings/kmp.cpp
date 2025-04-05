#include <vector>
#include <string>
#include <iostream>
using namespace std;

/**
 * Calcula a função de prefixo (tabela de falha) para o algoritmo KMP
 * 
 * A função de prefixo para uma string S é um array pi onde pi[i] é o comprimento
 * do maior prefixo próprio de S que também é sufixo de S[0..i]
 * 
 * @param padrao A string para a qual calcular a função de prefixo
 * @return Vetor contendo os valores da função de prefixo para cada posição
 */
vector<int> calcularFuncaoPrefixo(const string& padrao) {
    int tamanhoPadrao = padrao.length();
    vector<int> tabelaPrefixos(tamanhoPadrao, 0); // Inicializa com zeros

    for (int indiceAtual = 1; indiceAtual < tamanhoPadrao; indiceAtual++) {
        // Começa com o valor do prefixo anterior
        int comprimentoPrefixoSufixo = tabelaPrefixos[indiceAtual - 1];

        // Enquanto não encontrou um match e ainda há prefixos para verificar
        while (comprimentoPrefixoSufixo > 0 && 
               padrao[indiceAtual] != padrao[comprimentoPrefixoSufixo]) {
            comprimentoPrefixoSufixo = tabelaPrefixos[comprimentoPrefixoSufixo - 1];
        }

        // Se encontrou um caractere que matcha, incrementa o comprimento
        if (padrao[indiceAtual] == padrao[comprimentoPrefixoSufixo]) {
            comprimentoPrefixoSufixo++;
        }

        // Armazena o resultado para a posição atual
        tabelaPrefixos[indiceAtual] = comprimentoPrefixoSufixo;
    }

    return tabelaPrefixos;
}

int main() {
    string texto = "ababacaababacab";
    string padrao = "ababacab";
    
    vector<int> tabelaPrefixos = calcularFuncaoPrefixo(padrao);
    
    cout << "Tabela de Prefixos para \"" << padrao << "\":\n";
    for (int i = 0; i < tabelaPrefixos.size(); i++) {
        cout << "[" << i << "]: " << tabelaPrefixos[i] << "\n";
    }
    
    return 0;
}