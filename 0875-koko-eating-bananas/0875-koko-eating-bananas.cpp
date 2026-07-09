#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int ans = 0;
        
        // 1. Use 0LL so accumulate doesn't overflow internally
        long long sum = std::accumulate(piles.begin(), piles.end(), 0LL);
        
        // 2. Koko must eat at least 1 banana per hour to avoid division by zero
        long long start = 1; 
        long long end = *std::max_element(piles.begin(), piles.end());
        long long mid;
        
        while (start <= end) {
            mid = start + (end - start) / 2; // Prevents overflow
            long long timetaken = 0;         // Use long long to prevent timetaken overflow
            
            for (int i = 0; i < piles.size(); i++) {
                timetaken += piles[i] / mid;
                if (piles[i] % mid) {
                    timetaken++;
                }
            }
            
            if (timetaken <= h) {
                ans = mid;
                end = mid - 1; // Try to find a smaller valid speed
            } else {
                start = mid + 1; // Speed is too slow, increase it
            }
        } 
        return ans;
    }
};