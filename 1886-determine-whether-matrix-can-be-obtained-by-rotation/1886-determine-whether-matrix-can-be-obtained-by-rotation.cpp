class Solution {
public:
    void rotate90(vector<vector<int>>& mat) {
        int n = mat.size();
        // 1. Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // 2. Reverse each row
        for (int i = 0; i < n; i++) {
            int start = 0, end = n - 1;
            while (start < end) {
                swap(mat[i][start], mat[i][end]);
                start++;
                end--;
            }
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // Try all 4 possible 90-degree rotations
        for (int k = 0; k < 4; k++) {
            if (mat == target) {
                return true;
            }
            rotate90(mat); // Rotate 90 degrees clockwise for the next attempt
        }
        return false;
    }
};