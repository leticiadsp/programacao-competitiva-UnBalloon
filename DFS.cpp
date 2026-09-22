#include <bits/stdc++.h>
using namespace std;

void DFS (vector<vector<int>>&G, int s){
    int n = G.size();
    vector<bool>visitado (n, false);

    stack<int>st;
    st.push(s);

    while(!st.empty()){
        int u = st.top();
        st.pop();

        if(visitado[u] == false){
            visitado[u] = true;
            cout << u << " ";
        }
        for(int v: G[u]){
            if(visitado[v] == false) st.push(v);
        }
    }


}

int main(){
    int V, A;
    cin >> V >> A;

    vector<vector<int>>G(V);

    for(int i = 0; i < A; i++) {
        int v1, v2; cin >> v1 >> v2;
        G[v1].push_back(v2);
        G[v2].push_back(v1); // G[0] agora é a lista {1, 2};(lista de vizinhos do vertice 0) // G[1] agora é a lista {0, 2} e assim por diante
    }
    DFS(G, 0);

}