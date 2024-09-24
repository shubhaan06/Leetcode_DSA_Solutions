class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxLength = 1;  // Tracks the longest increasing subsequence
        int currentLength = 1;  // Tracks the length of the current increasing subsequence

        // Loop through the array once
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                // Continue the current increasing subsequence
                currentLength++;
            } else {
                // Reset the current sequence length
                currentLength = 1;
            }
            // Update the maxLength with the longest found sequence
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};