#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void merge(vector<int> &ans, vector<pair<int, int>> &numsPair, int start, int mid, int end)
    {
        vector<pair<int, int>> temp(end - start + 1);
        int i = start, j = mid + 1, k = 0;
        while (i <= mid && j <= end)
        {
            if (numsPair[i].first <= numsPair[j].first)
                temp[k++] = numsPair[j++];
            else
            {
                ans[numsPair[i].second] += end - j + 1;
                temp[k++] = numsPair[i++];
            }
        }
        while (i <= mid)
        {
            temp[k++] = numsPair[i++];
        }
        while (j <= end)
        {
            temp[k++] = numsPair[j++];
        }
        for (int i = start; i <= end; i++)
            numsPair[i] = temp[i - start];
    }

    void mergeSort(vector<int> &ans, vector<pair<int, int>> &numsPair, int start, int end)
    {
        if (start < end)
        {
            int mid = start + (end - start) / 2;
            mergeSort(ans, numsPair, start, mid);
            mergeSort(ans, numsPair, mid + 1, end);
            merge(ans, numsPair, start, mid, end);
        }
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> numsPair;
        for (int i = 0; i < n; i++)
            numsPair.push_back({nums[i], i});
        vector<int> ans(n, 0);
        mergeSort(ans, numsPair, 0, n - 1);
        return ans;
    }
};