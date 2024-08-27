class Solution {
public:
    double maxProbability(int n, vector <vector <int> >& edges, vector <double> & succProb, int start, int end){

        // Graph bana rahe hain unordered_map use karke
        unordered_map <int, vector< pair <int, int> > > graph;
                    // u                   v    idx

        // Saare edges ko graph mein daal rahe hain
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], edgeIdx = i;
            graph[u].push_back({v, edgeIdx}); // u se v edge jod rahe hain
            graph[v].push_back({u, edgeIdx}); // v se u edge jod rahe hain
        }

        // Har node ki probability ko 0 se initialize kar diya
        vector <double> probabilities(n, 0.0);
        probabilities[start] = 1.0; // Starting node ki probability 1.0 set kari

        // Max heap banane ke liye priority_queue use kar rahe hain
        priority_queue <pair <double, int> > pq;

        pq.push({1.0, start}); // Initial node ko heap mein daal diya

        while (!pq.empty()) {

            auto topNode = pq.top(); // Current node ko top se le liya
            double prob = topNode.first; // Is node ki probability
            int u = topNode.second; // Current node ka index
            pq.pop(); // Top node ko heap se hata diya

            if (u == end) return prob; // Agar end node mil gayi, toh uski probability return kar denge
                
            if (probabilities[u] > prob) continue; // Agar current node ki probability zyada hai, toh aage badhte hain
                
            for (auto neighbor : graph[u]){
                int v = neighbor.first; // Neighbor node ka index
                int edgeIdx = neighbor.second; // Edge ka index
                double newProb = prob * succProb[edgeIdx]; // Nay probability calculate kari
                if (newProb > probabilities[v]) {
                    probabilities[v] = newProb; // Agar nayi probability zyada hai, toh update kar diya
                    pq.push({newProb, v}); // Nayi node ko heap mein daal diya
                }
            }
        }
        return 0.0; // Agar end node tak nahi pahunche, toh 0 return kar diya
    }
};