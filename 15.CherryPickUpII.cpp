#include<bits/stdc++.h>
using namespace std;


int maximiseRes(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
    // base1
    if(j1 < 0 || j1 == c || j2 < 0 || j2 == c || grid[i][j1] == -1 || grid[i][j2] == -1)  return INT_MIN;
    // base2
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int cur = grid[i][j1];
    if(j1 != j2)    cur += grid[i][j2];

    // base3
    if(i == r - 1)    return cur;

    int mx = INT_MIN, opt;
    for(int aj = -1; aj <= 1 ; aj++){
        for(int bj = -1 ; bj <= 1 ; bj++){
            opt = maximiseRes(i + 1, j1 + aj, j2 + bj, r, c, grid, dp);
            mx = max(mx, opt);
        }
    }

    return dp[i][j1][j2] = (mx != INT_MIN ? mx + cur : INT_MIN);
}

void solve(){
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cin >> grid[i][j];
        }
    }
    cout << maximiseRes(0, 0, c - 1, r, c, grid, dp);
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