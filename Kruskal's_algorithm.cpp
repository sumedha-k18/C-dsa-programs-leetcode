//Kruskal's algorithm for minimum spanning tree
class Solution {
  public:
    int findP(int x, vector<int> &parent)
    {
        if (parent[x]==x)
        {
            return x;
        }
        else
        {
            return parent[x] = findP(parent[x], parent);
        }
    }
    void union_(int u, int v, vector<int>&size, vector<int> &parent)
    {
        int pu = findP(u, parent);
        int pv = findP(v, parent);
        if(pu == pv)return;
        if(size[pu]>size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = pv;
            size[pv] += size[pu];
            
        }
    }
    static bool comp(vector<int> a, vector<int> b)
    {
        return (a[2]<b[2]);
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) 
    {
        sort(edges.begin(), edges.end(), comp);
        int sumWt = 0;
        int edges_used=0;
        vector<int> parent(V);
        vector<int> size(V, 1);
        //initialize the dsu
        for(int i=0; i<V; i++)
        {
            parent[i] = i;
        }
        for(auto it: edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (findP(u,parent)!=findP(v, parent))
            {
                union_(u,v,size, parent);
                edges_used++;
                sumWt += wt;
            }
            if(edges_used==V-1) break;
        }
        return sumWt;
    }
};