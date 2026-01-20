//Shortest Path in undirected unit weight graph
class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj(V);
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        int dist[V];
        //initialise to inf
        for(int i=0; i<V; i++)
        {
            dist[i] = 1e9;
        }
        dist[src] = 0;
        q.push(src);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it: adj[node])
            {
                /*do a lil run through in your head, d[0] = 3, 
                then the branch nodes will be 3+1 na*/
                if(dist[node]+1< dist[it])
                {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
            
        }
        vector<int> ans(V, -1);
        for(int i=0; i<V; i++)
        {
            if(dist[i]<1e9) ans[i] = dist[i];
        }
        return ans;
    }
};
