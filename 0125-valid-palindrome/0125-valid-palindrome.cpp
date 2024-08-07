class Solution {
public:
    bool isPalindrome(string s) 
    {
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) 
    {
        return !std::isalnum(static_cast<unsigned char>(c));
    }), s.end());
        
        for (char &c : s) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    string temp=s;
    reverse(temp.begin(),temp.end());


    if(temp==s)
    {
        return true;
    }
    return false;
    }
};