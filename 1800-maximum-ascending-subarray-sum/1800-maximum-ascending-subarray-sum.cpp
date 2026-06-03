class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        for(int st = 0; st < n; st++){
            int currentSum = 0;
            for(int end = st; end < n; end++){
                    currentSum += nums[end];
                    maxSum = max(maxSum, currentSum);
                    if(end+1 < n && nums[end] >= nums[end+1]){
                        break;
                    }
            }
        }
        return maxSum;
    }
};