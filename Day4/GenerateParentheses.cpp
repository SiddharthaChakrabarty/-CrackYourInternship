#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void helper(vector<string> &ans, int n, int lCount, int rCount, string str)
    {
        if (rCount == n)
        {
            ans.push_back(str);
            return;
        }
        if (lCount < n)
            helper(ans, n, lCount + 1, rCount, str + "(");
        if (rCount < lCount)
            helper(ans, n, lCount, rCount + 1, str + ")");
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        int lCount = 0, rCount = 0;
        helper(ans, n, lCount, rCount, "");
        return ans;
    }
};