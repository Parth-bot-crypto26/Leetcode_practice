class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frequencyMap;
        for(int num : arr){
            frequencyMap[num]++;
        }
        unordered_set<int> uniqueFrequencies;
        for(auto const& pair : frequencyMap){
            uniqueFrequencies.insert(pair.second);
        }
        return frequencyMap.size() == uniqueFrequencies.size();
    }
};