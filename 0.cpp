#include <bits/stdc++.h>
using namespace std;


void BFS(vector<vector<int>>& G, int s){
    int n = G.size();
    vector<int>dist(n+ 1, -1);
    vector <bool> visitado (n+ 1, false);
    vector<int>pai(n + 1, -1);//guarda quem descobriu quem
    vector<int>caminho;
    int atual = n - 1;

    queue<int>Q;

    dist[s] = 1; // a origem esta a 0 passos dela mesma
    visitado[s] = true;
    Q.push(s);

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        for(int v: G[u]){
            if(dist[v] == -1){ // ainda nao foi visitado
                dist[v] = dist[u] + 1; // um passo a mais que u
                pai[v] = u; // v foi descoberto a partir de u
                Q.push(v);
            }
        }
        }
        if(dist[n - 1] != -1)
        cout << dist[n - 1]<< endl;
        else {
            cout << "IMPOSSIBLE\n";
            return;
        }

        while(atual != -1){
        caminho.push_back(atual);
        atual = pai[atual];
    }
    reverse(caminho.begin(), caminho.end());
    for(int i = 0; i < caminho.size(); i++) cout << caminho[i] << " ";
    }




int main(){
    int V, A;
    cin >> V >> A;

    vector<vector<int>>G(V + 1);

    for(int i = 0; i < A; i++) {
        int v1, v2; cin >> v1 >> v2;
        G[v1].push_back(v2);
        G[v2].push_back(v1); // G[0] agora é a lista {1, 2};(lista de vizinhos do vertice 0) // G[1] agora é a lista {0, 2} e assim por diante
    }
    BFS(G, 1);


}