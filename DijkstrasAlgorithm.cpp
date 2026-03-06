#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int> > &edges, int src) {
        
        // structure of edges - u, v, weight rememberrrr
        // structure of adj(u) is v and weight,
        // structure of adj(v) is u and weight
        
        // adjacency list: for every vertex, store (neighbour, weight)
        vector<vector<pair<int, int> > > adj(V);
        
        // building adjacency list from edge list
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        
        // initialise distance array
        vector<int> distance(V, 1000000000);
        
        vector<int> parent(V);
        // initialise parent array
        for(int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
        
        // min heap -> {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int> >,
            greater<pair<int, int> >
        > pq;
        
        distance[src] = 0;
        
        // push distance
        pq.push(make_pair(0, src));
        
        while(!pq.empty())
        {
            pair<int,int> top = pq.top();
            pq.pop();
            
            int currentDist = top.first;
            int u = top.second;
            
            // ignore outdated entries??
            if(currentDist > distance[u]) 
                continue;
            
            // relaxing neighbours
            for(int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i].first;
                int weight = adj[u][i].second;
                
                if(distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    pq.push(make_pair(distance[v], v));
                }
            }
        }
        
        return distance;
    }
};

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int> > edges(E, vector<int>(3));

    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    Solution sol;
    vector<int> result = sol.dijkstra(V, edges, src);

    cout << "Shortest distances from source:\n";
    for(int i = 0; i < result.size(); i++)
    {
        cout << "Vertex " << i << " -> " << result[i] << endl;
    }

    return 0;
}
