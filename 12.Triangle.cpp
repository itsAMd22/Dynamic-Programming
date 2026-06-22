#include<bits/stdc++.h>
using namespace std;


int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int m = triangle[n-1].size();
    vector<vector<int>> dp(n, vector<int>(m));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i + 1 ; j++){
            if(i == 0 && j == 0)    dp[i][j] = triangle[i][j];
            else if(j == i)     dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            else{
                int up = (i > 0 ? dp[i - 1][j] : INT_MAX);
                int left = ((i > 0 && j > 0) ? dp[i - 1][j - 1] : INT_MAX);
                dp[i][j] = min(up, left) + triangle[i][j];
            }
        }
    }
    return *min_element(dp[n-1].begin(), dp[n-1].end());
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> triangle(n, vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i + 1 ; j++){
            cin >> triangle[i][j];
        }
    }
    int ans = minimumTotal(triangle);
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