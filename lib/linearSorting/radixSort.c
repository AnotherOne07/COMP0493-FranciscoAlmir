#include <stdio.h>
#include <stdlib.h>

void countSort (int inputArray[], int N, int exp){
    int outPut[N];
    int count[10] = {0};

    for (int i = 0;i < N;i++){
        count[(inputArray[i]/exp)%10]++;
    }

    for (int i =1; i < 10; i++){
        count[i] += count[i-1];
    }

    for (int i = N - 1;i >= 0; i--){
        outPut[count[(inputArray[i] / exp) % 10] - 1] = inputArray[i];
        count[(inputArray[i] / exp) % 10]--;
    }

    for(int i = 0;i < N;i++){
        inputArray[i] = outPut[i];
    }
}

int getMax(int arr[], int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void radixSort(int arr[], int n){
    // Obter o n'umero m'aximo para saber o numero de digitos
    int m = getMax(arr, n);

    // Realiza um counting sort para cada digito exponencial 10^i 
    // onde i deve ser o numero atual
    for(int exp=1;m/exp > 0;exp *= 10){
        countSort(arr, n, exp);
    }
}

int main() {
    int inputArray[] = {4, 3, 12, 1, 5, 5, 3, 9};
    int n = sizeof(inputArray) / sizeof(inputArray[0]);

    radixSort(inputArray, n);

    printf("Vetor ordenado utilizando radix sort: \n");
    for(int i = 0; i < n;i++){
        printf("%d ", inputArray[i]);
    }
    return 0;
}