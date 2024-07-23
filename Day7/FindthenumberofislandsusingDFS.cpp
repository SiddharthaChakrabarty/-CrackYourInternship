#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited,
             int x, int y, int n, int m)
    {
        visited[x][y] = true;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '1' && visited[nx][ny] == false)
                dfs(grid, visited, nx, ny, n, m);
        }
        // for(int i=-1;i<=1;i++) {
        //     if(i==0)
        //         continue;
        //     int nx = x+i;
        //     int ny = y+i;
        //     if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][y]=='1' && visited[nx][y]==false)
        //         dfs(grid,visited,nx,y,n,m);
        //     if(nx>=0 && ny>=0 && nx<n && ny<m && grid[x][ny]=='1' && visited[x][ny]==false)
        //         dfs(grid,visited,x,ny,n,m);
        // }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                visited[i][j] = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] == false)
                {

                    dfs(grid, visited, i, j, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};