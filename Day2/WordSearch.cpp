#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    bool isPossible(vector<vector<char>> &board, string &word, int idx, int i, int j)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx + 1])
            return false;
        return true;
    }

    bool existHelper(vector<vector<char>> &board, string &word, string ans, int idx, int i, int j)
    {
        if (idx == word.size() - 1)
        {
            if (word == ans)
                return true;
            else
                return false;
        }
        board[i][j] = '.';
        bool ans1 = false, ans2 = false, ans3 = false, ans4 = false;
        if (isPossible(board, word, idx, i + 1, j))
        {
            ans.push_back(word[idx + 1]);
            ans1 = existHelper(board, word, ans, idx + 1, i + 1, j);
            if (ans1)
                return true;
            ans.pop_back();
        }
        if (isPossible(board, word, idx, i - 1, j))
        {
            ans.push_back(word[idx + 1]);
            ans2 = existHelper(board, word, ans, idx + 1, i - 1, j);
            if (ans2)
                return true;
            ans.pop_back();
        }
        if (isPossible(board, word, idx, i, j + 1))
        {
            ans.push_back(word[idx + 1]);
            ans3 = existHelper(board, word, ans, idx + 1, i, j + 1);
            if (ans3)
                return true;
            ans.pop_back();
        }
        if (isPossible(board, word, idx, i, j - 1))
        {
            ans.push_back(word[idx + 1]);
            ans4 = existHelper(board, word, ans, idx + 1, i, j - 1);
            if (ans4)
                return true;
            ans.pop_back();
        }
        board[i][j] = word[idx];
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int idx = 0;
        int r = board.size();
        int c = board[0].size();
        string ans = "";
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == word[0])
                {

                    ans += word[0];
                    bool ret = existHelper(board, word, ans, idx, i, j);
                    if (ret)
                        return true;
                    ans = "";
                }
            }
        }
        return false;
    }
};