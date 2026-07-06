class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word){
            words.push_back(word);
        }
        if(pattern.length() != words.size()){
            return false;
        }
        unordered_map<char, string> m;
        unordered_set<string> st;
        for(int i = 0; i < pattern.length(); i++){
            char ch = pattern[i];
            string curr = words[i];
            if(m.count(ch)){
                if(m[ch] != curr){
                    return false;
                }
            }else{
                if(st.count(curr)){
                    return false;
                }
                m[ch] = curr;
                st.insert(curr);
            }
        }
        return true;
    }
};