class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        int index=0;
        if (m * n != original.size()) 
        {
            return {};
        }
        vector<vector<int>> arr2D(m, vector<int>(n));

          for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
            arr2D[i][j] = original[index];
            index++;
            }
        }
        return arr2D;
    }
};