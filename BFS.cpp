#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>>& G, int s){
    int n = G.size();
    vector <bool> visitado (n, false);

    queue<int>Q;

    visitado[s] = true;
    Q.push(s);

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        cout << u << " ";

        for(int v: G[u]){
            if(visitado[v] == false){
                visitado[v] = true;
                Q.push(v);
            }
        }
    }
}



int main(){
    int V, A;
    cin >> V >> A;

    vector<vector<int>>G(V);

    for(int i = 0; i < V; i++) {
        int v1, v2; cin >> v1 >> v2;
        G[i] = {v1, v2};
    }
    BFS(G, 0);

}