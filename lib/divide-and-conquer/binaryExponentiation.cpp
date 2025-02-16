#include <bits/stdc++.h>

using namespace std;

long long power(long long a, long long b)
{
    if (b == 0){
        return 1;
    }

    long long res = power(a, b/2);

    if(b % 2)
        return res * res * a;
    else 
        return res * res;
}

int main(){
    cout << power(2, 12) << "\n";
    return 0;
}