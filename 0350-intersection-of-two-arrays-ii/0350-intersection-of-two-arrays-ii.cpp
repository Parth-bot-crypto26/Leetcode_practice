class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> counts;
        for(int num : nums1){
            counts[num]++;
        }
        vector<int> result;
        for(int num : nums2){
            if(counts[num] > 0){
                result.push_back(num);
                counts[num]--;
            }
        }
        return result;
    }
};