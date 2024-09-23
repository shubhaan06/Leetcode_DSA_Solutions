class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        vector<int> ans;  // We store integers instead of strings
        int sum = 0;
        
        for (int i = 0; i < operations.size(); i++) 
        {
            if (operations[i] == "C") 
            {
                // Remove the last score
                ans.pop_back();
            } 
            else if (operations[i] == "+") 
            {
                // Add the sum of the last two scores
                int top = ans.back();
                int second_top = ans[ans.size() - 2];
                ans.push_back(top + second_top);
            } 
            else if (operations[i] == "D") 
            {
                // Double the last score
                ans.push_back(2 * ans.back());
            } 
            else 
            {
                // Add the round's score as an integer
                ans.push_back(stoi(operations[i]));
            }
        }

        // Sum all the valid scores
        for (int i = 0; i < ans.size(); i++) 
        {
            sum += ans[i];
        }

        return sum;  
    }
};