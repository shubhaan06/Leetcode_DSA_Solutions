class Solution {
public:

bool check(string s, int lo, int hi){
    while(lo<=hi){
        if(s[lo]!=s[hi])return false;
        lo++; hi--;
    }
    return true;
}

// start
    bool validPalindrome(string s){
        int count = 0;
        int n = s.size();
        int lo = 0, hi = n-1;
        while(lo<=hi){
            // if lo and hi element is equal then move on
            if(s[lo]==s[hi]){
                lo++; hi--;
            }
            // if not equal then pass the function in check
            /* we will pass 2 value in check, one after deleting
               lo and another after deliting hi.
            -> if any of the passed value returns true, then 
               it is a valid palindrome */
            else{
                return (check(s, lo+1, hi) || check(s, lo, hi-1));
            }
        }
        // if while loop se koi return nhi aaya then
        return true;
    }
};