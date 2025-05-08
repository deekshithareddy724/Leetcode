#include <vector>
#include <queue>
#include <climits>
#include <tuple>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        if (n == 0) return 0;
        int m = moveTime[0].size();
        if (m == 0) return 0;
        
        // Directions: up, down, left, right
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Min-heap: (time, i, j, nextMove)
        priority_queue<tuple<int, int, int, int>, 
                       vector<tuple<int, int, int, int>>,
                       greater<tuple<int, int, int, int>>> pq;
        
        // Initial state: (0, 0) at time 0, next move takes 1 second
        pq.push({0, 0, 0, 1});
        
        // Visited matrix: visited[i][j][nextMove-1]
        vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        
        while (!pq.empty()) {
            auto [time, i, j, nextMove] = pq.top();
            pq.pop();
            
            // If reached destination
            if (i == n - 1 && j == m - 1) {
                return time;
            }
            
            // Skip if we've found a better way
            if (time >= visited[i][j][nextMove - 1]) {
                continue;
            }
            visited[i][j][nextMove - 1] = time;
            
            // Explore neighbors
            for (auto [di, dj] : dirs) {
                int ni = i + di;
                int nj = j + dj;
                
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int enterTime = max(time, moveTime[ni][nj]);
                    int newTime = enterTime + nextMove;
                    int newNextMove = 3 - nextMove; // Toggle between 1 and 2
                    
                    if (newTime < visited[ni][nj][newNextMove - 1]) {
                        pq.push({newTime, ni, nj, newNextMove});
                    }
                }
            }
        }
        
        return -1; // Shouldn't reach here for valid inputs
    }
};