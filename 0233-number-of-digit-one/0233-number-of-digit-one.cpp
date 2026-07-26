class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        
        for (long long m = 1; m <= n; m *= 10) {
            long long divider = m * 10;
            count += (n / divider) * m + min(max(n % divider - m + 1, 0LL), m);
        }
        
        return (int)count;
    }
};