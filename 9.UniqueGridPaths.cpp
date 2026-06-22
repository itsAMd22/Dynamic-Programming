#include<bits/stdc++.h>
using namespace std;


int rec(int n, int m, vector<vector<int>> &dp){
    if(n < 0 || m < 0)  return 0;
    if(n == 0 || m == 0)    return 1;
    if(dp[n][m] != -1)  return dp[n][m];

    return dp[n][m] = rec(n-1, m, dp) + rec(n, m-1, dp);
}

int rec1(int n, int m, vector<vector<int>> &dp){
    if(dp[n][m] != -1)  return dp[n][m];

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            if(i == 0 || j == 0)    dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[n][m];
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m, -1));

    // int uniqueGridPaths = rec(n - 1, m - 1, dp);
    int uniqueGridPaths = rec1(n - 1, m - 1, dp);
    
    cout << uniqueGridPaths << endl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
