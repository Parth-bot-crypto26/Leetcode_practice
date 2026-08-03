class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(4, 0);
        for(int i = n-1; i >= 0; i--){
            int take = 0;
            int maxDiff = INT_MIN;
            for(int k = 1; k <= 3 && i+k <= n; ++k){
                take += stoneValue[i+k-1];
                maxDiff = max(maxDiff, take-dp[(i+k)%4]);
            }
            dp[i%4] = maxDiff;
        }
        if(dp[0] > 0) return "Alice";
        if(dp[0] < 0) return "Bob";
        return "Tie";
    }
};