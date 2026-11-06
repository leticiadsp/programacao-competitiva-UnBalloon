#include <bits/stdc++.h>
using namespace std;

//LCA = "menor" ancestral comum

const int n = 1e5+1;

int pai[n];
vector<int>g[n];
const int logn = 17;

vector<vector<int>> up (17, vector<int>(n)); // up[i][v] = 2**i - passo de v

int get_k_ancestral(int u, int k){
    for(int i = logn - 1; i--; i>= 0){
        int passos = (1<<i); // 1<<i = 2**i
        if(passos <= k){
            k-=passos;
            u = up[i][u];
        }
    }
    return u;
}


int main(){
    int n; cin >> n;

    //u, v-> v é filho de u

    int raiz = 1;
    up[0][raiz] = raiz;

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        up[0][v] = u; // pai[v] = u;
    }

    for(int i = 0; i + 1< logn; i++){
        for(int u = 1; u <= n; u++){
            up[i + 1][u] = up[i][up[i][u]];
        }
    }

    for(int i = 0; i < logn; i++){
        for(int u = 1; u<=n; u++){
            cout << up[i][u] << " ";
        }
        cout << endl;
    }


    int q; cin >> q;

    while(q--){
        int u; cin >> u;
        int k; cin >> k;
        cout << "o " << k << " ancestral de " << u << " eh " << get_k_ancestral(u, k);
    }
}