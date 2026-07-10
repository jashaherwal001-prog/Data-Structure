class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for(int i = 0; i < row; i++) {
            // 1. Initialize variables for the current row BEFORE the while loop
            int start = 0;
            int end = col - 1;
            int firstnegative = col; // Default to 'col' if no negative number is found

            while(start <= end) {
                int mid = start + (end - start) / 2; // Recalculate safely inside

                if(grid[i][mid] >= 0) {
                    start = mid + 1;
                }
                else {
                    firstnegative = mid; // Track the first negative index found so far
                    end = mid - 1;       // Keep searching left for an even earlier one
                }
            }
            
            // 2. If firstnegative remains 'col', it means col - col = 0 (no negatives added)
            count = count + (col - firstnegative);
        } 
        return count;
    }
};