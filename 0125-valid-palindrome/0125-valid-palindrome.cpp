class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(char c : s){
            if(isalnum(c)){
                temp += tolower(c);
            }
        }
        string reversed = temp;
        reverse(reversed.begin(), reversed.end());
        return temp == reversed;
    }
};