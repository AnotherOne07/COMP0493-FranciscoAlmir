#include <iostream>
using namespace std;

// Coeficiente binomial usando recursão: C(n, k) = C(n-1, k-1) + C(n-1, k)
unsigned long long coeficienteBinomialRecursivo(int n, int k) {
    if (k == 0 || k == n) return 1; // Casos base
    if (k > n) return 0;            // Caso inválido
    
    // Usa memoização implícita pela propriedade C(n, k) = C(n, n-k)
    if (k > n - k) k = n - k;
    
    return coeficienteBinomialRecursivo(n - 1, k - 1) + 
           coeficienteBinomialRecursivo(n - 1, k);
}

// Versão com memoização para melhor performance
unsigned long long coeficienteBinomialMemo(int n, int k, unsigned long long** memo) {
    if (k == 0 || k == n) return 1;
    if (memo[n][k] != 0) return memo[n][k];
    
    if (k > n - k) k = n - k;
    
    memo[n][k] = coeficienteBinomialMemo(n - 1, k - 1, memo) + 
                 coeficienteBinomialMemo(n - 1, k, memo);
    return memo[n][k];
}

// Função wrapper para a versão com memoização
unsigned long long coeficienteBinomialMemoWrapper(int n, int k) {
    if (k < 0 || k > n) return 0;
    
    // Aloca matriz para memoização
    unsigned long long** memo = new unsigned long long*[n+1];
    for (int i = 0; i <= n; ++i) {
        memo[i] = new unsigned long long[k+1]();
    }
    
    unsigned long long resultado = coeficienteBinomialMemo(n, k, memo);
    
    // Libera memória
    for (int i = 0; i <= n; ++i) {
        delete[] memo[i];
    }
    delete[] memo;
    
    return resultado;
}

int main() {
    int n = 5, k = 2;
    
    cout << "C(" << n << ", " << k << ") [Recursivo] = " 
         << coeficienteBinomialRecursivo(n, k) << endl;
         
    cout << "C(" << n << ", " << k << ") [Memoização] = " 
         << coeficienteBinomialMemoWrapper(n, k) << endl;
    
    return 0;
}