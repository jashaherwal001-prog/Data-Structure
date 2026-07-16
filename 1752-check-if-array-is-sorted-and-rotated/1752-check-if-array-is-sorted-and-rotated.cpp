class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Check if current element is greater than the next element
            // (i + 1) % n handles the circular check from last to first element
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            
            // If there's more than one drop/break point, it cannot be sorted and rotated
            if (count > 1) {
                return false;
            }
        }
        
        return true;
    }
};