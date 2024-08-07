class Solution {
public:
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
    int maxPoints(vector<vector<int>>& points) 
    {
        if (points.size() <= 1) return points.size();

    int maxPoints = 0;

    for (int i = 0; i < points.size(); ++i) {
        unordered_map<string, int> slopeMap;
        int duplicates = 0;
        int localMax = 0;

        for (int j = i + 1; j < points.size(); ++j) {
            if (points[i] == points[j]) {
                ++duplicates;
                continue;
            }

            int dy = points[j][1] - points[i][1];
            int dx = points[j][0] - points[i][0];
            int gcdValue = gcd(dy, dx);

            dy /= gcdValue;
            dx /= gcdValue;

            // Handle slope direction consistency
            if (dx < 0) {
                dy = -dy;
                dx = -dx;
            }

            string slope = to_string(dy) + "/" + to_string(dx);
            slopeMap[slope]++;
            localMax = max(localMax, slopeMap[slope]);
        }

        maxPoints = max(maxPoints, localMax + duplicates + 1); // +1 for the current point
    }

    return maxPoints;
    }
};