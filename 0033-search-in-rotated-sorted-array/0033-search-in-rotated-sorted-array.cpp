class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start = 0;
        int end = arr.size() - 1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2; // Prevents potential integer overflow
            
            if (arr[mid] == target) {
                return mid;
            }
            
            // Check if the left side is sorted
            if (arr[start] <= arr[mid]) {
                // Check if the target lies within the sorted left side
                if (arr[start] <= target && target < arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } 
            // Otherwise, the right side must be sorted
            else {
                // Check if the target lies within the sorted right side
                if (arr[mid] < target && target <= arr[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        
        return -1;
    }
};