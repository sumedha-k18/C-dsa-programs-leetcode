#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rows, columns;
    int originalcolor;
    void dfs(int r, int c, vector<vector<int> >& image, int newcolor)
    {
        // Boundary check
        if (r < 0 || r >= rows || c < 0 || c >= columns)
            return;
        // Stop if color is different because we're recoloring only the cells which have the original colour
        if (image[r][c] != originalcolor)
            return;
        // recolor current cell
        image[r][c] = newcolor;
        // 4 directions
        dfs(r + 1, c, image, newcolor);
        dfs(r - 1, c, image, newcolor);
        dfs(r, c + 1, image, newcolor);
        dfs(r, c - 1, image, newcolor);
    }

    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int color)
    {
        rows = image.size();
        columns = image[0].size();
        originalcolor = image[sr][sc];

        if (color == originalcolor)
            return image;

        dfs(sr, sc, image, color);
        return image;
    }
};
int main()
{
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    vector<vector<int> > image(rows, vector<int>(cols));
    cout << "Enter the image matrix:";
    for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < cols; j++) {
            cin >> image[i][j];
        }
    }
    int sr, sc, newColor;
    cout << "Enter starting row, starting column, and new color: ";
    cin >> sr >> sc >> newColor;
    Solution sol;
    vector<vector<int> > result = sol.floodFill(image, sr, sc, newColor);
    cout << "\nFlood filled image:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

