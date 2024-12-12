#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int N, i, j;
    int instances = 0;
    string input;

    while(cin >> N){
        vector<string> rows;
        int count = 0;

        for(i = 0; i < N; i++){
            cin >> input;
            rows.push_back(input);
        }

        stable_sort(rows.begin(), rows.end());

        for(i = 1; i < N; i++){
            string telAbove = rows.at(i-1);
            string currentTel = rows.at(i);

            for(j = 0; j < currentTel.length(); j++){
                if(currentTel[j] == telAbove[j]){
                    count++;
                } else{
                    break;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}