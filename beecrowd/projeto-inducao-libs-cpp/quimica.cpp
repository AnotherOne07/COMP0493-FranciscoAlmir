#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stack>

using namespace std;

vector<string> stringPartition(string s, char symbol){
    vector<string> result;
    stringstream ss(s);
    string word;
    while(getline(ss, word, symbol)){
        result.push_back(word);
    }
    return result;
}

vector<string> getSubsAndSol(string s){
    vector<string> result, partialOne, partialTwo;
    // Ex: ['A', 'B->T1']
    partialOne = stringPartition(s, '+');
    result.push_back(partialOne[0]);
    // Ex: ['B','>T1'];
    partialTwo = stringPartition(partialOne[1], '-');
    result.push_back(partialTwo[0]);
    result.push_back(partialTwo[1].substr(1));
    return result;
}

string removeWhiteSpaces(string s){
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    return s;
}

int main(){
    // Vetor que representa os componentes iniciais
    vector<string> primarySubs;
    // Vetor que representa os componentes intermediários
    vector<string> secondSubs; 
    // Vetor que representa os recipientes
    vector<stack<string>> vessels;

    string currentReaction;

    int i, j, N;

    vector<string> provisory;

    while(cin >> N){
        cout << "N: " << N << endl;
        for(i = 0; i < N; i++){
            cout << "Line :" << i <<endl;
            
            // Entrada da formula
            cin.clear();
            getline(cin, currentReaction);

            // Tratamento da string de entrada
            currentReaction = removeWhiteSpaces(currentReaction);
            provisory.push_back(currentReaction);
        }
        for(string p : provisory){
            cout << p << endl; 
        }
    }


    return 0;
}