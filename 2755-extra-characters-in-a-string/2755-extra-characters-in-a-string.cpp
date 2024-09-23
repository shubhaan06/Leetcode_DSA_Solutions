
class TrieNode {
public:
    TrieNode* children[26] = {nullptr};  // 26 letters in the alphabet
    bool isWord = false;  // Marks the end of a valid word
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }

    // Check for words starting from index i in string s
    vector<int> searchFrom(int i, const string& s) {
        vector<int> endPositions;
        TrieNode* node = root;
        for (int j = i; j < s.size(); j++) {
            char c = s[j];
            if (!node->children[c - 'a']) {
                break;
            }
            node = node->children[c - 'a'];
            if (node->isWord) {
                endPositions.push_back(j);  // Found a valid word ending at j
            }
        }
        return endPositions;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        
        // Step 1: Build the Trie from the dictionary
        Trie trie;
        for (const string& word : dictionary) {
            trie.insert(word);
        }

        // Step 2: Dynamic Programming initialization
        vector<int> dp(n + 1, INT_MAX);  // dp[i] = min extra characters up to index i
        dp[0] = 0;  // No extra characters at the start

        // Step 3: Fill DP array using the Trie for efficient word lookup
        for (int i = 0; i < n; i++) {
            if (dp[i] == INT_MAX) continue;  // Skip if this position cannot be reached

            // Option 1: Assume character at s[i] is extra
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);

            // Option 2: Check for valid words starting from s[i]
            vector<int> endPositions = trie.searchFrom(i, s);
            for (int end : endPositions) {
                dp[end + 1] = min(dp[end + 1], dp[i]);
            }
        }

        // Step 4: Return the minimum number of extra characters at the end of the string
        return dp[n];
    }
};