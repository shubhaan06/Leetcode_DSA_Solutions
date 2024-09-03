class Solution {
public:
    int countEven(int num) 
    {
        int count = 0;

        // Loop through each number from 1 to num
        for (int i = 1; i <= num; ++i) 
        {
            int sum = 0;
            int current = i;

            // Sum the digits of the current number
            while (current != 0) 
            {
                sum += current % 10;
                current /= 10;
            }

            // If the sum of the digits is even, increment the count
            if (sum % 2 == 0) 
            {
                count++;
            }
        }

        return count;
    }
};
