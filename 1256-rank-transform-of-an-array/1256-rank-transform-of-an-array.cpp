class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        if (arr.empty()) return {};  // Handle empty array

        vector<int> temp = arr;  // Copy the original array
        sort(temp.begin(), temp.end());  // Sort the copied array

        unordered_map<int, int> rankMap;  // Map to store the rank of each element
        int rank = 1;
        
        // Assign ranks to the sorted elements
        for (int i = 0; i < temp.size(); i++) {
            if (rankMap.find(temp[i]) == rankMap.end()) {  // Only assign rank if it's not already assigned
                rankMap[temp[i]] = rank++;
            }
        }

        // Create the result array and assign ranks based on the original array
        vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            result[i] = rankMap[arr[i]];
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