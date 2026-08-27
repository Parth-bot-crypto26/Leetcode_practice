class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int minLen = s.length()+1;
        int n = s.length();
        for(int i = 0; i < n; ++i){
            int ones = 0;
            string sub = "";
            for(int j = i; j < n; ++j){
                sub += s[j];
                if(s[j] == '1') ones++;
                if(ones == k){
                    int len = sub.length();
                    if(len < minLen){
                        minLen = len;
                        ans = sub;
                    }else if(len == minLen){
                        if(ans == "" || sub < ans){
                            ans = sub;
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
};