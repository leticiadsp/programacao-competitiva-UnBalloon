#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5 + 1;
int parent[maxn];

int find(int u){
    if(u != parent[u])
        return parent[u] = find(parent[u]);
    return u;


}


bool uniao(int u, int v){
    u = find(u), v = find(v); 
    if(u != v){
        if(u > v)
            swap(u,v);

    parent[u] = v;
    return true;
    }
    return false;
}



int main(){
    int n, m, last = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        parent[i] = i;
    
    while(m--){
        int u, v; cin >> u >> v;
         uniao(u, v);
    }

    vector<array<int, 2>> ans;
    for(int i = 1; i <= n; i++)
        if(find(i) == i){
            if(last != 0)
                ans.push_back({last, i});
            last = i;    
        }
    cout << size(ans) << endl;
    for(auto[x, y]: ans )
        cout << x << " " << y << endl;
}