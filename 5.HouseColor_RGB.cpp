#include<bits/stdc++.h>
using namespace std;

#define ll long long

int rec(int cur, int prev, vector<int>& r, vector<int>& g, vector<int>& b, vector<vector<int>>& dp){
    if(cur < 0) return 0;    
    else if(prev != 0 && dp[cur][prev] != -1)  return dp[cur][prev];

    int rr, gg, bb, cur_cost = 0;
    rr = gg = bb = INT_MAX;

    if(prev != 1)   rr = r[cur] + rec(cur - 1, 1, r, g, b, dp);
    if(prev != 2)   gg = g[cur] + rec(cur - 1, 2, r, g, b, dp);
    if(prev != 3)   bb = b[cur] + rec(cur - 1, 3, r, g, b, dp);

    return dp[cur][prev] = min({rr, gg, bb});
}

int solve(){
    cin.ignore();
    int n;
    cin >> n;
    vector<int> r(n), g(n), b(n);
    vector<vector<int>> dp(n, vector<int>(4));
    for(int i = 0 ; i < n ; i++)    dp[i][1] = dp[i][2] = dp[i][3] = -1;
    for(int i = 0 ; i < n ; i++)    cin >> r[i] >> g[i] >> b[i];
    return rec(n - 1, 0, r, g, b, dp);
}

int main(){
    int t = 1;
    cin >> t;
    for(int i = 1 ; i <= t ; i++){
        cout << "Case " << i << ": " << solve();
        // cout << solve();
        if(i != t)  cout << '\n';
    }

    return 0;
}