#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll rec(int n, int k, vector<ll> &cost, vector<ll> &dp) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    ll min_cost = LLONG_MAX;
    for (int i = 1; i <= k; i++) {
        if (n - i >= 0) {
            ll sub = rec(n - i, k, cost, dp);
            if(sub != LLONG_MAX){
                min_cost = min(min_cost, sub + abs(cost[n] - cost[n - i]));
            }
        }
    }
    return dp[n] = min_cost;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> cost(n);
    for (int i = 0; i < n; i++) cin >> cost[i];

    vector<ll> dp(n, -1);
    cout << rec(n - 1, k, cost, dp);
}