class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int n=nums.size();
        int count=0;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            count++;
            if(nums[i]==0)
            {ans.push_back(count);
            count=0;
            }
        }
        ans.push_back(count);
        sort(ans.begin(),ans.end(),greater<int>());
        return ans[0];
    }
};