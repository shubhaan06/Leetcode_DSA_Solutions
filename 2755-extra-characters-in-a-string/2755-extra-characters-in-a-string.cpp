class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end()); // Store dictionary in a set for fast lookup
        vector<int> dp(n + 1, 0);  // dp[i] represents the minimum extra characters for substring s[0...i-1]

        // Fill dp array with the worst case (all characters are extra)
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i] + 1;  // Assume the current character is extra

            // Try to match words in dictionary
            for (int j = i; j >= 0; j--) {
                string word = s.substr(j, i - j + 1);
                if (dict.find(word) != dict.end()) {
                    dp[i + 1] = min(dp[i + 1], dp[j]);
                }
            }
        }

        return dp[n];  // Return the result for the entire string
    }
};