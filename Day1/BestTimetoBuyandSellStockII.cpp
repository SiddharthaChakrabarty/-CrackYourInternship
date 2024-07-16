#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int profit = 0, maxProfit = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int diff = prices[i + 1] - prices[i];
            if (diff < 0)
                continue;
            profit += diff;
            maxProfit = max(profit, maxProfit);
        }
        return maxProfit;
    }
};