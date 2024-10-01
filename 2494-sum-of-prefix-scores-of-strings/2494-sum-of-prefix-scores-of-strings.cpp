class TrieNode {
public:
    unordered_map<char, TrieNode*> children;  // Maps character to child node
    int count;  // How many words share this prefix

    TrieNode() {
        count = 0;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie and update prefix counts
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->count++;  // Increment count for this prefix
        }
    }

    // Get the prefix score for a word by summing up counts of its prefixes
    int getPrefixScore(const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char c : word) {
            node = node->children[c];
            score += node->count;  // Add the count of this prefix
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        vector<int> result;

        // First, insert all words into the Trie
        for (const string& word : words) {
            trie.insert(word);
        }

        // Then, for each word, calculate its prefix score
        for (const string& word : words) {
            result.push_back(trie.getPrefixScore(word));
        }

        return result;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
//KDS