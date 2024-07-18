#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int countLive(vector<vector<int>> &board, int x, int y, int m, int n)
    {
        int cnt = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && (board[nx][ny] == 1 || board[nx][ny] == 2))
                    cnt++;
            }
        }
        return cnt;
    }

public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int cnt = countLive(board, i, j, m, n);
                if (board[i][j] == 1 && (cnt < 2 || cnt > 3))
                    board[i][j] = 2;
                if (board[i][j] == 0 && cnt == 3)
                    board[i][j] = 3;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                if (board[i][j] == 3)
                    board[i][j] = 1;
            }
        }
    }
};