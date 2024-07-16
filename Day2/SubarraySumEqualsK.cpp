#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), preSum = 0, cnt = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            preSum += nums[i];
            if (mp.find(preSum - k) != mp.end())
            {
                cnt += mp[preSum - k];
                mp[preSum]++;
            }
            else
                mp[preSum]++;
        }
        return cnt;
    }
};