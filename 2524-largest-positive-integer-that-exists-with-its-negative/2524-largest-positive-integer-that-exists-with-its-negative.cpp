class Solution {
public:
    int findMaxK(vector<int>& v) {
        sort(v.begin(),v.end());
        int i = 0;
        int j = v.size()-1;
        while(i < j)
        {
            if(v[i] == -v[j] || v[j] == -v[i] )
                return abs(v[i]);
            if(abs(v[i]) < abs(v[j]))
            {
                j--;
            }
            else 
                i++;
        }
        return -1;

    }
};
