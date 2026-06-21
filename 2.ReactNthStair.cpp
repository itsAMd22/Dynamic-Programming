#include<bits/stdc++.h>
using namespace std;

//recursion
//TC:O(n)
//SC:O(n)+O(n) -> Stack space + array space
// int rec(int index, vector<int> &dp){
//     if(index <= 1)   return index;
//     if(dp[index] != -1) return dp[index];
//     return dp[index] = rec(index - 1, dp) + rec(index - 2, dp);
// }

//tabular
//TC:O(n)
//SC:O(n)
int rec(int index, vector<int> &dp){
    if(index <= 1)  return index;
    
    // dp[0] = 0, dp[1] = 1;
    // for(int i = 2 ; i <= index ; i++){
    //     dp[i] = dp[i - 1] + dp[i - 2];
    //     cout << dp[i] << endl;
    // }
    // return dp[index];

    //SC: O(1)
    int dp0 = 0, dp1 = 1, dp2, ct = 1;
    while(ct <= index){
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
    vector<int> dp(n + 1, -1);
    int ways = rec(n, dp);
    cout << ways << endl;
    return 0;
}
