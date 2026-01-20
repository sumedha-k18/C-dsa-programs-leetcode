//https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class Solution {
public:
    vector<int> parent, rank;
    int findP(int node, vector<int> &parent)
    {
        if(node==parent[node])
        return node;
        else
        {
            return parent[node] = findP(parent[node], parent);
        }
    }
    void unite(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        int pu = findP(u, parent);
        int pv = findP(v, parent);
        if(pu==pv) return;//already connected
        if(rank[pv]>rank[pu])
        {
            parent[pu] = pv;
        }
        else if(rank[pv]<rank[pu])
        {
            parent[pv] = pu;
        }
        else if(rank[pv]==rank[pu])
        {
            parent[pv] = pu;
            rank[pu]++;
        }

    }
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        if(connections.size()<n-1)
        return -1;
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }
        for(auto& it : connections)
        {
            unite(it[0], it[1], parent, rank);
        }
        int components = 0;
        for(int i=0; i<n; i++)
        {
            if(parent[i]==i)
            {
                components++;
            }
        }
        return components-1;
    }
};