class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) return ans;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (left <= right && top <= bottom) {
            // 1. Traverse from Left to Right along the Top row
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++; // Move the top boundary down

            // 2. Traverse from Top to Bottom along the Right column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--; // Move the right boundary left

            // 3. Traverse from Right to Left along the Bottom row
            // (Check if top <= bottom is still true after modifying top)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // Move the bottom boundary up
            }

            // 4. Traverse from Bottom to Top along the Left column
            // (Check if left <= right is still true after modifying right)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++; // Move the left boundary right
            }
        }
        return ans;
    }
};