#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans(2);
        for (int i = 0; i < n; i++)
        {
            if (mp.find(target - nums[i]) != mp.end())
            {
                ans = {mp[target - nums[i]], i};
                return ans;
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};