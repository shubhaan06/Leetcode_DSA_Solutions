class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        if(start==goal)
        return 0;
        int count=0;
        bitset<32> st(start);
        bitset<32> go(goal);

        string s = st.to_string();
        string g = go.to_string();

        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=g[i])
            count++;
        }
        return count;
    }
    };