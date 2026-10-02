#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
const int mod = 1e9+7;




int combinacao(int n, int k){
    if(k > n) return 0;
    
    k = min(k, (n - k+mod)%mod
    );
    
    long long res = 1;
    for(int i = 1; i <= k; i++) res = (res * (((n - k + i) / i)  % mod));
    
    return res;
}

int fexp(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1){
            ans = (ans * a) % mod;
        }
    a = (a * a) % mod;
    b>>=1;
    }
    return ans;
}

int invMult(int a){
    return fexp(a, mod - 2);
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    vector<int>fat(1e6 + 1, 1);
    int ans = 1;
    for(int i = 1; i < 1e6 + 1; i++) {
        ans = (ans * i) % mod;
        fat[i]= ans;
    }
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        
        int c = (fat[b] * fat[(a - b) % mod]) % mod;
        int res = (fat[a] * invMult(c)) % mod;
        cout << res << endl;
        
       
    }
}