class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i = 1; i <= n/2; ++i){
            if(n % i == 0){
                string sub = s.substr(0, i);
                string constructed = "";
                for(int j = 0; j < n/i; ++j){
                    constructed += sub;
                }if(constructed == s){
                    return true;
                }
            }
        }
        return false;
    }
};