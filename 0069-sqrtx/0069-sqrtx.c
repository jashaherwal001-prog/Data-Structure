int mySqrt(int x) {
    if (x == 1 || x == 0) {
        return x;
    }
    
    int start = 1;
    int end = x;
    int index = 0;
    
    while (start <= end) {
        // Using long long prevents mid * mid from overflowing
        long long mid = start + (end - start) / 2; 
        
        if (mid * mid == x) {
            return mid;
        }
        else if (mid * mid > x) {
            end = mid - 1;
        }
        else {
            index = mid; // Keep track of the closest floor value
            start = mid + 1;
        }
    } 
    return index;
}