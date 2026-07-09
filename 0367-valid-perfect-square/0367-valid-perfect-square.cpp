class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        
        long long start = 1;
        long long end = num;
        long long mid;
        
        while (start <= end) {
            mid = start + (end - start) / 2; // Prevents overflow during addition
            long long square = mid * mid;
            
            if (square == num) {
                return true;
            } else if (square > num) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }
};