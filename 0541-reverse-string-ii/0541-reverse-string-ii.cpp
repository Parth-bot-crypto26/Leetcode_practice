class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for(int i = 0; i < n; i += 2*k){
            int rem = n-i;
            if(rem >= k){
                string sub = s.substr(i, k);
                reverse(sub.begin(), sub.end());
                s.replace(i, k, sub);
            }else{
                string sub = s.substr(i, rem);
                reverse(sub.begin(), sub.end());
                s.replace(i, rem, sub);
            }
        }
        return s;
    }
};