class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        
        for (int num : arr) {
            freq[(num % k + k) % k]++;
        }
        
        if (freq[0] % 2 != 0) return false;
        
        for (int i = 1; i <= k / 2; i++) {
            if (freq[i] != freq[k - i]) return false;
        }
        
        return true;
    }
};
static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
//KDS