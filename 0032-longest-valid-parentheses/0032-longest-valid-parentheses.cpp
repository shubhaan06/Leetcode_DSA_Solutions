class Solution {
public:
    int longestValidParentheses(string s) 
    {
        std::stack<int> stack;
    stack.push(-1); // Initial base for valid substring calculation
    int maxLength = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            stack.push(i);
        } else {
            stack.pop();
            if (stack.empty()) {
                stack.push(i);
            } else {
                maxLength = std::max(maxLength, i - stack.top());
            }
        }
    }

    return maxLength;
    }
};