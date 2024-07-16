#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size(), preSum = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            preSum = (preSum + nums[i] % k + k) % k;
            ans += mp[preSum];
            mp[preSum]++;
        }
        return ans;
    }
};