class Solution {
public:
    bool check(vector<int>& arr) 
    {
        int n=arr.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] < 0) {
                count++;
                if (count > 1) {
                    return false;
                }
            }
        }
        if(count==0)
        return true;
        if (arr[n - 1] - arr[0] > 0)
            return false;
        return true;
    }
};