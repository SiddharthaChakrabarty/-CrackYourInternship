#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int leftSum = 0, rightSum = 0, maxSum = 0;
        int n = cardPoints.size();
        int rightIndex = n - 1;
        for (int i = 0; i < k; i++)
            leftSum += cardPoints[i];
        maxSum = leftSum;
        for (int i = k - 1; i >= 0; i--)
        {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIndex--];
            maxSum = max(maxSum, leftSum + rightSum);
        }
        return maxSum;
    }
};