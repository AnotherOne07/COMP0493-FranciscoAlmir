#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cria dois arrays temporarios
    vector<int> L(n1), R(n2);

    // copia os dados para dois vetores temporarios criados
    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for (int j = 0;j < n2;j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    // faz a união dos vetores temporários no vetor original arr
    while(i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copia os elementos remanecentes de L1  caso ainda exista
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copia os elementos remanecentes de R1 caso ainda exista
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right){
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void printVector(vector<int>& arr)
{
    for (int i = 0;i < arr.size(); i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

int main(){
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Vetor inicial: \n";
    printVector(arr);

    mergeSort(arr, 0, n - 1);

    cout << "\nVetor ordenado: \n";
    printVector(arr);
    return 0;
}