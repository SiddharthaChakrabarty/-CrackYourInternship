#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int largestRectangleInHistogram(vector<int> &hist, int m)
    {
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i < m; i++)
        {
            while (!st.empty() && hist[st.top()] >= hist[i])
            {
                int ele = st.top();
                st.pop();
                int nse = i;
                int pse = (st.empty()) ? -1 : st.top();
                int area = (nse - pse - 1) * hist[ele];
                maxArea = max(area, maxArea);
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int ele = st.top();
            st.pop();
            int nse = m;
            int pse = (st.empty()) ? -1 : st.top();
            int area = (nse - pse - 1) * hist[ele];
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        int maxi = INT_MIN;
        vector<int> hist(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    hist[j] += 1;
                else
                    hist[j] = 0;
            }
            int currMax = largestRectangleInHistogram(hist, m);
            maxi = max(currMax, maxi);
        }
        return maxi;
    }
};