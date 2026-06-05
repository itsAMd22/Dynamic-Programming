#include<bits/stdc++.h>
using namespace std;

//recursion
//TC:O(n)
// SC:O(n)+O(n) -> Stack space + array space
// int fib(int n, vector<int> &dp){
//     if(n <= 1)  return n;
//     if(dp[n] != -1) return dp[n];
//     return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
// }

//tabular
//TC:O(n)
//SC:O(n) -> array space
int fib(int n, vector<int> &dp){
    if(n <= 1)  return n;

//     if(dp[n] != -1) return dp[n];
//     dp[0] = 0, dp[1] = 1;
//     for(int i = 2 ; i <= n ; i++){
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }   
//     return dp[n];

    //SC: O(1)
    int dp0 = 0, dp1 = 1, dp2, ct = 1;
    while(ct < n){
        ct++;
        dp2 = dp1 + dp0;
        dp0 = dp1;
        dp1 = dp2;
    }
    return dp1;
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    int nth_fib = fib(n, dp);
    cout << nth_fib;
    return 0;
}