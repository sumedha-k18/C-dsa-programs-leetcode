class Solution {
private:
    void dfsHelper(int node, vector<vector<int>> &adj,
                   vector<int> &vis, vector<int> &ls)
    {
        vis[node] = 1;
        ls.push_back(node);

        for (int it : adj[node]) {
            if (!vis[it]) {
                dfsHelper(it, adj, vis, ls);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>>& adj)
    {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ls;

        dfsHelper(0, adj, vis, ls);
        return ls;
    }
};
