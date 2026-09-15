class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int ans = 0;
        int lastEnd = -1;
        for(int center = 0; center < 2*n-1; ++center){
            int left = center / 2;
            int right = left + (center % 2);
            while(left >= 0 && right < n && s[left] == s[right]){
                if(right - left + 1 >= k){
                    if(left > lastEnd){
                        ans++;
                        lastEnd = right;
                    }
                    break;
                }
                left--;
                right++;
            }
        }
        return ans;
    }
};