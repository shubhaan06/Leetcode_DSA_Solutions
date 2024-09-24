class Solution {
public:
    int numSteps(std::string s) {
        int count = 0;
        
        // Iterate from the least significant bit to the most significant bit
        while (s != "1") {
            if (s.back() == '0') {
                // If the last bit is '0', it means the number is even. Perform division by 2.
                s.pop_back();  // Remove the last '0' (divide by 2 in binary)
            } else {
                // If the last bit is '1', it means the number is odd. Perform addition by 1.
                int i = s.size() - 1;
                
                // Perform binary addition of 1
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';  // Carry the addition over by setting '1' to '0'
                    i--;
                }
                
                // If we have moved past all bits and carried over, we need to add a new '1' at the front
                if (i < 0) {
                    s = "1" + s;  // Add '1' to the front if we carried past the first bit
                } else {
                    s[i] = '1';  // Otherwise, set the current bit to '1'
                }
            }
            count++;
        }
        
        return count;
    }
};