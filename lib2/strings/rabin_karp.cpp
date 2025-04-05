#include <vector>
#include <string>
#include <iostream>
#include <cmath> // Para std::max
using namespace std;

/**
 * Implementa o algoritmo Rabin-Karp para busca de padrões com hashing
 * 
 * @param padrao O padrão a ser buscado
 * @param texto O texto onde buscar o padrão
 * @return Vetor com as posições iniciais de todas as ocorrências do padrão no texto
 */
vector<int> buscarOcorrenciasRabinKarp(const string& padrao, const string& texto) {
    // Constantes para o cálculo do hash
    const int BASE = 31;                   // Base numérica para o hash
    const int MODULO = 1e9 + 9;            // Número primo grande para evitar overflow
    
    int tamanhoPadrao = padrao.size();
    int tamanhoTexto = texto.size();

    // Pré-computa as potências da base (BASE^i % MODULO)
    vector<long long> potenciasBase(max(tamanhoPadrao, tamanhoTexto)); 
    potenciasBase[0] = 1; // BASE^0 = 1
    for (int i = 1; i < (int)potenciasBase.size(); i++) {
        potenciasBase[i] = (potenciasBase[i-1] * BASE) % MODULO;
    }

    // Calcula o hash de todos os prefixos do texto
    vector<long long> hashPrefixosTexto(tamanhoTexto + 1, 0); 
    for (int i = 0; i < tamanhoTexto; i++) {
        int valorCaractere = texto[i] - 'a' + 1; // Mapeia 'a'-'z' para 1-26
        hashPrefixosTexto[i+1] = (hashPrefixosTexto[i] + valorCaractere * potenciasBase[i]) % MODULO;
    } 

    // Calcula o hash do padrão
    long long hashPadrao = 0; 
    for (int i = 0; i < tamanhoPadrao; i++) {
        int valorCaractere = padrao[i] - 'a' + 1; // Mapeia 'a'-'z' para 1-26
        hashPadrao = (hashPadrao + valorCaractere * potenciasBase[i]) % MODULO;
    } 

    // Busca as ocorrências do padrão no texto
    vector<int> ocorrencias;
    for (int i = 0; i + tamanhoPadrao - 1 < tamanhoTexto; i++) {
        // Calcula o hash da substring texto[i..i+tamanhoPadrao-1]
        long long hashSubstring = (hashPrefixosTexto[i+tamanhoPadrao] + MODULO - hashPrefixosTexto[i]) % MODULO;
        
        // Compara com o hash do padrão (ajustando pela potência da base)
        if (hashSubstring == hashPadrao * potenciasBase[i] % MODULO) {
            // Verificação adicional para evitar colisões (opcional)
            bool match = true;
            for (int j = 0; j < tamanhoPadrao; j++) {
                if (texto[i+j] != padrao[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                ocorrencias.push_back(i);
            }
        }
    }
    return ocorrencias;
}

int main() {
    string texto = "abracadabra";
    string padrao = "abra";
    
    vector<int> posicoes = buscarOcorrenciasRabinKarp(padrao, texto);
    
    cout << "Padrão \"" << padrao << "\" encontrado nas posições: ";
    for (int pos : posicoes) {
        cout << pos << " ";
    }
    cout << endl;
    
    return 0;
}