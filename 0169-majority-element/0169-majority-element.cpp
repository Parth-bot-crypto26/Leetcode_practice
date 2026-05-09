class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 0;
        for(int num : nums){
            if(count == 0){
                candidate = num;
            }
            if(num == candidate) count++;
            else count--;
        }
        count = 0;
        for(int num : nums){
            if(num == candidate) count++;
        }
        if(count > nums.size()/2){
            return candidate;
        }else{
            return -1;
        }
    }
};