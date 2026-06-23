#include<bits/stdc++.h>
using namespace std;


int minimumTotal(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(i == 0)    dp[i][j] = grid[i][j];
            else{
                int up = (i > 0 ? dp[i - 1][j] : INT_MAX);
                int left = ((i > 0 && j > 0) ? dp[i - 1][j - 1] : INT_MAX);
                int right = ((i > 0 && j < m - 1) ? dp[i - 1][j + 1] : INT_MAX);
                
                dp[i][j] = min({up, left, right}) + grid[i][j];
            }
        }
    }
    return *min_element(dp[n-1].begin(), dp[n-1].end());
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> grid[i][j];
        }
    }
    int ans = minimumTotal(grid);
    cout << ans << endl;
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