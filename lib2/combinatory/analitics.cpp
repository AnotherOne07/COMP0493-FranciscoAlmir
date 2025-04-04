#include <iostream>
using namespace std;

// Função para calcular fatorial
unsigned long long fatorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

// Coeficiente binomial usando a fórmula analítica: C(n, k) = n! / (k!(n-k)!)
unsigned long long coeficienteBinomialAnalitico(int n, int k) {
    if (k < 0 || k > n) return 0; // Caso inválido
    if (k == 0 || k == n) return 1; // Casos base
    
    // Simplificação para evitar overflow: C(n, k) = C(n, n-k)
    if (k > n - k) k = n - k;
    
    unsigned long long resultado = 1;
    for (int i = 1; i <= k; ++i) {
        resultado *= (n - k + i);
        resultado /= i; // Divisão segura pois há sempre fatores suficientes
    }
    return resultado;
}

int main() {
    int n = 5, k = 2;
    cout << "C(" << n << ", " << k << ") [Analítico] = " 
         << coeficienteBinomialAnalitico(n, k) << endl;
    return 0;
}