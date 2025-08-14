class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> s = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> st;
        string conv;
        for (string str : words) {
            conv = "";
            for (char c : str) {
                conv += s[c-'a'];
            }
            st.insert(conv);
        }

        return st.size();
    }
};