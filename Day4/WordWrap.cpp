#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
private:
    int solve(vector<int> &nums, int k, int n, vector<vector<int>> &dp, int i, int rem)
    {
        if (i == n)
            return 0;
        if (dp[i][rem + 1] != -1)
            return dp[i][rem + 1];
        int ans;
        if (nums[i] > rem)
            ans = (rem + 1) * (rem + 1) + solve(nums, k, n, dp, i + 1, k - nums[i] - 1);
        else
        {
            int opt1 = (rem + 1) * (rem + 1) + solve(nums, k, n, dp, i + 1, k - nums[i] - 1);
            int opt2 = solve(nums, k, n, dp, i + 1, rem - nums[i] - 1);
            ans = min(opt1, opt2);
        }
        dp[i][rem + 1] = ans;
        return ans;
    }

public:
    int solveWordWrap(vector<int> nums, int k)
    {
        // Code here
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 2, -1));
        return solve(nums, k, n, dp, 0, k);
    }
};