class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        // Initial sum of first k elements: k * (k + 1) / 2
        long long sum = (long long)k * (k + 1) / 2;
        
        // Sort to process elements in increasing order
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // If the current element is within our current range [1, k]
            if (nums[i] <= k) {
                sum -= nums[i]; // Remove the blocked number
                k++;            // Expand the range to take the next available number
                sum += k;       // Add the new boundary number to the sum
            } else {
                // Since the array is sorted, all remaining elements will be > k
                break;
            }
        }
        
        return sum;
    }
};