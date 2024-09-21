class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        // If needle is empty, return 0 (as per the problem definition)
        if (needle.empty()) return 0;

        int h_len = haystack.length();
        int n_len = needle.length();
        
        // Traverse the haystack and compare substrings of length equal to needle
        for (int i = 0; i <= h_len - n_len; i++) 
        {
            // Compare the substring of haystack with needle
            if (haystack.substr(i, n_len) == needle) {
                return i;  // Return the starting index of the match
            }
        }
        
        return -1;  // If no match is found, return -1
    }
};
