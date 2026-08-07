class Solution {
    int m, n;
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int index){
        if(index == word.length()) return true;
        if(r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[index]){
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        bool found = dfs(board, word, r-1, c, index+1) || dfs(board, word, r+1, c, index+1) || dfs(board, word, r, c-1, index+1) || dfs(board, word, r, c+1, index+1);
        board[r][c] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        if(word.length() > m*n) return false;
        unordered_map<char, int> boardFreq, wordFreq;
        for(int r = 0; r < m; ++r){
            for(int c = 0; c < n; ++c){
                boardFreq[board[r][c]]++;
            }
        }
        for(char ch : word){
            wordFreq[ch]++;
            if(wordFreq[ch] > boardFreq[ch]) return false;
        }
        if(boardFreq[word.front()] > boardFreq[word.back()]){
            reverse(word.begin(), word.end());
        }
        for(int r = 0; r < m; ++r){
            for(int c = 0; c < n; ++c){
                if(board[r][c] == word[0]){
                    if(dfs(board, word, r, c, 0)) return true;
                }
            }
        }
        return false;
    }
};