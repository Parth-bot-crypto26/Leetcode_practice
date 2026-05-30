class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector row(rowIndex+1, 1);
        long long current = 1;
        for (int i = 1; i < rowIndex; ++i) {
            current = current * (rowIndex - i + 1) / i;
            row[i] = current;
        }
        return row;
    }
};