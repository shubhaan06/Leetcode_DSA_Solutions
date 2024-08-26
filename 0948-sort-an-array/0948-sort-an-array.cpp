#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Create a min-heap
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Insert all elements from nums into the min-heap
        for (int num : nums) {
            minHeap.push(num);
        }

        // Extract elements from the min-heap and store them in the result vector
        vector<int> sortedArray;
        while (!minHeap.empty()) {
            sortedArray.push_back(minHeap.top());
            minHeap.pop();
        }

        return sortedArray;
    }
};
