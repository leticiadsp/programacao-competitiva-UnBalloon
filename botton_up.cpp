#include <bits/stdc++.h>
using namespace std;

#define int long long 

int32_t main(){
   // memset(dp, -1, sizeof dp);
    int N;
    cin >> N;
    vector<int>dp(N + 1);
    dp[0] = 1;
    for(int i = 1; i <= N; i++){
        if(i - 1 >= 0) dp[i] += dp[i - 1];
        if(i - 2 >= 0) dp[i] += dp[i - 2];
        if(i - 3 >= 0) dp[i] += dp[i - 3];
    }
    for(int x : dp) cout << x << ' ';
    cout << '\n';
    
}