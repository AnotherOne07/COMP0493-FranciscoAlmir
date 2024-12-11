// SOLUÇÃO INCORRETA - PARA USAR A BUSCA BINÁRIO O ARRAY DEVE ESTAR ORDENADO
// #include <iostream>

// using namespace std;

// int binarySearch(int arr[], int low, int high, int num){
    
//     while (low <= high) {
//         int mid = low + (high - low) / 2;

//         if (arr[mid] == num)
//             return mid;

//             if (arr[mid] < num)
//                 low = mid + 1;
//             else high = mid - 1;
//     }

//     return -1;
// }

// int main(){
//     int T, N, i, j;
//     int distinct;

//     cin >> T;

//     int rows[T];

//     for(i = 0 ;i < T; i++){
//         cin >> N;
//         distinct = 0;
//         int numbers[N];
        
//         for(j = 0; j < N; j++){
//             cin >> numbers[j];
//         }
        
//         for(j = 0; j < N; j++){
//             int findL = -1, findR;
//             if (j > 0){
//                 findL = binarySearch(numbers, 0, j-1, numbers[j]);
//             }
//             if (findL == -1){
//                 distinct++;
//             }
//         }
//         rows[i] = distinct;
//     }

//     for(int row : rows){
//         cout << row << endl; 
//     }
    
//     return 0;
// }

// SOLUÇÃO
#include <iostream>
#include <set>
using namespace std;

int main() {
    int T, N;

    cin >> T;
    int rows[T];

    for (int i = 0; i < T; i++) {
        cin >> N;
        set<int> distinctNumbers;

        for (int j = 0; j < N; j++) {
            int number;
            cin >> number;
            distinctNumbers.insert(number); // Adiciona apenas números únicos
        }

        rows[i] = distinctNumbers.size(); // Tamanho do set = números distintos
    }

    for (int i = 0; i < T; i++) {
        cout << rows[i] << endl;
    }

    return 0;
}
