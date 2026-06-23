#include<bits/stdc++.h>
using namespace std;


int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0)    dp[i][j] = grid[i][j];
                else{
                    for(int k = 0 ; k < m ; k++){
                        if(j == k)  continue;
                        dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                    }
                    dp[i][j] += grid[i][j];
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
    int ans = minFallingPathSum(grid);
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