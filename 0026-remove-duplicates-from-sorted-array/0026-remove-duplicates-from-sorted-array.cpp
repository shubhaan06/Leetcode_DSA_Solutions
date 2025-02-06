class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;  // Edge case: empty array

        int index = 1;  // Position to place the next unique element

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {  
                nums[index] = nums[i];  // Overwrite duplicate
                index++;  
            }
        }

        return index;  // New length of modified array
    }
};
