class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        map<char, string> phoneMap;
        phoneMap['2'] = "abc";
        phoneMap['3'] = "def";
        phoneMap['4'] = "ghi";
        phoneMap['5'] = "jkl";
        phoneMap['6'] = "mno";
        phoneMap['7'] = "pqrs";
        phoneMap['8'] = "tuv";
        phoneMap['9'] = "wxyz";

        string currentCombination = "";
        
        backtrack(digits, 0, phoneMap, currentCombination, result);
        
        return result;
    }

private:
    void backtrack(const string& digits, int index, const map<char, string>& phoneMap, string& currentCombination, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }

        char digit = digits[index];
        string letters = phoneMap.at(digit);

        for (char letter : letters) {
            currentCombination.push_back(letter);
            backtrack(digits, index + 1, phoneMap, currentCombination, result);
            currentCombination.pop_back(); 
        }
    }
};