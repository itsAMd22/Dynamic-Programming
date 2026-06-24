#include<bits/stdc++.h>
using namespace std;

int rec(int cur, int k, vector<int> &a, vector<vector<int>> &dp){
    if(k == 0) return 1;
    if(cur < 0) return 0;
    if(dp[cur][k] != -1)    return dp[cur][k];

    bool notTake = rec(cur-1,k,a, dp);
    bool take = 0;
    if(a[cur] <= k){
        take = rec(cur-1, k-a[cur], a, dp);
    }
    return dp[cur][k] = take || notTake;
}

int rec1(int cur, int k, vector<int> &a, vector<vector<int>> &dp){
    for(int i = 0 ; i <= cur ; i++)  dp[i][0] = 1;

    for(int i = 0 ; i <= cur ; i++){
        for(int tg = 1 ; tg <= k ; tg++){
            bool notTake = (i > 0 ? dp[i-1][k] : 0);
            bool take = 0;
            if(a[cur] <= k){
                take = (i > 0 ? dp[i-1][k-a[i]] : 0);
            }
            dp[i][tg] = (take || notTake);
        }
    }
    return dp[cur][k];
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> dp(n, (vector<int>(k+1, -1)));
    for(int i = 0 ; i < n ; i++)    cin >> a[i];
    int sum = rec1(n-1, k, a, dp);
    cout << sum << endl;
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