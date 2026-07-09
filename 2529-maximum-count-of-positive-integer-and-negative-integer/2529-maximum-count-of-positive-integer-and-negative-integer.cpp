class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        // Find the index of the first element >= 0
        int start = 0, end = n - 1;
        int firstNonNegative = n; // Default if all elements are negative
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= 0) {
                firstNonNegative = mid;
                end = mid - 1; // Look left for an even earlier non-negative
            } else {
                start = mid + 1; // Look right
            }
        }
        
        // Find the index of the first element > 0
        start = 0;
        end = n - 1;
        int firstPositive = n; // Default if there are no positive elements
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > 0) {
                firstPositive = mid;
                end = mid - 1; // Look left for an even earlier positive
            } else {
                start = mid + 1; // Look right
            }
        }
        
        // Count calculations:
        // Negative count is just the index of the first non-negative number.
        int negativeCount = firstNonNegative; 
        // Positive count is total elements minus the first positive index.
        int positiveCount = n - firstPositive; 
        
        return max(negativeCount, positiveCount);
    }
};