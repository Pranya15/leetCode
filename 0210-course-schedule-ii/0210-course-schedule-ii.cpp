class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto edge : prerequisites) {

            int a = edge[0];
            int b = edge[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;

        // Push all courses with indegree 0
        for (int i = 0; i < numCourses; i++) {

            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {

            int curr = q.front();
            q.pop();

            ans.push_back(curr);

            for (int neigh : adj[curr]) {

                indegree[neigh]--;

                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        if (ans.size() == numCourses) {
            return ans;
        }

        return {};
    }
};