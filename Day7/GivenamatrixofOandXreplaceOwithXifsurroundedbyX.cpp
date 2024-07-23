//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    void dfs(int n, int m, vector<vector<char>> &mat,
             vector<vector<int>> &vis, int x, int y)
    {
        vis[x][y] = 1;
        vector<vector<int>> vec = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + vec[i][0];
            int ny = y + vec[i][1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 'O' && !vis[nx][ny])
                dfs(n, m, mat, vis, nx, ny);
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
        {
            if (mat[0][i] == 'O' && !vis[0][i])
                dfs(n, m, mat, vis, 0, i);
            if (mat[n - 1][i] == 'O' && !vis[n - 1][i])
                dfs(n, m, mat, vis, n - 1, i);
        }
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 'O' && !vis[i][0])
                dfs(n, m, mat, vis, i, 0);
            if (mat[i][m - 1] == 'O' && !vis[i][m - 1])
                dfs(n, m, mat, vis, i, m - 1);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' && !vis[i][j])
                    mat[i][j] = 'X';
            }
        }

        return mat;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends