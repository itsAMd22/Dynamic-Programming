#include<bits/stdc++.h>
using namespace std;

#define ll long long

//recursion
//TC:O(n)
//SC:O(n)+O(n) -> Stack space + array space
// ll rec(int cur, vector<int>& e, vector<ll> &dp){
//     if(cur < 0) return LLONG_MAX;
//     if(cur == 0) return 0;

//     ll j1 = rec(cur - 1, e, dp);
//     ll j2 = rec(cur - 2, e, dp);
    
//     ll op1 = (j1 == LLONG_MAX ? LLONG_MAX : j1 + abs(e[cur] - e[cur - 1]));
//     ll op2 = (j2 == LLONG_MAX ? LLONG_MAX : j2 + abs(e[cur] - e[cur - 2]));

//     return dp[cur] = min(op1, op2);
// }

//tabular
//TC:O(n)
//SC:O(n)
ll rec(int n, vector<int> &e, vector<ll> &dp){
    if(n <= 1)  return 0;

    // dp[0] = 0;
    // for(int i = 1 ; i < n ; i++){
    //     dp[i] = min(dp[i], dp[i - 1] + abs(e[i] - e[i - 1]));
    //     if(i >= 2)  dp[i] = min(dp[i], dp[i - 2] + abs(e[i] - e[i - 2]));
    // }
    // return dp[n-1];

    //without dp table
    ll one = 0, two = 0, cur;
    if(n == 2)  return abs(e[1] - e[0]);

    one = abs(e[0] - e[1]);
    for(int i = 2 ; i < n ; i++){
        cur = min(one + abs(e[i - 1] - e[i]), two + abs(e[i - 2] - e[i]));
        two = one;
        one = cur;
    }
    return one;
}

int main(){
    int n;
    cin >> n;

    vector<int> e(n);
    for(int i = 0 ; i < n ; i++)    cin >> e[i];

    vector<ll> dp(n, LLONG_MAX);

    ll mn_energy = rec(n, e, dp);
    cout << mn_energy;
    return 0;
}