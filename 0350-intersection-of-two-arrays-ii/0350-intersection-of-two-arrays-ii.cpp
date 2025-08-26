class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> freqMap;
        for(int num : nums1){
            freqMap[num]++;
        }

        vector<int> result;
        for(int num : nums2){
            if(freqMap.count(num) && freqMap[num] > 0){
                result.push_back(num);
                freqMap[num]--;
            }
        }
        return result;
    }
};