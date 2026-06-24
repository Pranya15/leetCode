class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        // Build graph
        for(auto edge : prerequisites)
        {
            int a = edge[0];
            int b = edge[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;

        // Push all indegree 0 nodes
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        int count=0;

        while(!q.empty())
        {
            int curr=q.front();
            q.pop();

            count++;

            for(int neigh : adj[curr])
            {
                indegree[neigh]--;

                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }
            }
        }

        return count==numCourses;
    }
};