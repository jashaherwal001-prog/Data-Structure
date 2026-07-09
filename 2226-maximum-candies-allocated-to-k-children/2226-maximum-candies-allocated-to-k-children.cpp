#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumCandies(std::vector<int>& candies, long long k) {
        long long start = 1;
        long long end = *std::max_element(candies.begin(), candies.end());
        long long mid;
        int ans = 0; // Default to 0 if we can't even give 1 candy to each child
        
        while (start <= end) {
            mid = start + (end - start) / 2; // Safer way to find mid without overflow
            long long count = 0;             // Start counting from 0
            
            // Calculate how many total sub-piles of size 'mid' we can create
            for (int i = 0; i < candies.size(); i++) {
                count += candies[i] / mid;
            }
            
            // If we can make AT LEAST k piles, mid is a valid configuration
            if (count >= k) {
                ans = mid;       // Store the valid candy count
                start = mid + 1; // Try to see if we can give a larger amount
            } 
            // If we can't make enough piles, mid is too large
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};