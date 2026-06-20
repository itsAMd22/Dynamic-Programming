#include<bits/stdc++.h>
using namespace std;

int rec(int cur, int bound, vector<int> &v, vector<int> &dp){
    if((int)v.size() == 1)   return (cur == 0 ? v[cur] : 0);
    
    if(cur == bound - 1)    return v[cur];
    if(dp[cur] != -1)   return dp[cur];

    int take = v[cur] + (cur + 2 < bound ? rec(cur + 2, bound, v, dp) : 0);
    int notTake = (cur + 1 < bound ? rec(cur + 1, bound, v, dp) : 0);

    return dp[cur] = max(take, notTake);
}

int rec1(int start, int bound, vector<int> &v, vector<int> &dp){
    if((int)v.size() == 1)   return (start == 0 ? v[start] : 0);

    if(dp[start] != -1)   return dp[start];

    int take = 0, notTake = v[start];
    dp[start] = v[start];

    for(int i = start + 1 ; i < bound ; i++){
        take = (i - 2 >= start ? dp[i - 2] : 0) + v[i];
        dp[i] = max(take, notTake);
        notTake = take;       
    }
    return dp[bound - 1];
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n), dp1(n, -1), dp2(n, -1);
    for(int i = 0 ; i < n ; i++)    cin >> v[i];

    // int mx1 = rec(0, n - 1, v, dp1);
    // int mx2 = rec(1, n, v, dp2);
    
    // for(auto e : dp1)   cout << e << " ";   cout << endl;
    // for(auto e : dp2)   cout << e << " ";   cout << endl;
    
    //Space optimised - recursion stack avoided
    int mx1 = rec1(0, n - 1, v, dp1);
    int mx2 = rec1(1, n, v, dp2);

    // for(auto e : dp1)   cout << e << " ";   cout << endl;
    // for(auto e : dp2)   cout << e << " ";   cout << endl;

    cout << max(mx1, mx2) << endl;
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

