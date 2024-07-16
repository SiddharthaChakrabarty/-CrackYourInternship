#include <vector>
using namespace std;

class Solution
{
private:
    void traverse(vector<vector<int>> &matrix, vector<int> &ans,
                  int left, int right, int top, int bottom)
    {
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            if (left > right || top > bottom)
                break;
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (left > right || top > bottom)
                break;
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            if (left > right || top > bottom)
                break;
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        traverse(matrix, ans, 0, n - 1, 0, m - 1);
        return ans;
    }
};