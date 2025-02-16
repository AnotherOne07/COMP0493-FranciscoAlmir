#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& arr){
    // ordena o vetor de strings
    sort(arr.begin(), arr.end());

    // compara a primeira e ultima string da lista
    string first = arr.front();
    string last = arr.back();
    int minLength = min(first.size(), last.size());

    int i = 0;

    while(i < minLength && first[i] == last[i]){
        i++;
    }

    return first.substr(0, i);
}

int main(){
    vector<string> arr = {"flamengo", "flamingo", "flamejante"};

    cout << longestCommonPrefix(arr) << endl;

    return 0;
}