class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed=numBottles;
        while(numBottles>=numExchange)
        {
            int newBottles=numBottles/numExchange;
            consumed+=newBottles;
            numBottles=newBottles+numBottles%numExchange;
        }
        return consumed;
    }
};