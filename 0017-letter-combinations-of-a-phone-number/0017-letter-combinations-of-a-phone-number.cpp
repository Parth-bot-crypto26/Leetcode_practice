class Solution {
    void backtrack(int index, const string& digits, string& current, const vector<string>& mapping, vector<string>& result){
        if(index == digits.length()){
            result.push_back(current);
            return;
        }
        string letters = mapping[digits[index]-'0'];
        for(char c : letters){
            current.push_back(c);
            backtrack(index+1, digits, current, mapping, result);
            current.pop_back();
        } 
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> mapping = {
            "", " ", "abc", "def",
            "ghi", "jkl", "mno", "pqrs",
            "tuv", "wxyz"
        };
        vector<string> result;
        string current = "";
        backtrack(0, digits, current, mapping, result);
        return result;
    }
};