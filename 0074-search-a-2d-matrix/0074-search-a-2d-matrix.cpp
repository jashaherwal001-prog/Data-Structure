class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int x) {
        int N = matrix.size();
        int M = matrix[0].size();
        int row_index;
        int col_index;
        int start = 0;
        int mid;
        int end = (M * N) - 1;
        
        while (start <= end) {
            mid = (start + end) / 2;
            
            // --- FIXED LINE HERE ---
            row_index = mid / M;
            col_index = mid % M;
            
            if (matrix[row_index][col_index] == x) {
                return true; // it's good practice to use true/false for bool return types
            }
            else if (matrix[row_index][col_index] < x) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        } 
        return false;
    }
};