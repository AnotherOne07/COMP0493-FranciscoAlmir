#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// implementação recursiva do algoritmo que resolve o problema da mochila
// retorna o máximo de lucro que pode ser obtido para a capacidade W
int knapSack(int W, int wt[], int val[], int n)
{
    // caso base
    if (n == 0 || W == 0){
        return 0;
    }

    // se o peso do item na posição n for maior doq a capacidade
    // entao esse item nao pode ser incluso na solução otima
    if(wt[n - 1] > W)
        return knapSack(W, wt, val, n-1);
    else

        // retorna o máximo dos dois casos
        // Caso 1: item na posição n incluso na solução
        // Caso 2: item na posição n nao esta incluso na solução
        return max(
            val[n - 1] +
            knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1)
        );
}

int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    printf("%d", knapSack(W, weight, profit, n));
    return 0;
}