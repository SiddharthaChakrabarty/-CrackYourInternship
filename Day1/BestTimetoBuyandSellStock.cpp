#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int profit = 0;
        int maxProfit = 0;
        for (int i = 0; i < n - 1; i++)
        {
            profit += prices[i + 1] - prices[i];
            maxProfit = max(maxProfit, profit);
            if (profit < 0)
                profit = 0;
        }
        return maxProfit;
    }
};