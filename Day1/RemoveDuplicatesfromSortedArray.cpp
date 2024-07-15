#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0, mid = 0, end = 0;
        while (end < n)
        {
            if (nums[start] == nums[end])
            {
                end++;
            }
            else
            {
                start++;
                swap(nums[start], nums[end]);
                end++;
            }
        }
        return start + 1;
    }
};