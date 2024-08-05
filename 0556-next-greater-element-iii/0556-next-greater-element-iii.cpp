class Solution {
public:
    int nextGreaterElement(int n) {
        int x = n;
        string num = to_string(n);

        //finding first value that has to be swaped
        int i = num.size() - 2;
        while(i>= 0 && num[i]>=num[i+1]) {
            i--;
        }

        //means num is inself maximum
        if(i==-1) return -1;

        //finding int just greater than num[i]
        int k = num.size() -1;
        while(num[i]>=num[k]) k--;

        
        //swap ith and kth num
        swap(num[i], num[k]);

        //reversing rest end digits to make the number just greater than the number
        reverse(num.begin() + i+1, num.end());
        long ans = stol(num);
        if(ans>INT_MAX) return -1;

        return ans;
    }
};