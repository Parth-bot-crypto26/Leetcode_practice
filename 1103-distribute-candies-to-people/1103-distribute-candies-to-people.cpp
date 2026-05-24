class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int give = 1;
        int idx = 0;
        while(candies > 0){
            ans[idx] += min(give, candies);
            candies -= give;
            give++;
            idx = (idx+1) % num_people;
        }
        return ans;
    }
};