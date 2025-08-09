class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string currentParenthesis = "";

        backtrack(result, currentParenthesis, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& currentParenthesis,
                   int openCount, int closeCount, int n) {
        if (currentParenthesis.length() == 2 * n) {
            result.push_back(currentParenthesis);
            return;
        }

        if (openCount < n) {
            currentParenthesis += '(';
            backtrack(result, currentParenthesis, openCount + 1, closeCount, n);
            currentParenthesis.pop_back();
        }

        if (closeCount < openCount) {
            currentParenthesis += ')';
            backtrack(result, currentParenthesis, openCount, closeCount + 1, n);
            currentParenthesis.pop_back();
        }
    }
};
