#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll rec(vector<ll> &v, vector<ll> &dp, int cur){
    // recursion with memo
    // if(cur < 1) return 0;
    // if(cur == 1)    return v[cur];
    // if(dp[cur] != -1)   return dp[cur];

    // ll picked = v[cur] + rec(v, dp, cur - 2);
    // ll not_picked = rec(v, dp, cur - 1);

    // return dp[cur] = max(picked, not_picked);


    //tabular with memo
    // dp[0] = 0, dp[1] = v[1];
    // if(cur <= 1)    return dp[cur];
    // ll n = cur, picked = 0, not_picked = 0;
    // for(int i = 2 ; i <= n ; i++){
    //     dp[i] = max(v[i] + dp[i - 2], dp[i - 1]);
    // }
    // return dp[cur];


    //space optimized
    int n = cur;
    if(n < 1)   return 0;

    ll prev2 = 0, prev1 = v[1], dpi = v[1];
    for(int i = 2 ; i <= n ; i++){
        dpi = max(prev2 + v[i], prev1);
        prev2 = prev1;
        prev1 = dpi;
    }
    return dpi;
}



void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n + 1), dp(n + 1, -1);
    //In dp, 1->not picked, 2->picked
    for(int i = 1 ; i <= n ; i++)   cin >> v[i];
    ll max_sum = rec(v, dp, n);
    cout << max_sum << endl;
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