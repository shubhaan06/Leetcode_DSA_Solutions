class Solution {
public:
    int similarPairs(std::vector<std::string>& words) 
    {
        int count = 0;
        
        for (int i = 0; i < words.size(); i++) 
        {
            unordered_set<char> set1(words[i].begin(), words[i].end());

            for (int j = i + 1; j < words.size(); j++) 
            {
                unordered_set<char> set2(words[j].begin(), words[j].end());
                if (set1 == set2) 
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};