#include<bits/stdc++.h>
using namespace std;


int rec(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(n < 0 || m < 0 || grid[n][m] == -1)  return 0;
    if(n == 0 && m == 0)    return 1;
    if(dp[n][m] != -1)  return dp[n][m];

    return dp[n][m] = rec(n-1, m, grid, dp) + rec(n, m-1, grid, dp);
}

int rec1(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(dp[n][m] != -1)  return dp[n][m];

    int left, up;
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            if(grid[i][j] == -1)    dp[i][j] = 0;
            else if(i == 0 && j == 0)    dp[i][j] = 1;
            else{
                up = (i > 0 ? dp[i - 1][j] : 0);
                left = (j > 0 ? dp[i][j - 1] : 0);
                dp[i][j] = left + up;
            } 
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

    int uniqueGridPaths = rec(n - 1, m - 1, grid, dp);
    // int uniqueGridPaths = rec1(n - 1, m - 1, grid, dp);

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