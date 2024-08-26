class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        // Create a vector of pairs (height, name)
        vector<pair<int, string>> heightNamePair;
        for (int i = 0; i < names.size(); ++i) {
            heightNamePair.emplace_back(heights[i], names[i]);
        }

        // Sort by height in descending order
        sort(heightNamePair.begin(), heightNamePair.end(), greater<pair<int, string>>());

        // Extract sorted names
        vector<string> ans;
        for (const auto& pair : heightNamePair) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};