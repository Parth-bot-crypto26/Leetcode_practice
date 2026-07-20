class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m*n;
        k = k % total;
        while(k > 0){
            int prev = grid[m-1][n-1];
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    swap(grid[i][j], prev);
                }
            }
            k--;
        }
        return grid;
    }
};