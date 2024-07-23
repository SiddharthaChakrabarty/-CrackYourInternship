#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPossible(vector<int> &nums, int k, int mid)
    {
        int n = nums.size();
        int sum = 0;
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum > mid)
            {
                cnt++;
                sum = 0;
                i--;
            }
            if (cnt > k)
                return false;
        }
        return true;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        int mini = INT_MAX, sum = 0, ans;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            mini = min(mini, nums[i]);
        }
        int start = mini, end = sum;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (isPossible(nums, k, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};