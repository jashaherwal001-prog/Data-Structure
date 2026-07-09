class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans; // Fix 1: Initialize completely empty

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate values for the first element
            if (i>0 && nums[i] == nums[i - 1]) continue;

                int start = i + 1;
                int end = n - 1;

                while (start < end) {
                    // Fix 4: Use long long to prevent integer overflow
                    long long current_sum = (long long)nums[i]+ nums[start] + nums[end];

                    if (current_sum ==0) {
                        ans.push_back({nums[i], nums[start], nums[end]});
                        
                        // Fix 3: Move pointers and skip duplicates
                        start++;
                        end--;
                        while (start < end && nums[start] == nums[start - 1]) start++;
                        while (start < end && nums[end] == nums[end + 1]) end--;
                    } 
                    else if (current_sum >0) {
                        end--;
                    } 
                    else {
                        start++;
                    }
                }
            } return ans;
        } 
    
};