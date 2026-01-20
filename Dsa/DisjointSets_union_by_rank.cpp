union by rank
class DisjointSet
{
    vector<int> rank;
    vector<int> parent;
 public: 
    DisjointSet(int n)//no. of nodes
    {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i<=n; i++)
        {
            parent[i] = i;
        }
    }
    int findUltP(int node)
    {
        if(node == parent[node])
        return node;
        else
        {
            return parent[node] = findUltP(parent[node]);
        }
        
    }
    void unionSet(int x, int z) 
    {
        int ultix = findUltP(x);
        int ultiz = findUltP(z);
        if(ultix == ultiz) return;//they belong to same component
        else if(rank[ultix]>rank[ultiz])
        {
            parent[ultiz] = ultix;
        }
        else if(rank[ultiz]>rank[ultix])
        {
            parent[ultix] = ultiz;
        }
        else if(rank[ultix]==rank[ultiz])
        {
            parent[ultix] = ultiz;
            rank[ultiz]++;//doesnt matter you could do it either way
        }
    }
};