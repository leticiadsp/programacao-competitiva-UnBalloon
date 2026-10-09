#include <bits/stdc++.h>
using namespace std;

//contagem
//maximizar / minimizar
//ver se é possivel


const int N = 3;
vector<int>v;

void rec (int i){
    if( i == N + 1) {
        for(int x: v) cout << x << ' ';
        cout << '\n';
        return;
    }
    v.push_back(i);
    rec(i + 1);
    v.pop_back();
    rec(i + 1);
}

int main(){
    rec(1);
}