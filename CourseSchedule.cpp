#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int> >& adj,
             vector<int>& visited, vector<int>& dfsVisited)
    {
        visited[node] = 1;
        dfsVisited[node] = 1;

        for (int i = 0; i < adj[node].size(); i++)
        {
            int adjnode = adj[node][i];

            if (!visited[adjnode])
            {
                if (dfs(adjnode, adj, visited, dfsVisited))
                    return true;   // cycle found
            }
            else if (dfsVisited[adjnode])
            {
                return true;       // back edge ? cycle
            }
        }

        dfsVisited[node] = 0; // remove from recursion stack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int> >& prerequisites)
    {
        vector<vector<int> > adj(numCourses);

        // build graph: b -> a
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
        }

        vector<int> visited(numCourses, 0);
        vector<int> dfsVisited(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, dfsVisited))
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    int numCourses, m;
    cout << "Enter number of courses: ";
    cin >> numCourses;

    cout << "Enter number of prerequisite pairs: ";
    cin >> m;

    vector<vector<int> > prerequisites(m, vector<int>(2));

    cout << "Enter prerequisite pairs (a b) meaning b -> a:\n";
    for (int i = 0; i < m; i++)
    {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    Solution sol;
    if (sol.canFinish(numCourses, prerequisites))
        cout << "All courses can be finished (No cycle)\n";
    else
        cout << "Courses cannot be finished (Cycle exists)\n";

    return 0;
}
