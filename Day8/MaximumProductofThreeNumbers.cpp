#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int m1 = nums[0] * nums[1] * nums[n - 1];
        int m2 = nums[n - 2] * nums[n - 3] * nums[n - 1];
        return max(m1, m2);
    }
};