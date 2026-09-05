class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minSuffix(n);
        minSuffix[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; --i){
            minSuffix[i] = min(nums[i], minSuffix[i+1]);
        }
        int maxPrefix = nums[0];
        for(int i = 0; i < n; ++i){
            maxPrefix = max(maxPrefix, nums[i]);
            if(maxPrefix - minSuffix[i] <= k){
                return i;
            }
        }
        return -1;
    }
};