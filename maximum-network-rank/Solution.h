// 1615. Maximal Network Rank

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<set<int>> graph(n, set<int>{}); 

        for (auto & road : roads) {
            int city1 = road[0];
            int city2 = road[1];
            graph[city1].insert(city2);
            graph[city2].insert(city1);
        }

        int maxRank = 0;

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int curRank = graph[i].size() + graph[j].size(); 
                if (graph[i].find(j) != graph[i].end()) {
                    // city i and city j are connected
                    --curRank; 
                }
                maxRank = max(curRank, maxRank); 
            }
        }
        
        return maxRank; 
    }
};