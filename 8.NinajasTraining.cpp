#include<bits/stdc++.h>
using namespace std;

int rec(int cur, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(cur < 0)   return 0;
    if(dp[cur][last] != -1)   return dp[cur][last];

    int cur_best = 0;

    if(last != 0) cur_best = max(points[cur][0] + rec(cur - 1, 0, points, dp), cur_best);    
    if(last != 1) cur_best = max(points[cur][1] + rec(cur - 1, 1, points, dp), cur_best);
    if(last != 2) cur_best = max(points[cur][2] + rec(cur - 1, 2, points, dp), cur_best);

    return dp[cur][last] = cur_best;
}

int rec1(int cur, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(dp[cur][last] != -1)   return dp[cur][last];

    int n = (int) dp.size() - 1;
    
    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];

    
    for(int c = 1 ; c < n ; c++){
        for(int now = 0 ; now < 3 ; now++){
            int pt = 0;
            for(int l = 0 ; l < 3 ; l++){
                if(l != now)    pt = max(pt, points[c][now] + dp[c - 1][l]);
            }
            dp[c][now] = pt;
        }
    }
    
    return dp[n][3] = max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> points(n + 1, vector<int>(3)), dp(n + 1, vector<int>(4, -1));
    for(int i = 0 ; i < n ; i++)    cin >> points[i][0] >> points[i][1] >> points[i][2];
    
    // int max_merit = rec(n - 1, 3, points, dp);
    // cout << max_merit << endl;

    int max_merit1 = rec1(0, 3, points, dp);
    cout << max_merit1 << endl;
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