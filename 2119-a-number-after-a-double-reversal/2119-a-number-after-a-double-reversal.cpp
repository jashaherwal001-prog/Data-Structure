class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (num == 0) return true; // Quick escape for 0
        
        int originalNum = num; // Save the original value of num
        int reversed1 = 0;
        
        // First Reversal
        while (num > 0) {
            int rem = num % 10;
            if (reversed1 > INT_MAX / 10) return false; // Overflow check
            reversed1 = reversed1 * 10 + rem;
            num /= 10; 
        } 
        
        int tempReversed1 = reversed1; // Copy to loop through without losing it
        int reversed2 = 0;
        
        // Second Reversal
        while (tempReversed1 > 0) {
            int rem1 = tempReversed1 % 10;
            if (reversed2 > INT_MAX / 10) return false; // Overflow check
            reversed2 = reversed2 * 10 + rem1;
            tempReversed1 /= 10;
        }
        
        // Compare with the saved original value
        return reversed2 == originalNum;
    }
};