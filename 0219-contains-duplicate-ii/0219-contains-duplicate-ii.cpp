class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i];
            if(seen.find(curr) != seen.end()){
                if(i-seen[nums[i]] <= k){
                    return true;
                }
            }
            seen[nums[i]] = i;
        }
        return false;
    }
};