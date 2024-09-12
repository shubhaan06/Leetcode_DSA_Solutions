class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            string currentString = words[i];
            bool isValid = true; 
            for(int j=0;j<currentString.length();j++)
            {
                if(allowed.find(currentString[j]) == string::npos)
                {
                isValid=false;
                break;
                }
            }

            if(isValid)
            count++;
        }
        return count;
    }
};