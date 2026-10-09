#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int MAXN = 1002;
int N, dp[MAXN];

int rec (int i){
    if(i== N) return 1;
    if(dp[i] != -1) return dp[i]; // se o valor ja tiver sido calculado ele retorna o valor ja
    int ans = 0;
    if(i + 1 <= N) ans += rec(i + 1);
    if(i + 2 <= N) ans += rec(i + 2);
    if( i + 3 <= N) ans += rec(i + 3);
    return dp[i] = ans;

}

int32_t main(){
    memset(dp, -1, sizeof dp);
    cin >> N;
    cout << rec(0) << '\n';
}