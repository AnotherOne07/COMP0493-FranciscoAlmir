#include <bits/stdc++.h>
using namespace std;

/*
   Função para calcular o número mínimo de moedas necessárias para
   alcançar um determinado valor N, utilizando uma abordagem gulosa.
*/
long getMinimumCoins(long N, vector<long> Coins) {
    // Ordena as moedas em ordem decrescente para começar com as maiores
    sort(Coins.rbegin(), Coins.rend());
    
    long count = 0; // Contador de moedas utilizadas
    
    for (long coin : Coins) {
        if (N == 0) break; // Se já atingimos o valor exato, encerramos
        
        if (coin <= N) {
            long numCoins = N / coin; // Quantidade máxima da moeda atual que podemos usar
            count += numCoins;
            N -= numCoins * coin; // Reduz o valor restante
        }
    }
    
    // Retorna a quantidade mínima de moedas necessárias
    return count;
}

void printArray(vector<long> coins) {
    for (long i : coins)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<long> Coins = {1, 5, 10}; // Moedas disponíveis
    long N = 12; // Valor alvo
    
    cout << "Moedas disponíveis: ";
    printArray(Coins);
    
    cout << "Número mínimo de moedas para formar " << N << ": ";
    cout << getMinimumCoins(N, Coins) << endl;
    
    return 0;
}
