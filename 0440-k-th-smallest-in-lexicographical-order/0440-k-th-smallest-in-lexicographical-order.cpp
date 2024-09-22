class Solution {
public:
    // Function to count how many numbers are between prefix and prefix+1
    int countPrefix(int prefix, int n) {
        long curr = prefix;
        long next = prefix + 1;
        int count = 0;
        
        while (curr <= n) {
            count += min(n + 1L, next) - curr;  // Add the numbers between curr and next
            curr *= 10;
            next *= 10;
        }
        
        return count;
    }
    
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;  // Decrement k because we are already starting at the first number (1)
        
        while (k > 0) {
            int count = countPrefix(curr, n);  // Count how many numbers start with 'curr'
            
            if (count <= k) {
                // If k is larger than the count of numbers under 'curr', move to the next sibling
                curr++;
                k -= count;
            } else {
                // If k is within the range of numbers under 'curr', go deeper in the tree
                curr *= 10;
                k--;
            }
        }
        
        return curr;
    }
};
