class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxLength = 0;

        // Step 1: Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: For each number, check if (num + 1) exists
        for (auto& [num, count] : freq) {
            if (freq.count(num + 1)) {
                maxLength = max(maxLength, count + freq[num + 1]);
            }
        }

        return maxLength;
    }
};
