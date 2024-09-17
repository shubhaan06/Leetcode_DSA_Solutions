class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        unordered_map<string, int> freq; // One map to store frequencies for both sentences
        
        // Helper function to split words and count their frequencies
        auto countWords = [&](const string &sentence) {
            stringstream ss(sentence);
            string word;
            while (ss >> word) { // Split the sentence into words
                freq[word]++;    // Increment frequency of the word
            }
        };
        
        // Count words from both sentences
        countWords(s1);
        countWords(s2);
        
        vector<string> ans; // Result vector to store uncommon words
        
        // Traverse through the frequency map to find words with frequency 1
        for (const auto &pair : freq) {
            if (pair.second == 1) {
                ans.push_back(pair.first);
            }
        }
        
        return ans; // Return the result
    }
};