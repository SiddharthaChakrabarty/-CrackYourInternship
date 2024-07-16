#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxAr = 0;
        int start = 0, end = height.size() - 1;
        while (start < end)
        {
            int area = (end - start) * min(height[start], height[end]);
            maxAr = max(area, maxAr);
            if (height[start] < height[end])
                start++;
            else
                end--;
        }
        return maxAr;
    }
};