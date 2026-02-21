#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& mat)
    {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int> > distance(r, vector<int>(c));
        queue<pair<int,int> > q;

        // Initialization
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(mat[i][j] == 1)
                    distance[i][j] = 1e9;
                else
                {
                    distance[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // BFS
        while(!q.empty())
        {
            int r1 = q.front().first;
            int c1 = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int r2 = r1 + dr[i];
                int c2 = c1 + dc[i];

                if(r2 >= 0 && r2 < r && c2 >= 0 && c2 < c)
                {
                    if(distance[r2][c2] > distance[r1][c1] + 1)
                    {
                        distance[r2][c2] = distance[r1][c1] + 1;
                        q.push({r2, c2});
                    }
                }
            }
        }

        return distance;
    }
};

int main()
{
    int r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    vector<vector<int> > mat(r, vector<int>(c));
    cout << "Enter matrix elements (0/1):\n";
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> mat[i][j];

    Solution sol;
    vector<vector<int> > ans = sol.updateMatrix(mat);

    cout << "Distance Matrix:\n";
for(int i = 0; i < ans.size(); i++)
{
    for(int j = 0; j < ans[i].size(); j++)
    {
        cout << ans[i][j] << " ";
    }
    cout << "\n";
}

    return 0;
}

