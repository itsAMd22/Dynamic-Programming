#include<bits/stdc++.h>
using namespace std;


int rec(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(n == 0 && m == 0)    return dp[n][m] = grid[n][m];
    if(n < 0 || m < 0)  return INT_MAX;
    if(dp[n][m] != -1)  return dp[n][m];

    int up = rec(n-1, m, grid, dp);
    int left = rec(n, m-1, grid, dp);
    int cur = grid[n][m];
    
    int min_cost = cur + min(up, left);
    if(min_cost >= INT_MAX) min_cost = INT_MAX;

    return dp[n][m] = min_cost;
}

int rec1(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(dp[n][m] != -1)  return dp[n][m];

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            int up = (i > 0 ? dp[i - 1][j] : INT_MAX);
            int left = (j > 0 ? dp[i][j - 1] : INT_MAX);
            int cur = grid[i][j], mn = min(up, left);

            dp[i][j] = cur + (mn != INT_MAX ? mn : 0);
        }
    }
    return dp[n][m];
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n, vector<int>(m, -1)), grid(n, vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> grid[i][j];
        }
    }

    // int cost = rec(n - 1, m - 1, grid, dp);
    int cost = rec1(n - 1, m - 1, grid, dp);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << dp[i][j] << " ";
        }cout << endl;
    }
    
    cout << cost << endl;
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