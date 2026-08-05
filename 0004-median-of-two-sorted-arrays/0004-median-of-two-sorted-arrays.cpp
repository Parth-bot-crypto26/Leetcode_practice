class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> ans;
        for(double i = 0; i < nums1.size(); i++){
            ans.push_back(nums1[i]);
        }
        for(double j = 0; j < nums2.size(); j++){
            ans.push_back(nums2[j]);
        }
        sort(ans.begin(), ans.end());
        int n = ans.size();
        int mid = n / 2;
        if(n % 2 != 0){
            return ans[mid];
        }else{
            return (ans[mid-1]+ans[mid])/2.0;
        }
    }
};