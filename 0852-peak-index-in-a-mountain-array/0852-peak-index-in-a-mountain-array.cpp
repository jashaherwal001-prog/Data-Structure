class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // A mountain peak can never be at the first or last index
        int start = 1;
        int end = arr.size() - 2; 
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            // Checking neighbors is now perfectly safe from going out-of-bounds
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
                return mid;
            }
            // If we are on the ascending slope, the peak is to the right
            else if (arr[mid] > arr[mid-1]) {
                start = mid + 1;
            }
            // If we are on the descending slope, the peak is to the left
            else {
                end = mid - 1;
            }
        }
        return -1; // Fallback, though the problem guarantees a peak exists
    }
};