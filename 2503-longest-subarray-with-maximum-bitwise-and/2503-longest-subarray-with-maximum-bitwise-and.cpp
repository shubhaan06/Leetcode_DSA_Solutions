class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int count = 0;
        int ans = 0;
        int maxVal = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxVal) 
            {
                maxVal = nums[i];
                ans = count = 1; 
            }
            else if (nums[i] == maxVal) 
            {
                count++;
            }
            else 
            {
                count = 0; 
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
