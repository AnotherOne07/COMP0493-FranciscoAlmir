#ifndef NUMERIC_UTILS_H
#define NUMERIC_UTILS_H

#include <cmath>

class NumericUtils {
public:
    /**
     * Testa primalidade por força bruta
     * @param numero Número a testar
     * @return true se primo, false caso contrário
     */
    static bool isPrimeBruteForce(int numero) {
        if (numero <= 1) return false;
        
        for (int divisor = 2; divisor <= std::sqrt(numero); divisor++) {
            if (numero % divisor == 0) return false;
        }
        return true;
    }

    /**
     * Testa primalidade com otimizações
     * @param numero Número a testar
     * @return true se primo, false caso contrário
     */
    static bool isPrimeOptimized(int numero) {
        if (numero <= 1) return false;
        if (numero <= 3) return true;
        if (numero % 2 == 0 || numero % 3 == 0) return false;
        
        for (int divisor = 5; divisor * divisor <= numero; divisor += 6) {
            if (numero % divisor == 0 || numero % (divisor + 2) == 0) {
                return false;
            }
        }
        return true;
    }

    /**
     * Calcula o inverso modular
     * @param numero Número base
     * @param modulo Módulo
     * @return Inverso modular ou -1 se não existir
     */
    static int modularInverse(int numero, int modulo) {
        int m0 = modulo;
        int y = 0, x = 1;
        
        if (modulo == 1) return 0;
        
        while (numero > 1) {
            int q = numero / modulo;
            int t = modulo;
            
            modulo = numero % modulo;
            numero = t;
            t = y;
            
            y = x - q * y;
            x = t;
        }
        
        if (x < 0) x += m0;
        
        return (numero == 1) ? x : -1;
    }
};

#endif // NUMERIC_UTILS_H