class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> suf(n+1, 0);
        for (int i = n-1; i >= 0; i--) {
            suf[i] = suf[i+1];
            if (suf[i] < m && word1[i] == word2[m-1-suf[i]]) {
                suf[i]++;
            }
        }
        vector<int> result;
        int i=0, j=0;
        bool usedChange=false;
        while (j<m && i<n) {
            if (word1[i]==word2[j]) {
                result.push_back(i);
                i++; j++;
            } else {
                if (!usedChange && suf[i+1] >= m-j-1) {
                    result.push_back(i);
                    i++; j++;
                    usedChange = true;
                } else {
                    i++;
                }
            }
        }
        if (j<m) return {};
        return result;
    }
};