class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<bool> vis(n, false);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, 0});

        int cost = 0;
        int edgesUsed = 0;

        while(edgesUsed < n) {

            auto curr = pq.top();
            pq.pop();

            int wt = curr.first;
            int node = curr.second;

            if(vis[node])
                continue;

            vis[node] = true;

            cost += wt;

            edgesUsed++;

            for(int nei = 0; nei < n; nei++) {

                if(!vis[nei]) {

                    int dist =
                        abs(points[node][0] - points[nei][0]) +
                        abs(points[node][1] - points[nei][1]);

                    pq.push({dist, nei});
                }
            }
        }

        return cost;
    }
};