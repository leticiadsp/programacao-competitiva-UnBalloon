#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long ll;
typedef pair<int, ll>pll;

const int MAX = 1e5;
const ll MOD = 1e9+7;
const ll INF = 1e18;

vector<vector<pll>> g(MAX, vector<pll>());
vector<ll>dist(MAX, INF);

void dijkstra (int no){
    dist[no] = 0;
    priority_queue<pll, vector<pll>, greater <pll>> pq;
    pq.push({0, no});

    while(!pq.empty()){
        auto[d, u] = pq.top();
        pq.pop();

        if(dist[u] < d) continue;

        for(auto [w, v] : g[u]){
            if(d+w < dist[v]){
                dist[v] = d+w;
                pq.push({d + w, v});
            }
        }
    }
}




int main(){
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({w, b});
        g[b].push_back({w, a});
        g[a].push_back({w / 2, b + n});
    }
    dijkstra(1);

    for(int i = 1; i <=n; i++) cout << dist[i] << endl;


}