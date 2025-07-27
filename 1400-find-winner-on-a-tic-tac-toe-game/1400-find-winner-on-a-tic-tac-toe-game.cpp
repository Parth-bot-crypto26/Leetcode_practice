class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rowSums(3, 0);
        vector<int> colSums(3, 0);
        int diagSum1 = 0; 
        int diagSum2 = 0; 

        for (int i = 0; i < moves.size(); ++i) {
            int r = moves[i][0];
            int c = moves[i][1];

            int playerValue;
            if (i % 2 == 0) { 
                playerValue = 1;
            } else { 
                playerValue = -1;
            }

            rowSums[r] += playerValue;
            colSums[c] += playerValue;

            if (r == c) { 
                diagSum1 += playerValue;
            }
            if (r + c == 2) { 
                diagSum2 += playerValue;
            }
            if (abs(rowSums[r]) == 3 ||
                abs(colSums[c]) == 3 ||
                abs(diagSum1) == 3 ||
                abs(diagSum2) == 3) {
                
                if (playerValue == 1) {
                    return "A";
                } else {
                    return "B";
                }
            }
        }

        if (moves.size() == 9) {
            return "Draw";
        } else {
            return "Pending"; 
        }
    }
};
