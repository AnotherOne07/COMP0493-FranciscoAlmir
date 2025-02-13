#include <stdio.h>
#include <stdlib.h>

void countSort (int inputArray[], int N){
    // Encontrar o elemento máximo do array inputArray
    int M = 0;
    for (int i = 0; i < N;i++){
        if (inputArray[i] > M){
            M = inputArray[i];
        }
    }

    // Inicializa o array com todas as posições com 0
    int* countArray = (int*)calloc(M+1, sizeof(int));

    // Mapeia cada elemento do array como um índice do countArray
    for (int i = 0;i < N;i++){
        countArray[inputArray[i]]++;
    }

    // Calcula a soma do prefixo de cada índice do array countArray
    for (int i = 1; i <= M;i++){
        countArray[i] += countArray[i-1];
    }

    // cria um array que irá armazenar o resultado do countArray
    int* outputArray = (int*)malloc(N * sizeof(int));
    for(int i = N - 1; i >= 0;i--){
        outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
        countArray[inputArray[i]]--; 
    }

    // copia o array ordenado de volta para o array de entrada
    for (int i = 0;i < N;i++){
        inputArray[i] = outputArray[i];
    }

    free(countArray);
    free(outputArray);
}

int main () {
    int inputArray[] = {4, 3, 12, 1, 5, 5, 3, 9};
    int N = sizeof(inputArray) / sizeof(inputArray[0]);
    
    // Ordenando com countSort
    countSort(inputArray, N);
    printf("Ordenando com countSort:\n");
    for(int i = 0;i < N;i++){
        printf("%d ", inputArray[i]);
    }

    return 0;
}

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
