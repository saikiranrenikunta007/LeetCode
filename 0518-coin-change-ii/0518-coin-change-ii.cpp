class Solution {
public:
    int solve(int amount,vector<int>&coins,int i,vector<vector<int>>&dp){

         int n = coins.size();
         if(dp[amount][i] != -1) {
            return dp[amount][i];
         }
         if(i==n) {
            if(amount == 0) return 1;
            return 0;
         }
         int ans = 0;
         for(int j=0;;++j) {
            if(amount-j*coins[i]>=0) {
                ans+=solve(amount-j*coins[i],coins,i+1,dp);
            }
            else {
                break;
            }
         }
         return dp[amount][i] = ans;
    }
    int change(int sum, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(sum+1,vector<int>(n+1,-1));
        return solve(sum,coins,0,dp);
    }
};